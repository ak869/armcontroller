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
 
OS_STK	MainStk [TaskStkLengh];		// 定义用户任务0的堆栈
OS_STK	ComTaskStk [TaskStkLengh];		// 定义用户任务0的堆栈
OS_STK	InputTaskStk[TaskStkLengh];	// 定义Task1的堆栈
OS_STK	TimeTaskStk[TaskStkLengh];



/*
**********************************************************************************************************
** 函数名称 ：main()
** 函数功能 ：uC/OS-II主函数，启动多任务环境。
**********************************************************************************************************
*/
void PcLineTask(void  *pdata);
void InputPinTask(void  *pdata);
void mainTask(void *pdata);
void TimeTask(void *pdata);
void HostLineTask(void *pdata);

OS_EVENT *QNoEmptySem, *QFullSem;
int main (void)
{
	OSInit ();
	

	QNoEmptySem = OSSemCreate(0);																								;
	OSTaskCreate (mainTask,(void *)0, &MainStk[TaskStkLengh - 1], 2);		
	OSStart ();
	return 0;															
}

/*********************************************************************************************************
**                            Task0 任务0
**                     目标板初始化，创建Task1，向串口0发送字符串“I AM TASK A.”
********************************************************************************************************/



struct tag_timecount
{
	uint8 megnet_count;		//time	MEGNET_NODE state
	uint8 door_count;		//time =0 door close, >0 door open 	DOOR_NODE state
	uint8 reader_count;		//time								
	uint8 reader_card;
	uint8 other_count;		
	uint8 ctrl_count;		//
	uint8 reserved;			
	uint8 exit_state 	: 1;
	uint8 alarm_state	: 1;
	uint8 reader_state	: 1;
}timecount[FULL_DOORS];
void PinInit(void)
{	
	IO1CLR = PIN_DOOR1;
	IO1DIR |= PIN_DOOR1;
		
}
void mainTask(void *pdata)
{
	uint8 err,t,ntype,nid;
	uint8 mbuf[8];
	PNODEMSG msg;
	struct tag_attrib *attr;
	DATETIME *dt;
	int i;
	pdata = pdata;
	dt = (DATETIME *)mbuf;
	msg = (PNODEMSG)mbuf;
	attr = (struct tag_attrib *)mbuf;

	TargetInit();
	for( i = 0; i < FULL_DOORS; i++ )
	{
		timecount[i].door_count = 0xff;
		timecount[i].megnet_count = 0xff;
			
	}
	OSTaskCreate (InputPinTask,(void *)0, &InputTaskStk[TaskStkLengh - 1], 3);	
	OSTaskCreate ( TimeTask,(void *)0, &TimeTaskStk[TaskStkLengh - 1], 4);
	OSTaskCreate ( HostLineTask,(void *)0, &ComTaskStk[TaskStkLengh - 1], 5);	
	while(1)
	{
		OSSemPend(QNoEmptySem, 0, &err);
		msg->bits.size = 8;
		NMsgQRead( msg, 0,0);
		ntype = msg->bits.node & MSG_CHILDREN_NODE_MASK;
		nid = (msg->bits.node >> MSG_PARENT_NODE_BIT);
		switch( ntype )
		{
			case READERDATA_NODE:
				{
					uint16 empty_p,exist_p;
					struct tag_userinfo *info = (struct tag_userinfo *)mbuf;
					at45db_Comp_uint32( USER_ID_PAGE, 0, *((uint32 *)msg->bits.data) , (USER_ID_NUMBER * USER_ID_SIZE), &empty_p, &exist_p );
					if( exist_p == (USER_ID_NUMBER * USER_ID_SIZE) )
					{
						// no enroll id;
					}
					exist_p *= 2;
					empty_p =  exist_p / 528;
					at45db_Page_Read( empty_p + USER_INFO_PAGE, exist_p % 528, mbuf , 8);					
									
				}
				break;
			case MEGNET_NODE:
				t = (msg->bits.msg & 0x1);
				at45db_Page_Read(GROUP_PAGE + nid, ATTRIB_BA, mbuf, 8);			
				OS_ENTER_CRITICAL();
				if( t ^ attr->megnet )
				{
					//set megnet alarm					
					timecount[nid].megnet_count = attr->megnet_delay;
					
				}
				else
				{	
					//close megnet alarm				
					timecount[nid].megnet_count = 0xff;					
				}
				OS_EXIT_CRITICAL();			
				break;
			case EXIT_NODE:			
				t = (msg->bits.msg & 0x1);
				at45db_Page_Read(GROUP_PAGE + nid, ATTRIB_BA, mbuf, 8);
				OS_ENTER_CRITICAL();
				if( attr->link < 16  )
				{
					if( timecount[attr->link].megnet_count != 0xff )
					{
						OS_EXIT_CRITICAL();
						break;
					}				
				}			
				if( t ^ attr->button )
				{
					switch( nid )
					{
						case 0:
							IO1SET = PIN_DOOR1;
							break;
						case 1:
							break;
						default:
							if( nid < 16 )
							{
								msg->bits.node = (nid << MSG_PARENT_NODE_BIT) + DOOR_NODE;
								msg->bits.size = 4;
								msg->bits.msg = 1;
								msg->bits.task = 5;
								while( NMsgQWrite( msg ) != QUEUE_OK )
								{
									OSTimeDly(2);
								}
							}
							break;
			
					}					
					timecount[nid].door_count = attr->door_delay;
					ReadRTC(dt);
					LogWrite( (nid<<3) + DOOR_NODE, 0, 0, dt->value);
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
	uint8 mbuf[8];
	struct tag_attrib *attr;
	DATETIME *dt;
	PNODEMSG msg;
	struct tag_timecount * t;
	attr = (struct tag_attrib *)mbuf;
	dt = (DATETIME *)mbuf;
	msg = ( PNODEMSG )mbuf;
	
	pdata = pdata;
	while(1)
	{	
		OS_ENTER_CRITICAL();	
		for( i = 0; i < FULL_DOORS; i++ )
		{
			t = timecount + i;
			if( t->door_count != 0xff &&
				t->door_count != 0x0 )
			{
				t->door_count--;
			}
			else if( t->door_count == 0x0)
			{
				//close door
				t->door_count = 0xff;
				switch(i)
				{
					case 0:
						IO1CLR = PIN_DOOR1;
						break;
					case 1:
						break;
					default:
						msg->bits.node = (i << MSG_PARENT_NODE_BIT) + DOOR_NODE;
						msg->bits.size = 4;
						msg->bits.msg = 0;
						msg->bits.task = 5;
						while( NMsgQWrite( msg ) != QUEUE_OK )
						{
							OSTimeDly(2);
						}
						break;	
				}						
			}
			if( t->megnet_count != 0xff &&  
				t->megnet_count != 0x0 && 
				t->door_count == 0xff )
			{
				t->megnet_count--;
			}else if( t->megnet_count == 0x00 )
			{
				at45db_Page_Read(GROUP_PAGE + i, ATTRIB_BA, mbuf, 8);
				t->megnet_count = attr->megnet_delay;	
				//read rtc
				ReadRTC(dt);									
				//write log
				LogWrite( (i<<3) + MEGNET_NODE, ALARM_TYPE, 0, dt->value);
			}			
		}
		OS_EXIT_CRITICAL();	
		OSTimeDly(200);
	}
	
}




/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
