#include "config.h"

#define PIN_IN_MASK (PIN_MEGNET1 |  PIN_EXIT1 | PIN_MEGNET2 | PIN_EXIT2 )
extern OS_EVENT *QNoEmptySem;
static struct tag_inpin
{
	uint8	state	: 	3;
	uint32  bit		:	5;		
}pin[LOCAL_DOORS][IN_NODES] = {{{0,PIN_MEGNET1_BIT},{0,PIN_EXIT1_BIT}}};//,{0,PIN_MEGNET1_BIT},{0,PIN_MEGNET1_BIT},
extern unsigned char wd1_count;
extern unsigned char wd2_count;


extern unsigned int wd1_data;
extern unsigned int wd2_data;

void InputPinTask( void *pdata)//20ms
{
	uint32 pin_state,pin_prev_state, t;
	uint8 mbuf[8];
	uint8 wd1_count_prev,wd2_count_prev;
	uint8 wd1_state,wd2_state;
	int i,j;
	PNODEMSG msg;
	msg = (PNODEMSG)mbuf;	

	pdata = pdata;
	pin_prev_state = pin_state = IOPIN;
	
	wd1_count_prev = wd1_count;
	wd2_count_prev = wd2_count;
	wd1_state = 0;
	wd2_state = 0;
	
	while(1)
	{	
		OSTimeDly(4);//20ms
		OS_ENTER_CRITICAL();
		if( wd1_count_prev == wd1_count )
		{
			if( wd1_state )
			{
				wd1_state = 0;
				switch( wd1_count )
				{
					case 0:
						break;
					case 26:
						//t = WD1_26_check();
						t = wd1_data >> 6;
						if( t != 0 )
						{
							msg->bits.size = 8;
							msg->bits.node = READER_NODE + READERDOOR1;
							msg->bits.msg = 0;
							msg->bits.task = 2;
							msg->bits.data[0] = t;
							if( NMsgQWrite(msg) == QUEUE_OK )
							{
								
								OSSemPost(QNoEmptySem);
							}
						}
						WD1_RST();				 
						break;
					default:
						WD1_RST();
						break;
				}
			}			
		}
		else
		{	
			wd1_state = 1;
			wd1_count_prev = wd1_count;
		}
		OS_EXIT_CRITICAL();
		OS_ENTER_CRITICAL();
		if( wd2_count_prev == wd2_count )
		{
			if( wd2_state )
			{
				wd2_state = 0;
				switch( wd2_count )
				{
					case 0:
						break;
					case 26:
						t = WD2_26_check();
						//t = wd2_data;
						if( t != 0 )
						{
							msg->bits.size = 8;
							msg->bits.node = READER_NODE + READERDOOR2;
							msg->bits.msg = 0;
							msg->bits.task = 2;
							msg->bits.data[0] = t;
							if( NMsgQWrite(msg) == QUEUE_OK )
							{
								
								OSSemPost(QNoEmptySem);
							}
						}
						WD2_RST();			
						break;
					default:
						WD2_RST();
						break;
				}
			}			
		}
		else 
		{	
			//
			wd2_state = 1;
			wd2_count_prev = wd2_count;
		}
		OS_EXIT_CRITICAL();
/*		
		pin_state = IOPIN;
		t = (pin_state ^ pin_prev_state);
		for( i = 0; i < LOCAL_DOORS; i++ )
		{
			for( j = 0; j < IN_NODES; j++)
			{
				if( t & (1 << pin[i][j].bit) )
				{
					pin[i][j].state = 0;			
				}else
				{
					if( pin[i][j].state < 2 )
						pin[i][j].state++;
					else if( pin[i][j].state == 2 )
					{
						msg->bits.size = 4;
						msg->bits.node = (j + (i << 3));
						msg->bits.msg = (pin_state >> pin[i][j].bit) & 0x1;
						msg->bits.task = 2;
						if( NMsgQWrite(msg) == QUEUE_OK )
						{
							OSSemPost(QNoEmptySem);
							pin[i][j].state = 3;
						}						
					}
				}
			
			}
		
		}
		pin_prev_state = pin_state;
*/		
		
	}
}
