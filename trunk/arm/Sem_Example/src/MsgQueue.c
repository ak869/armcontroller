#include "config.h"


// queue max 512 byte no include header
//
#define MAX_QUEUE_DATA	128
#define MAP_SIZE		(MAX_QUEUE_DATA / 16)

#define QUEUE_ADDRESS_MASK	0x3ff;

#define MAP_BIT_MASK	(16 - 1)

#define MSG_NODE(x)		((PNODEMSG)(MsgQueue.buf + x))

struct tag_msgqueue
{
	uint32  out : 10;
	uint32  in  : 10;
	uint32  NData : 12;
	uint16  map[ MAP_SIZE ];
	uint32  buf[ MAX_QUEUE_DATA ];
}MsgQueue;


void NMsgQCreate( void )
{
	int i;
	MsgQueue.out = 0x3ff;
	MsgQueue.in = 0x3ff;
	MsgQueue.NData = 0;
	for( i = 0; i < MAP_SIZE; i++ )
		MsgQueue.map[i] = 0x0;
}

uint8 NMsgQWrite( PNODEMSG Val )
{
	int i,j;
	uint16 id;
	uint8 nSize;
	uint16 *map;
	uint32 m,mask;
	nSize = (Val->bits.size >> 2);
	if( nSize == 0 )
		return FALSE;
	mask = (1 << nSize) - 1;
	map = MsgQueue.map;
	OS_ENTER_CRITICAL();
	m = (map[1] << 16) + map[0];
	id = 0;
	for( i = 2; i < MAP_SIZE; i++)
	{		
		for( j = 0; j < 16; j++ )
		{
			if( m & mask )
			{
				mask <<= 1;
				id++;
			}else
			{
//				id = 2;
				m |= mask;
				map[i - 2] |= (uint16)m;
				map[i - 1] |= (uint16)(m>>16);
				goto map_exit;
			}
		}
		mask >>= 16;
		m >>= 16;
		m += (map[i] << 16);
	}
	for( j = 0; j < 16; j++ )
	{
		if( m & mask )
		{
			mask <<= 1;
			id++;
		}else
		{
			m |= mask;
			map[i - 2] |= m;
			map[i - 1] |= (m>> 16);
			goto map_exit;
		}
	}
	mask >>= 16;
	m >>= 16;
	m |= 0xffff0000;
	for( j = 0; j < 16; j++ )
	{
		if( m & mask )
		{
			mask <<= 1;
			id++;
		}else
		{
			m |= mask;
			map[i - 1] |= m;
			goto map_exit;
		}
	}
	OS_EXIT_CRITICAL();
	return FALSE;
map_exit:
	for( i = 0; i < nSize; i++ )
	{
		MsgQueue.buf[id + i] = Val->value[i];
	}
	if( MsgQueue.in != 0x3ff )
	{
		MSG_NODE(MsgQueue.in)->bits.next = id;
		MSG_NODE(id)->bits.next = 0x3ff;
		MsgQueue.in = id;
	}else
	{
		MSG_NODE(id)->bits.next = 0x3ff;
		MsgQueue.in = id;
		MsgQueue.out = id;
	}
	MsgQueue.NData++;
	OS_EXIT_CRITICAL();
	return TRUE;
}

uint8 NMsgQRead( PNODEMSG Ret,uint8 node, uint8 node_mask )
{
	uint16 id;
	uint32 m;
	uint8 ret;
	int i;
	uint8 nSize;
	PNODEMSG t,prev;
	uint8 tsk;
	uint32 mask;

	nSize = (Ret->bits.size >> 2);
	if( nSize == 0 )
		return FALSE;
	ret = FALSE;
	tsk = GetOSPrioCur();
	OS_ENTER_CRITICAL();
	if( MsgQueue.NData > 0 )
	{
		id = MsgQueue.out;
		prev = NULL;
		while( id != 0x3ff )
		{
			t = MSG_NODE(id);
			if( t->bits.task != tsk ||
				(t->bits.node & node_mask) != node )
			{
				prev = t;
				id = t->bits.next;
			}
			else
			{
				nSize = t->bits.size;
				if( nSize > Ret->bits.size )
					return FALSE;

				if( prev == NULL )
				{
					MsgQueue.out = t->bits.next;
				}
				else
				{
					prev->bits.next = t->bits.next;
				}
				nSize >>= 2;
				for( i = 0; i < nSize; i++)
				{
					Ret->value[i] = MsgQueue.buf[id + i];
				}
				//map
				
				mask = (1 << nSize ) - 1;
				m = MsgQueue.map[id >> 4];
				m += ( MsgQueue.map[(id >> 4) + 1] << 16 );
				m &= ~(mask << (id & MAP_BIT_MASK));
				MsgQueue.map[id >> 4] = m;
				MsgQueue.map[(id >> 4) + 1] = (m >> 16);
				break;
			}

		}
		if( id != 0x3ff )
		{
			MsgQueue.NData--;
			ret = TRUE;
		}
	}
	OS_EXIT_CRITICAL();
	return ret;
}




