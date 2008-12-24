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
** Descriptions:		�ź���ʹ��
**
********************************************************************************************************/
#include "config.h"
#include "stdlib.h"

#define	TaskStkLengh	128			// �����û�����0�Ķ�ջ����
 
OS_STK	MainStk [TaskStkLengh];		// �����û�����0�Ķ�ջ
OS_STK	ComTaskStk [TaskStkLengh];		// �����û�����0�Ķ�ջ
OS_STK	InputTaskStk[TaskStkLengh];	// ����Task1�Ķ�ջ
uint8	msgBuf[128];


/*
void 	Task0(void *pdata);			// Task0 ����0
void 	Task1(void *pdata);			// Task1 ����1
*/

/*
**********************************************************************************************************
** �������� ��main()
** �������� ��uC/OS-II�����������������񻷾���
**********************************************************************************************************
*/
void PcLineTask(void  *pdata);
void InputPinTask(void  *pdata);
void mainTask(void *pdata);

OS_EVENT *QEmptySem, *QFullSem;
int main (void)
{
	OSInit ();
	

	NMsgQCreate(msgBuf, sizeof(msgBuf));																								;
	OSTaskCreate (mainTask,(void *)0, &MainStk[TaskStkLengh - 1], 2);		
	OSStart ();
	return 0;															
}

/*********************************************************************************************************
**                            Task0 ����0
**                     Ŀ����ʼ��������Task1���򴮿�0�����ַ�����I AM TASK A.��
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

void mainTask(void *pdata)
{
	uint8 err,t,ntype,nid;
	uint8 mbuf[8];
	struct tag_nodemsg *msg;
	struct tag_attrib *attr;
	DATETIME *dt;
	int i;
	pdata = pdata;
	dt = (DATETIME *)mbuf;
	msg = (struct tag_nodemsg *)mbuf;
	attr = (struct tag_attrib *)mbuf;
	TargetInit();
	for( i = 0; i < FULL_DOORS; i++ )
	{
		timecount[i].door_count = 0;
		timecount[i].megnet_count = 0xff;
			
	}
	OSTaskCreate (InputPinTask,(void *)0, &InputTaskStk[TaskStkLengh - 1], 3);	
//	OSTaskCreate (PcLineTask,(void *)0, &ComTaskStk[TaskStkLengh - 1], 4);	
	while(1)
	{
		msg->size = 6;
		NMsgQRead( msg, msgBuf);
		ntype = msg->node & 0x7;
		nid = (msg->node >> 3);
		switch( ntype )
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
									
				}
				break;
			case MEGNET_NODE:
				t = (msg->msg & 0x1);
				at45db_Page_Read(GROUP_PAGE + nid, ATTRIB_BA, mbuf, 8);			
				OS_ENTER_CRITICAL();
				if( t & attr->megnet )
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
				t = (msg->msg & 0x1);
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
				if( t & attr->button )
				{
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
	attr = (struct tag_attrib *)mbuf;
	dt = (DATETIME *)mbuf;
	pdata = pdata;
	while(1)
	{	
		OS_ENTER_CRITICAL();	
		for( i = 0; i < FULL_DOORS; i++ )
		{
			if(timecount[i].door_count)
			{
				timecount[i].door_count--;
			}
			else
			{
				//close door
				
				IOSET = PIN_DOOR1;
				
				if( timecount[i].megnet_count != 0xff &&  
					timecount[i].megnet_count != 0x0)
				{
					timecount[i].megnet_count--;
				}else if( timecount[i].megnet_count == 0x00 )
				{
;
					at45db_Page_Read(GROUP_PAGE + i, ATTRIB_BA, mbuf, 8);
					timecount[i].megnet_count = attr->megnet_delay;	
					//read rtc
					ReadRTC(dt);									
					//write log
					LogWrite( (i<<3) + MEGNET_NODE, ALARM_TYPE, 0, dt->value);

				}						
			}
		}
		OS_EXIT_CRITICAL();	
		OSTimeDly(200);
	}
	
}




/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
