/****************************************Copyright (c)**************************************************
**                               Guangzou ZLG-MCU Development Co.,LTD.
**                                      graduate school
**                                 http://www.zlgmcu.com
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			main.c
** Last modified Date:  2004-09-16
** Last Version:		1.0
** Descriptions:		The main() function example template
**
**------------------------------------------------------------------------------------------------------
** Created by:			Chenmingji
** Created date:		2004-09-16
** Version:				1.0
** Descriptions:		The original version
**
**------------------------------------------------------------------------------------------------------
** Modified by:			Chenxibing
** Modified date:		2005-03-11
** Version:
** Descriptions:		信号量使用
**
********************************************************************************************************/
#include "config.h"
#include "stdlib.h"

#define	TaskStkLengh	64			// 定义用户任务0的堆栈长度
 
OS_STK	TaskStk [TaskStkLengh];		// 定义用户任务0的堆栈
OS_STK	ComTaskStk [TaskStkLengh];		// 定义用户任务0的堆栈
OS_STK	InputTaskStk[TaskStkLengh];	// 定义Task1的堆栈
uint8	msgBuf[128];


/*
void 	Task0(void *pdata);			// Task0 任务0
void 	Task1(void *pdata);			// Task1 任务1
*/

/*
**********************************************************************************************************
** 函数名称 ：main()
** 函数功能 ：uC/OS-II主函数，启动多任务环境。
**********************************************************************************************************
*/
void PcLineTask(void  *pdata);
void InputPinTask(void  *pdata);


OS_EVENT *QEmptySem, *QFullSem;
int main (void)
{
	OSInit ();
	

	NMsgQCreate(msgBuf, sizeof(msgBuf));																								;
	OSTaskCreate (PcLineTask,(void *)0, &TaskStk[TaskStkLengh - 1], 5);		
	OSStart ();
	return 0;															
}

/*********************************************************************************************************
**                            Task0 任务0
**                     目标板初始化，创建Task1，向串口0发送字符串“I AM TASK A.”
********************************************************************************************************/

enum e_node
{
	door1 =	0,
	megnet1,
	exit1,
	ctrl1,
	reader1,
	alarm1,
	state1,
	other1,

	door2,
	megnet2,
	exit2,
	ctrl2,
	reader2,
	alarm2,
	state2,
	other2,

	reader_power	=	128,
	net_module,
	rtc,
	flash,
	
	machine	=	254,

	test	
};

#define DOOR_NODE			0
#define MEGNET_NODE			1
#define EXIT_NODE			2
#define	CTRL_NODE			3
#define READERDATA_NODE		4
#define ALARM_NODE			5
#define OTHER_NODE			6

#define READERDOOR1				0x00
#define READERDOOR2				0x08
#define READERDOOR3				0x10
#define READERDOOR4				0x18
#define READERDOOR5				0x20
#define READERDOOR6				0x28
#define READERDOOR7				0x30
#define READERDOOR8				0x38
#define READERDOOR9				0x40
#define READERDOOR10			0x48
#define READERDOOR11			0x50
#define READERDOOR12			0x58 
#define READERDOOR13			0x60 
#define READERDOOR14			0x68 
#define READERDOOR15			0x70 
#define READERDOOR16			0x78

  

struct tag_timecount
{
	uint8 megnet_count:7;
	uint8 megnet_state:1;
	uint8 door_count;		// =0 door close, >0 door open
	uint8 reader_count;
	uint8 reader_card;
}timecount[2];



void mainTask(void *pdata)
{
	uint8 err,t;
	uint8 mbuf[8];
	struct tag_nodemsg *msg;
	struct tag_attrib *attr;
	pdata = pdata;
	msg = (struct tag_nodemsg *)mbuf;
	attr = (struct tag_attrib *)mbuf;
	TargetInit();
	OSTaskCreate (InputPinTask,(void *)0, &InputTaskStk[TaskStkLengh - 1], 6);	
	OSTaskCreate (PcLineTask,(void *)0, &ComTaskStk[TaskStkLengh - 1], 4);	
	while(1)
	{
		msg->size = 6;
		NMsgQRead( msg, msgBuf);
		switch(msg->node)
		{
			case READERDATA_NODE:
				{
					uint16 empty_p,exist_p;
					struct tag_userinfo *info = (struct tag_userinfo *)mbuf;
					at45db_Comp_uint32( USER_ID_PAGE, 0, *((uint32 *)msg->data) , (USER_ID_NUMBER * USER_ID_SIZE), &empty_p, &exist_p );
					if( exist_p == (USER_ID_NUMBER * USER_ID_SIZE) )
					{
						// no enroll id;
					}
					exist_p *= 2;
					empty_p =  exist_p / 528;
					at45db_Page_Read( empty_p + USER_INFO_PAGE, exist_p % 528, mbuf , 8);
					//info->group[0]
					
					
									
				}
				break;
			case MEGNET_NODE:
				t = (msg->msg & 0x1);
				at45db_Page_Read(GROUP_PAGE, ATTRIB_BA, mbuf, 8);			
				OS_ENTER_CRITICAL();
				if( t & attr->megnet )
				{
					//set megnet alarm					
					timecount[0].megnet_count = attr->megnet_delay;
					
				}
				else
				{					
					timecount[0].megnet_count = 0;					
				}
				OS_EXIT_CRITICAL();			
				break;
			case EXIT_NODE:			
				t = (msg->msg & 0x1);
				at45db_Page_Read(GROUP_PAGE, ATTRIB_BA, mbuf, 8);
				OS_ENTER_CRITICAL();
				if( attr->link < 16  )
				{
					if( timecount[attr->link].megnet_count != 0 )
					{
						OS_EXIT_CRITICAL();
						break;
					}				
				}			
				if( t & attr->button )
				{
					timecount[0].door_count = attr->door_delay;
				}
				
				OS_EXIT_CRITICAL();			
				break;			
			default:
				break;
		
		}
	}			
}

