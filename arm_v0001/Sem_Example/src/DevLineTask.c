#include "config.h"
#include "com.h"
#define MAX_UART_BUFFER	265
static uint8 uart0_buf[MAX_UART_BUFFER];
extern uint32 log_id;
#define SECONDPREBYTE	1	// (1000 * 10 / 9600)
#define CMD_BUSY		1
#define CMD_READY		0
typedef union
{
	struct
	{
		uint32	addr : 	8;
		uint32	token:	4;
		uint32	size :	12;
		uint32 	check:	8;
	}bits;
	uint32 	value32;
	uint8	value8[4];
}THEADER,*PTHEADER;

//XOR 8



/*
1	等待总线空闲
	
2	等待数据
	
3	有数据并符合标志 4 
	不符合标志 1
	
4	有数据未满	4
		    满  5
	超时		2

5   校验  	是	6
			否	1
	
6	检查机号是	7
	        否	分析包 是有数据包	等待 < ( nSize + 2 )(ms) 到 1
	        		   否			1
7	是有数据包  8
	否			16
	
8	有数据未满	8
			满  9
	超时		2

9   校验	是	16
			否	1
	
16

*/
#define TOKEN_REQUESTSIZE	0
#define TOKEN_ALLOWSIZE		1
#define TOKEN_PING			2
#define TOKEN_DATAPACK		3
#define TOKEN_BUSY			6
#define TOKEN_ERRSIZE		7

