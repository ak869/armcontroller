#include "config.h"
#include "com.h"
static uint8 host_buf[256];
//token
extern OS_EVENT *QNoEmptySem;
#define TOKEN_SIZE		3

#define TOKEN_FLAG		0
#define TOKEN_NODE		1
#define TOKEN_P1		2
#define TOKEN_P2		3
#define TOKEN_P3		4
#define TOKEN_P4		5
#define TOKEN_ADDR		6
#define TOKEN_XOR		7
/*  
host send
	2:0 -> node
	5:3 -> size	(7:ext_cmd)
	6   -> x	
	7	-> token 0

ext_ack		01xxxxxxb
	read	flash
	write	flash
	P1	-> dataPack size
	P4  -> return;
	
device send
	2:0 -> node
	5:3 -> size (7:ext_cmd)
	6	-> x
	7   -> ack	1
ext_cmd		
	P1	-> dataPack size
	P2  -> addr[0]
	P3  -> addr[1]
	P4  -> addr[2]
	
*/
void HostLineTask(void  *pdata)
{
	int i,n;
	uint8 node,t,mbuf[8];
	uint8 chk,cmd,test;
	uint8 nSize,err;
	union tag_flashaddr addr;
	PNODEMSG msg;
	uint8 *f;
		
	pdata = pdata;
	msg = (PNODEMSG)mbuf;
	node = 0x10;
	while(1)
	{
		node += 0x80;
		if( node > 0x78 )
			node = 0x10;	
		
		/*
			发送令牌		
		*/		
		msg->bits.size = 8;
		if( NMsgQRead(msg, node, 0x78) )
		{
			t = msg->bits.node & 0x3;
			nSize = msg->bits.size > 4 ? 4:1;
			switch( t )
			{
				case EXT_NODE:
					break;
				default:
					if( msg->bits.size > 4 )
					{
						nSize = 0;
						f = (uint8*)(msg->value + 1);
						host_buf[TOKEN_P1] = f[0];
						host_buf[TOKEN_P2] = f[1];
						host_buf[TOKEN_P3] = f[2];
						host_buf[TOKEN_P4] = f[3];
						
					}
					else
					{
						nSize = 1;
						host_buf[TOKEN_P1] = msg->bits.msg;	
					}
					host_buf[TOKEN_NODE] = t | (nSize << TOKEN_SIZE);					
					nSize = 0;				
					break;
			}			
		}
	
		host_buf[TOKEN_FLAG] = PLT_VERSION;
		host_buf[TOKEN_ADDR] = (node >> 3);
		chk = 0;
		for( i = 1; i < CMD_SIZE - 1; i++ )
		{
			chk ^= host_buf[i];
		}		
		host_buf[TOKEN_XOR] = chk;
		
		if( nSize )
		{
			chk = 0;
			
			for(i = 0; i < nSize; i++)
				chk ^= host_buf[DATA_PACK_DATA + i];
				
			host_buf[DATA_PACK_DATA + i] = chk;	
		}
		
		//senduart1
		UART1Write(host_buf, 8);
		/*
			接受等待，解析协议
		*/
		/*
			记录时钟
		*/
		host_buf[0] = UART1GetchForWait(4, &err);
		if( err != OS_NO_ERR )
		{
			continue;
		}
		chk = 0;
		for( i = 1; i < 8; i++ )
		{
			host_buf[i] = UART1GetchForWait(1, &err);
			if( err != OS_NO_ERR )
			{
			
				continue;
			}
			chk^= host_buf[i];
		}
		if( chk )
		{
			continue;
		}
		
		/*
			处理协议		
		*/
		msg->bits.node = (host_buf[TOKEN_NODE] & 0x3) + host_buf[TOKEN_ADDR] << 3;
		nSize = (host_buf[TOKEN_NODE] >> 3 & 0x3);
		if( nSize == 1 )
		{
			msg->bits.size = 8;
			msg->bits.msg = host_buf[TOKEN_P1];
		}else
		{
			msg->bits.size = 8;
			f = (uint8*)(msg->value + 1);
			f[0] = host_buf[TOKEN_P1];
			f[1] = host_buf[TOKEN_P2];
			f[2] = host_buf[TOKEN_P3];
			f[3] = host_buf[TOKEN_P4];		
		}
		 
		msg->bits.task = 2;
		while( NMsgQWrite(msg) != QUEUE_OK )
		{
			OSTimeDly(2);			
		}
		OSSemPost(QNoEmptySem);
		
		
		/*
			没有超过总线空闲时间的继续等
		*/

	}
}