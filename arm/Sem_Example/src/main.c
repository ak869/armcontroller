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
#define MainStkLengh	128
OS_STK	MainStk [MainStkLengh];		// 定义用户任务0的堆栈
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
	OSTaskCreate (mainTask,(void *)0, &MainStk[MainStkLengh - 1], 2);		
	OSStart ();
	return 0;															
}

/*********************************************************************************************************
**                            Task0 任务0
**                     目标板初始化，创建Task1，向串口0发送字符串“I AM TASK A.”
********************************************************************************************************/



struct tag_timecount
{
	uint8 megnet_time;		//time	MEGNET_NODE state
	uint8 door_time;		//time =0 door close, >0 door open 	DOOR_NODE state
	uint8 door_cards_time;		//time								
	uint8 door_cards;
	uint8 door_power;					
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
	uint8 err,ntype,nid;
	uint8 mbuf[36 + 5];
	PNODEMSG msg;
	DATETIME *dt;	
	int i;
	pdata = pdata;
	dt = ( DATETIME * )(mbuf + 36);
	msg = ( PNODEMSG )mbuf;

	TargetInit();
	for( i = 0; i < FULL_DOORS; i++ )
	{
		timecount[i].door_time = 0xff;
		timecount[i].megnet_time = 0xff;
			
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
			case READER_NODE:
				{
					int j;
					struct tag_doorgroup * gp;
					struct tag_attrib *attr;
					uint8 state,power, buf[16];
					uint32 *t,id;
					uint16 ugp,ugb,d;
					uint16 empty_p,exist_p;
					gp = (struct tag_doorgroup *)mbuf;
					attr = (struct tag_attrib *)mbuf;
					ReadRTC(dt);
					id = *((uint32 *)msg->bits.data);
					at45db_Comp_uint32( USER_ID_PAGE, 0, id , (USER_ID_NUMBER * USER_ID_SIZE), &empty_p, &exist_p );
					if( exist_p == (USER_ID_NUMBER * USER_ID_SIZE) )
					{
						// no enroll id
						state = NOENROLLID_TYPE;						
						break;
					}
					exist_p *= 2;
					ugp =  exist_p / 528;
					ugb = exist_p % 528;
					
					at45db_Page_Read( USER_GROUP_PAGE + ugp, ugb, mbuf, 8);
					at45db_Page_Read( DOOR_READER_PAGE, nid << 1, (uint8*)&d, 2);
					
					for( i = 0; i < FULL_DOORS; i++ )
					{
						buf[i] = 0;
					}
					for( i = 0; i < FULL_DOORS; i++ )
					{
						if( d & 0x1  )
						{
							if( i & 0x1 )
								buf[i] |= (mbuf[(i >> 1)] >> 4);
							else
								buf[i] |= mbuf[(i >> 1)] & 0xf;							
						}
						d >>= 1;
					}
					for( i = 0; i < FULL_DOORS; i++ )
					{
						if( buf[i] < 14 )
						{
							at45db_Page_Read( i + GROUP_PAGE, buf[i] * GROUP_SIZE, mbuf, GROUP_SIZE);
							ReadRTC(dt);
							gp = (struct tag_doorgroup *)mbuf;
							d = (dt->value & 0x7FF);
							t = (uint32 *)(gp->t);
							
							for( j = 0; j < GROUP_TIMELIST_NUM; j++ )
							{
								if( d >= (uint16)(t[j] & 0x7FF) &&
									d <= (uint16)((t[j] >> 11) & 0x7FF) )
								{
									if(  t[j] & 0x20000000 )
									{//read other table
										
									}else
									{
										if( ((1 << dt->timelong.weeks) & (t[j] >> 22)) != 0 )
										{
											timecount[i].door_power += gp->power;
											if( timecount[i].door_power > 100 )
												timecount[i].door_power = 100;											
											if( gp->power != 100 )
												state = POWERNOFULL_TYPE;
											else
												state = POWERID_TYPE;										
											break;								
										}
									}
								}
							}
						}					
						at45db_Page_Read(GROUP_PAGE + i, ATTRIB_BA, mbuf, 8);	
						if(  attr->cards  > 0 )
						{
							if( timecount[i].door_power >= 100 &&
								timecount[i].door_time == 0xff )
							{
								//open door
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
								timecount[nid].door_time = attr->door_delay;						
								LogWrite( (nid<<3) + DOOR_NODE, 0, 0, dt->value);						
							}
							else
							{
								
								
							}					
					
						}									

					}
ExitReaderNode:					
					LogWrite( (nid<<3) + READER_NODE, state, id, dt->value);												
									
				}
				break;
			case MEGNET_NODE:
				{
					uint8 t;
					struct tag_attrib *attr;
					attr = (struct tag_attrib *)mbuf;
					t = (msg->bits.msg & 0x1);
					at45db_Page_Read(GROUP_PAGE + nid, ATTRIB_BA, mbuf, 8);			
					OS_ENTER_CRITICAL();
					if( t ^ attr->megnet )
					{
						//set megnet alarm					
						timecount[nid].megnet_time = attr->megnet_delay;
						
					}
					else
					{	
						//close megnet alarm				
						timecount[nid].megnet_time = 0xff;					
					}
					OS_EXIT_CRITICAL();
				}		
				break;
			case EXIT_NODE:
				{
					uint8 t;
					struct tag_attrib *attr;
					attr = (struct tag_attrib *)mbuf;						
					t = (msg->bits.msg & 0x1);
					at45db_Page_Read(GROUP_PAGE + nid, ATTRIB_BA, mbuf, 8);
					OS_ENTER_CRITICAL();
					if( attr->link < 16  )
					{
						if( timecount[attr->link].megnet_time != 0xff )
						{
							OS_EXIT_CRITICAL();
							break;
						}				
					}			
					if( (t ^ attr->button ) && 
						timecount[nid].door_time == 0xff )
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
						timecount[nid].door_time = attr->door_delay;
						ReadRTC(dt);
						LogWrite( (nid<<3) + DOOR_NODE, 0, 0, dt->value);
					}
					
					OS_EXIT_CRITICAL();
				}			
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
			if( t->door_time != 0xff &&
				t->door_time != 0x0 )
			{
				t->door_time--;
			}
			else if( t->door_time == 0x0)
			{
				//close door
				t->door_time = 0xff;
				t->door_power = 0;
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
			if( t->megnet_time != 0xff &&  
				t->megnet_time != 0x0 && 
				t->door_time == 0xff )
			{
				t->megnet_time--;
			}else if( t->megnet_time == 0x00 )
			{
				at45db_Page_Read(GROUP_PAGE + i, ATTRIB_BA, mbuf, 8);
				t->megnet_time = attr->megnet_delay;	
				//read rtc
				ReadRTC(dt);									
				//write log
				LogWrite( (i<<3) + MEGNET_NODE, 0, 0, dt->value);
			}			
		}
		OS_EXIT_CRITICAL();	
		OSTimeDly(200);
	}
	
}




/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