OS_EVENT	*DevLineMsg;
extern OS_EVENT *QNoEmptySem;
/*
	ping
	F2 01 02 00 03
	F2 01 0A 00 0B
*/
void UART0WriteTab(uint8 *Data, uint16 NByte)
{
    OS_ENTER_CRITICAL();
    while (NByte-- > 0)
    {
    	if( *Data == PLT_VERSION || *Data == PLT_TAB )
    	{
    		UART0Putch(PLT_TAB);
    		UART0Putch(*Data++);
    	}else 
        	UART0Putch(*Data++);
    }
    OS_EXIT_CRITICAL();
}
void DevLineTask(void  *pdata)
{
	int i,n;
	uint8 chk,cmd,t,test;
	uint16 nDataSize;
	uint8 err,state;
	uint8 mBuf[8];
	PNODEMSG msg;	
	PTHEADER header;	
	pdata = pdata;

	msg = (PNODEMSG)mBuf;
	header = (PTHEADER)uart0_buf;
	state = CMD_READY;
	
//	TargetInit();
	while(1)
	{
//			1	
		/*
			等待总线空闲		
		*/
		
//		UART0RXLineClear();
//2		
StartWhile:	
		/*
			开始接受接受数据，协议分析
		*/
		t = UART0Getch();
		if( t != PLT_VERSION )
		{
			if( t == 0xdb)
				t = UART0Getch();
			continue;
		}
		chk = 0;
		i = 0;
		do{	
			t = UART0Getch();
			if( t == 0xdb )
			{
				t = UART0Getch();
			}else if( t == PLT_VERSION )
			{
				continue;
			}
			chk ^= t;
			uart0_buf[i] = t;
			i++;
		}
		while( i < 4 );
		if( chk )
			continue;						//校验错误

		/*
			为命令包，为本机地址，有数据包继续接受
						不是，又有数据包跳空接受
			为应答包，跳空接受
		*/
		
//		6
		if( header->bits.addr != MACHINE_NO )
		{
			t = header->bits.size;
			OSTimeDly( (t + 2) / 5 ); 	//为9600 一个字节为1ms
		}
		nDataSize = header->bits.size + 1;
		
		switch( header->bits.token )
		{


			case TOKEN_REQUESTSIZE:
				if( nDataSize < MAX_UART_BUFFER )
				{
					header->bits.token = TOKEN_ALLOWSIZE;
				}else
					header->bits.token = TOKEN_ERRSIZE;
				header->bits.token |= 0x08;	
				chk = 0;
				for( i = 0; i < 3; i++ )
				{
					chk^= uart0_buf[i];
				}
				header->bits.check = chk;
				UART0Putch(PLT_VERSION);
				
				UART0WriteTab(uart0_buf, 4);
				continue;
				break;
			case TOKEN_DATAPACK:
				if( nDataSize > MAX_UART_BUFFER )
				{
					header->bits.token = TOKEN_ERRSIZE;;
				}else		
				if( state == CMD_BUSY )
					header->bits.token = TOKEN_BUSY;
				else 
					break;			
				i = 0;
				do
				{
					t = UART0Getch();
					if( t == PLT_TAB )
					{
						t = UART0Getch();
					}else if( t == PLT_VERSION )
					{
						continue;
					}
					i++;					
				}while( i < nDataSize );
				header->bits.token |= 0x08;
				chk = 0;
				for( i = 0; i < 3; i++ )
				{
					chk^= uart0_buf[i];
				}
				header->bits.check = chk;				
				UART0Putch(PLT_VERSION);				
				UART0WriteTab(uart0_buf, 4);			
				break;
			case TOKEN_PING:
			{
				uint32 nSize;
				nSize = 0;
				if( state == CMD_BUSY )
				{
					nSize = (uint32)OSMboxAccept(DevLineMsg);
					
				}
				if( nSize == 0 )
				{
					header->bits.token = 0x08 | TOKEN_PING;
					header->bits.size = 0;
				}
				else
				{
					header->bits.token = TOKEN_DATAPACK | 0x8;
					header->bits.size = nSize;
					chk = 0;
					for( i = 0; i < nSize; i++)
						chk ^= uart0_buf[i+4];
						uart0_buf[i+4] = chk;
					state = CMD_READY;					
				}
				chk = 0;
				for( i = 0; i < 3; i++ )
				{
					chk^= uart0_buf[i];
				}
				header->bits.check = chk;
				nSize += 4;
				UART0Putch(PLT_VERSION);				
				UART0WriteTab(uart0_buf, nSize);
				continue;
				break;
			}
		}
	   if( nDataSize - 1 )
	   {
// 			8
			
			chk = 0;
			i = 4;
			do{	
				t = UART0Getch();
				if( t == PLT_TAB )
				{
					t = UART0Getch();
				}else if( t == PLT_VERSION )
				{
					continue;
				}
				chk ^= t;
				uart0_buf[i] = t;
				i++;
			}
			while( i < nDataSize );
	   		if( chk )
	   			continue;	   		
	   }
		/*
			处理协议		
		*/
			   		
/*解析命令*/
/*
	Flash:
	CMD + ADDRESS + SIZE + Data
	CMD	+ ADDRESS + BIT + Data
	CMD + ADDRESS
*/
		cmd = uart0_buf[4];
		switch(cmd)
		{
			case SETLONGDATA:
			case GETLONGDATA:
			case SETBITDATA:
				msg->bits.msg = cmd & 0xf;
				msg->bits.size = 8;
				msg->bits.data[0] = (uint32)(uart0_buf + 1 + 4);
				msg->bits.task = 2;
				msg->bits.node = FLASH_NODE;
				if( NMsgQWrite(msg) == QUEUE_OK )
				{
					OSSemPost(QNoEmptySem);
					state = CMD_BUSY;
				}				
				break;
		}
/*
		switch( cmd )
		{
		case ADDUSER:
			{
				uint16 empty_p,exist_p;
				nDataSize = uart_buf[CMD_P1];
				addr.value[0] = *(uart_buf + DATA_PACK_DATA);
				addr.value[1] = *(uart_buf + DATA_PACK_DATA + 1);
				addr.value[2] = *(uart_buf + DATA_PACK_DATA + 2);
				addr.value[3] = *(uart_buf + DATA_PACK_DATA + 3);
						
				if( addr.addr != 0 && nDataSize == 13 )
				{
					at45db_Comp_uint32( USER_ID_PAGE, 0, addr.addr , (USER_ID_NUMBER), &empty_p, &exist_p );
					if( exist_p == (USER_ID_NUMBER) )
					{						
						exist_p = empty_p;
					}
					addr.addr = 0;
					empty_p =  exist_p / 132;
					addr.bits.pa = empty_p;
					addr.bits.ba = exist_p % 132;
					at45db_PagetoBuffer( 1, addr.bits.pa + USER_ID_PAGE);
					at45db_Buffer_Write( 1, addr.bits.ba, uart_buf + DATA_PACK_DATA , 4);
					at45db_BuffertoPage( 1, addr.bits.pa + USER_ID_PAGE );
					
					addr.bits.pa *= 2;
					addr.bits.ba *= 2;
					at45db_PagetoBuffer( 1, empty_p + USER_GROUP_PAGE );	
					at45db_Buffer_Write( 1, addr.bits.ba, uart_buf + DATA_PACK_DATA + 4, 8);	
					at45db_BuffertoPage( 1, empty_p + USER_GROUP_PAGE );				


					addr.bits.pa >>= 2;
					addr.bits.ba >>= 2;
					at45db_PagetoBuffer( 1, addr.bits.pa + USER_INFO_PAGE );	
					at45db_Buffer_Write( 1, addr.bits.ba, uart_buf + DATA_PACK_DATA + 12, 2);	
					at45db_BuffertoPage( 1, addr.bits.pa + USER_INFO_PAGE );
					
						
					uart_buf[CMD_P4] = 0;
					nDataSize = 0;
				}else
				{
					uart_buf[CMD_P4] = ERR_CMDPARAM;
					nDataSize = 0;
				}
			}
			break;
		case DELUSER:
			{
				uint32 id;
				uint16 empty_p,exist_p;
				nDataSize = uart_buf[CMD_P1];
				addr.value[0] = uart_buf[CMD_P1];
				addr.value[1] = uart_buf[CMD_P2];
				addr.value[2] = uart_buf[CMD_P3];
				addr.value[3] = uart_buf[CMD_P4];
						
				if( addr.addr != 0 )
				{
					at45db_Comp_uint32( USER_ID_PAGE, 0, addr.addr , (USER_ID_NUMBER), &empty_p, &exist_p );
					if( exist_p == (USER_ID_NUMBER) )
					{
						uart_buf[CMD_P4] = ERR_USERNOEXIST;
						nDataSize = 0;
						break;					
					}
					addr.addr = 0;
					empty_p =  exist_p / 528;
					addr.bits.pa = empty_p + USER_ID_PAGE;
					addr.bits.ba = exist_p % 528;
					id = 0;
					at45db_PagetoBuffer( 1, addr.bits.pa );
					at45db_Buffer_Write( 1, addr.bits.ba, (uint8*)&id, 4);
					at45db_BuffertoPageNoErase( 1, addr.bits.pa );			

					uart_buf[CMD_P4] = 0;
					nDataSize = 0;
				}else
				{
					uart_buf[CMD_P4] = ERR_CMDPARAM;
					nDataSize = 0;
				}
			
			}
			break;

		case SETSTATUE:
			switch( uart_buf[CMD_P1] )
			{
				case TEST_NODE:
					test =  uart_buf[CMD_P2];					
					uart_buf[CMD_P4] = 0;
					nDataSize = 0;
					break;
				default:
					uart_buf[CMD_P4] = ERR_NODENOEXIST;
					nDataSize = 0;
					break;					
			}
			break;
		case GETSTATUS:
			switch( uart_buf[CMD_P1] )
			{
				case TEST_NODE:
					uart_buf[CMD_P1] = test;
					uart_buf[CMD_P4] = 0;
					nDataSize = 0;					
					break;
				default:
					uart_buf[CMD_P4] = ERR_NODENOEXIST;
					nDataSize = 0;
					break;				
			}
			break;
		case DOWNLOADLOG:
			{
				uint32 id;
				uint16 ba,pa;
				addr.value[3] = uart_buf[CMD_P1];
				addr.value[2] = uart_buf[CMD_P2];
				addr.value[1] = uart_buf[CMD_P3];
				addr.value[0] = uart_buf[CMD_P4];
				id = addr.addr;
				if( log_id - id > MAX_SAVELOGS )
				{
					id = log_id - MAX_SAVELOGS;
				}
				ba = (id % 33) << 4;
				pa = id / 33;
				pa %= (MAX_PAGE_COUNT - LOG_PAGE);
				pa += LOG_PAGE;
				
				//read log
				nDataSize = (log_id - id) * 16;
				if( nDataSize > 256 )
				{
					nDataSize = 256;
				}
				if( pa == 4095 && 
					ba + nDataSize > 528 )
				{
					nDataSize = 528 - ba;
				}
				at45db_Page_Read( pa, ba, uart_buf + DATA_PACK_DATA, nDataSize);
				uart_buf[CMD_P4] = 0;
				nDataSize--;
				break;
			}
		case SETPOINTLOG:
			break;
		default:
			uart_buf[CMD_P4] = ERR_CMD;
			nDataSize = 0;
			break;		
		}
		
		
		cmd |= 0x80;
		cmd &= 0xBF;
		uart_buf[CMD_CMD] = cmd;
		uart_buf[0] = PLT_VERSION;
		uart_buf[CMD_ADDR] = MACHINE_NO;		
		chk = 0;
		for( i = 1; i < 7; i++)
		{
		
			chk ^= uart_buf[i];
		}
		
		uart_buf[i] = chk;
		i++;
		if( nDataSize )
		{
			uart_buf[CMD_CMD] |= 0x40;
			uart_buf[CMD_XOR] ^= 0x40;
			uart_buf[i] = PLT_VERSION;
			i++;
			nDataSize += i;
			chk = 0;
			for( ; i < nDataSize; i++ )
			{
				chk ^= uart_buf[i];
			}
		   	uart_buf[i] = chk;
		   	i++;
	   	}
	   	UART0Write(uart_buf, i);
*/	   	
	}
	
}