#include "config.h"
#include "com.h"
static uint8 host_buf[256];

void HostLineTask(void  *pdata)
{
	int i,n;
	uint8 node,t,mbuf[8];
	uint8 chk,cmd,test;
	uint8 nSize,err;
	union tag_flashaddr addr;
	PNODEMSG msg;
		
	pdata = pdata;
	msg = (PNODEMSG)mbuf;
	node = 0x10;
	while(1)
	{
		
		/*
			发送令牌		
		*/		
		msg->bits.size = 8;
		if( NMsgQRead(msg, node, 0x78) )
		{
			t = msg->bits.node & 0x3;
			switch( t )
			{
				case CTRL_NODE:
				case DOOR_NODE:
					host_buf[CMD_CMD] = t;
					host_buf[CMD_P1] = 0;
					host_buf[CMD_P2] = msg->bits.msg;
					nSize = 0;
					break;
				case EXT_NODE:
					break;
				default:
					break;
			}			
		}
	
		host_buf[CMD_FLAG] = PLT_VERSION;
		host_buf[CMD_ADDR] = (node >> 3);
		chk = 0;
		for( i = 1; i < CMD_SIZE - 1; i++ )
		{
			chk ^= host_buf[i];
		}		
		host_buf[CMD_XOR] = chk;
		
		if( nSize )
		{
			chk = 0;
			
			for(i = 0; i < nSize; i++)
				chk ^= host_buf[DATA_PACK_DATA + i];
				
			host_buf[DATA_PACK_DATA + i] = chk;	
		}
		
		//senduart1
		
		/*
			接受等待，解析协议
		*/
		
		
		/*
			记录时钟
		*/
		
		/*
			处理协议		
		*/
		
		/*
			没有超过总线空闲时间的继续等
		*/
		node+= 0x80;
		if( node >= 0x78 )
			node = 0x10;
	}
}