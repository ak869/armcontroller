#include "config.h"

#define PIN_IN_MASK (PIN_MEGNET1 |  PIN_EXIT1 | PIN_MEGNET2 | PIN_EXIT2 )
extern OS_EVENT *QNoEmptySem;
static struct tag_inpin
{
	uint8	state	: 	3;
	uint32  bit		:	5;		
}pin[LOCAL_DOORS][IN_NODES] = {{{0,PIN_MEGNET1_BIT},{0,PIN_EXIT1_BIT}}};//,{0,PIN_MEGNET1_BIT},{0,PIN_MEGNET1_BIT},

void InputPinTask( void *pdata)
{
	uint32 pin_state,pin_prev_state, t;
	uint8 mbuf[2];
	int i,j;
	PNODEMSG msg;
	msg = (PNODEMSG)mbuf;	
	msg->bits.size = 2;

	pdata = pdata;
	pin_prev_state = pin_state = IOPIN;	
	while(1)
	{	
		OSTimeDly(4);//20ms
		
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
						msg->bits.node = (j + (i << 3));
						msg->bits.msg = (pin_state >> pin[i][j].bit) & 0x1;
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
		
	}

}