void TimeTask(void *pdata)
{
	int i;
	pdata = pdata;
	while(1)
	{
		
		for( i = 0; i < 2; i++ )
		{
			if(timecount[i].door_count)
			{
				timecount[i].door_count--;
			}
			else
			{
				//close door
				OS_ENTER_CRITICAL();
				
				
				OS_EXIT_CRITICAL();			
			}
			if( timecount[i].door_count == 0 && timecount[0].megnet_count)
			{
				timecount[i].megnet_count--;	
			}
		}
		OSTimeDly(200);
	}
	
}

struct tag_inpin
{
	uint16	megnet_state	: 	3;
	uint16	megnet			:	1;
	uint16	exit_state 		:	3;
	uint16	exit			:	1;
	uint16  alarm_state		:	3;
	uint16  alarm			:	1;	
	uint16	other_state		:	3;
	uint16	other			:	1;	
}pin[2];

#define PIN_MEGNET1_BIT		4
#define PIN_EXIT1_BIT		5
#define PIN_MEGNET2_BIT		6
#define PIN_EXIT2_BIT		7

#define PIN_MEGNET1	( 1 << PIN_MEGNET1_BIT )
#define PIN_EXIT1	( 1 << PIN_EXIT1_BIT )
#define PIN_MEGNET2 ( 1 << PIN_MEGNET2_BIT )
#define PIN_EXIT2	( 1 << PIN_EXIT2_BIT )

#define PIN_IN_MASK (PIN_MEGNET1 |  PIN_EXIT1 | PIN_MEGNET2 | PIN_EXIT2 )

void InputPinTask( void *pdata)
{
	uint32 pin_state,pin_prev_state, t;
	uint8 mbuf[2];
	struct tag_nodemsg *msg;
	msg = (struct tag_nodemsg *)mbuf;	
	msg->size = 2;
	pdata = pdata;
	pin_prev_state = pin_state = IOPIN;	
	while(1)
	{	
		OSTimeDly(2);
		
		pin_state = IOPIN;
		t = (pin_state ^ pin_prev_state);
		if( t & PIN_IN_MASK )
		{
			if( PIN_MEGNET1 & t )
			{
				pin[0].megnet_state = 0;
				pin[0].megnet = (pin_state >> PIN_MEGNET1_BIT);
			}
			if( PIN_MEGNET2 & t )
			{
				pin[1].megnet_state = 0;
				pin[1].megnet = (pin_state >> PIN_MEGNET2_BIT);
			}
			if( PIN_EXIT1 & t )
			{
				pin[0].exit_state = 0;
				pin[0].exit = (pin_state >> PIN_EXIT1_BIT);
			}
			if( PIN_EXIT2 & t )
			{
				pin[1].exit_state = 0;
				pin[1].exit = (pin_state >> PIN_EXIT2_BIT);
			}
		}	
		
		
		if( pin[0].megnet_state < 2 )
		{
			pin[0].megnet_state++;
		}else if( pin[0].megnet_state == 2)
		{
			
			msg->node = megnet1;
			msg->msg = pin[0].megnet;
			if( NMsgQWrite(msgBuf, msg) == QUEUE_OK )
				pin[0].megnet_state = 3;
		}
		
		if( pin[1].megnet_state < 2 )
			pin[1].megnet_state++;
		else if( pin[1].megnet_state == 2)
		{			
			msg->node = megnet2;
			msg->msg = pin[1].megnet;
			if( NMsgQWrite(msgBuf, msg) == QUEUE_OK )
				pin[1].megnet_state = 3;
		}			
			
		if( pin[0].exit_state < 2 )
			pin[0].exit_state++;
		else if( pin[0].exit_state == 2)
		{			
			msg->node = exit1;
			msg->msg = pin[0].exit;
			if( NMsgQWrite(msgBuf, msg) == QUEUE_OK )
				pin[0].exit_state = 3;
		}
					
		if( pin[1].exit_state < 2 )
			pin[1].exit_state++;
		else if( pin[1].exit_state == 2)
		{
			pin[1].exit_state = 3;
			msg->node = exit2;
			msg->msg = pin[1].exit;
			if( NMsgQWrite(msgBuf, msg) == QUEUE_OK )
				pin[1].exit_state = 3;

		}	
		
	}

}
/*********************************************************************************************************
**                            Task1 任务1
**                        向串口0发送字符串“i am task b.”
********************************************************************************************************/
/*
void Task1	(void *pdata)
{
	uint8 err;
	uint8 str1[]="i am task b.";
	
	pdata = pdata;
	
	while (1)
	{
		
		OSSemPend(DispSem, 0, & err);	//  等待信号量
		UART0_SendStr(str1);
		err = OSSemPost(DispSem);		// 发送信号量

	}
}
   
 */ 
/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
