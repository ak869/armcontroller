#include "config.h"
extern uint8	msgBuf[128];
#define PIN_IN_MASK (PIN_MEGNET1 |  PIN_EXIT1 | PIN_MEGNET2 | PIN_EXIT2 )

static struct tag_inpin
{
	uint16	megnet_state	: 	3;
	uint16	megnet			:	1;
	uint16	exit_state 		:	3;
	uint16	exit			:	1;
	uint16  alarm_state		:	3;
	uint16  alarm			:	1;	
	uint16	other_state		:	3;
	uint16	other			:	1;	
}pin[LOCAL_DOORS];


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
			
			msg->node = (MEGNET_NODE + READERDOOR1);
			msg->msg = pin[0].megnet;
			if( NMsgQWrite(msgBuf, msg) == QUEUE_OK )
				pin[0].megnet_state = 3;
		}
		
		if( pin[1].megnet_state < 2 )
			pin[1].megnet_state++;
		else if( pin[1].megnet_state == 2)
		{			
			msg->node = (MEGNET_NODE + READERDOOR2);
			msg->msg = pin[1].megnet;
			if( NMsgQWrite(msgBuf, msg) == QUEUE_OK )
				pin[1].megnet_state = 3;
		}			
			
		if( pin[0].exit_state < 2 )
			pin[0].exit_state++;
		else if( pin[0].exit_state == 2)
		{			
			msg->node = (EXIT_NODE + READERDOOR1);
			msg->msg = pin[0].exit;
			if( NMsgQWrite(msgBuf, msg) == QUEUE_OK )
				pin[0].exit_state = 3;
		}
					
		if( pin[1].exit_state < 2 )
			pin[1].exit_state++;
		else if( pin[1].exit_state == 2)
		{
			pin[1].exit_state = 3;
			msg->node = (MEGNET_NODE + READERDOOR2);
			msg->msg = pin[1].exit;
			if( NMsgQWrite(msgBuf, msg) == QUEUE_OK )
				pin[1].exit_state = 3;

		}	
		
	}

}