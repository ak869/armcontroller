#include "config.h"
#include "com.h"

uint8 uart_buf[256];

void PcLineTask(void  *pdata)
{
	int i,n;
	uint8 chk,cmd,t,test;
	uint8 nDataSize,err;
	union tag_flashaddr addr;	
	pdata = pdata;

	
	while(1)
	{
StartWhile:	
		chk = 0;
		UART0RXLineClear();
		t = UART0Getch();
		if( t != PLT_VERSION )
			continue;
		uart_buf[0] = t;
		chk = 0;			
		for( i = 1; i < 8; i++ )
		{
	   		t = UART0GetchForWait(&err);
		   	if( err != OS_NO_ERR )
		   			goto StartWhile;
			chk ^= t;
			uart_buf[i] = t;
		}		
		if( chk )
			continue;
		
		cmd = uart_buf[CMD_CMD];
		if( uart_buf[CMD_ADDR] != MACHINE_NO )
		{
			if(  cmd & 0x40 )
			{
			//close uart recv interrupt
				t = uart_buf[CMD_P1];
				OSTimeDly( (t + 4 + 3) / 5 ); 	//5ms
			//open uart recv interrupt
			}
			continue;
		}	

	   
	   if(  cmd & 0x40 )
	   {
	   		n = uart_buf[CMD_P1] + 8 + 2;
	   		t = UART0GetchForWait(&err);
	   		
	   		if( err != OS_NO_ERR )
	   			goto StartWhile;
	   			
	   		if( t != PLT_VERSION )
	   			goto StartWhile;
	   			   			
	   		uart_buf[DATA_PACK_FLAG] = t;

	   		chk = 0;	
	   		for( i = DATA_PACK_DATA; i < n; i++ )
	   		{
	   			t = UART0GetchForWait(&err);
		   		if( err != OS_NO_ERR )
		   			goto StartWhile; 			
				chk ^= t;
				uart_buf[i] = t;	   			
	   		}
	   		if( chk )
	   			continue;	   		
	   }

				   		
/*½âÎöÃüÁî*/
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
						
				if( addr.addr != 0 && nDataSize == 11 )
				{
					at45db_Comp_uint32( USER_ID_PAGE, 0, addr.addr , (USER_ID_NUMBER * USER_ID_SIZE), &empty_p, &exist_p );
					if( exist_p == (USER_ID_NUMBER * USER_ID_SIZE) )
					{						
						exist_p = empty_p;
					}
					addr.addr = 0;
					empty_p =  exist_p / 528;
					addr.bits.pa = empty_p + USER_ID_PAGE;
					addr.bits.ba = exist_p % 528;
					at45db_PagetoBuffer( 1,  empty_p + USER_ID_PAGE );
					at45db_Buffer_Write( 1, exist_p % 528, uart_buf + DATA_PACK_DATA , 4);
					at45db_BuffertoPage( 1, empty_p + USER_ID_PAGE );
					
					exist_p *= 2;
					empty_p =  exist_p / 528;
					at45db_PagetoBuffer( 1, empty_p + USER_INFO_PAGE );	
					at45db_Buffer_Write( 1, exist_p % 528, uart_buf + DATA_PACK_DATA + 4, 8);	
					at45db_BuffertoPage( 1, empty_p + USER_INFO_PAGE );				

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
				uint16 empty_p,exist_p;
				nDataSize = uart_buf[CMD_P1];
				addr.value[0] = uart_buf[CMD_P1];
				addr.value[1] = uart_buf[CMD_P2];
				addr.value[2] = uart_buf[CMD_P3];
				addr.value[3] = uart_buf[CMD_P4];
						
				if( addr.addr != 0 )
				{
					at45db_Comp_uint32( USER_ID_PAGE, 0, addr.addr , (USER_ID_NUMBER * USER_ID_SIZE), &empty_p, &exist_p );
					if( exist_p == (USER_ID_NUMBER * USER_ID_SIZE) )
					{
						uart_buf[CMD_P4] = ERR_USERNOEXIST;
						nDataSize = 0;
						break;					
					}
					addr.addr = 0;
					empty_p =  exist_p / 528;
					addr.bits.pa = empty_p + USER_ID_PAGE;
					addr.bits.ba = exist_p % 528;
					addr.addr = 0;
					at45db_PagetoBuffer( 1,  empty_p + USER_ID_PAGE );
					at45db_Buffer_Write( 1, exist_p % 528, addr.value, 4);
					at45db_BuffertoPageNoErase( 1, empty_p + USER_ID_PAGE );			

					uart_buf[CMD_P4] = 0;
					nDataSize = 0;
				}else
				{
					uart_buf[CMD_P4] = ERR_CMDPARAM;
					nDataSize = 0;
				}
			
			}
			break;
		case GETLONGDATA:
			{
				nDataSize = uart_buf[CMD_P1];
				addr.addr = 0;
				addr.value[2] = uart_buf[CMD_P2];
				addr.value[1] = uart_buf[CMD_P3];
				addr.value[0] = uart_buf[CMD_P4];			
				if( nDataSize + addr.bits.ba <= MAX_PAGE_SIZE && addr.bits.pa < MAX_PAGE_COUNT )
				{
					at45db_Page_Read(addr.bits.pa, addr.bits.ba, uart_buf + DATA_PACK_DATA , nDataSize );
					uart_buf[CMD_P4] = 0;
				}else
				{
					uart_buf[CMD_P4] = ERR_CMDPARAM;
					nDataSize = 0;
				}
			}
			break;
		case SETLONGDATA:
			{
				nDataSize = uart_buf[CMD_P1];
				addr.addr = 0;
				addr.value[2] = uart_buf[CMD_P2];
				addr.value[1] = uart_buf[CMD_P3];
				addr.value[0] = uart_buf[CMD_P4];
				
				if( nDataSize + addr.bits.ba <= MAX_PAGE_SIZE && addr.bits.pa < MAX_PAGE_COUNT )
				{			
					at45db_PagetoBuffer( 1, addr.bits.pa );
					at45db_Buffer_Write( 1, addr.bits.ba, uart_buf + DATA_PACK_DATA , nDataSize );
					at45db_BuffertoPage( 1, addr.bits.pa );				
					uart_buf[CMD_P4] = 0;
				}
				else
				{
					uart_buf[CMD_P4] = ERR_CMDPARAM;
				}
				nDataSize = 0;	
			}
			break;
		case SETBYTEDATA:
			{
				addr.addr = 0;
				addr.value[2] = uart_buf[CMD_P2];
				addr.value[1] = uart_buf[CMD_P3];
				addr.value[0] = uart_buf[CMD_P4];
				
				if( nDataSize + addr.bits.ba <= MAX_PAGE_SIZE && addr.bits.pa < MAX_PAGE_COUNT )
				{			
					at45db_PagetoBuffer( 1, addr.bits.pa );
					at45db_Buffer_Write( 1, addr.bits.ba, uart_buf + CMD_P1 , 1 );
					at45db_BuffertoPage( 1, addr.bits.pa );				
					uart_buf[CMD_P4] = 0;
				}
				else
				{
					uart_buf[CMD_P4] = ERR_CMDPARAM;
				}
				nDataSize = 0;	
			}		
			break;
		case SETBITDATA:
			{
				chk = uart_buf[CMD_P1];
				nDataSize = chk & 0xf;
				chk >>= 4;
				addr.addr = 0;
				addr.value[2] = uart_buf[CMD_P2];
				addr.value[1] = uart_buf[CMD_P3];
				addr.value[0] = uart_buf[CMD_P4];
				
				if( nDataSize + addr.bits.ba <= MAX_PAGE_SIZE && addr.bits.pa < MAX_PAGE_COUNT )
				{			
					at45db_PagetoBuffer( 1, addr.bits.pa );					
					at45db_Buffer_Read( 1, addr.bits.ba, &t , 1 );					
					if(nDataSize == 0)
					{
						t &= (~(0x1 << chk ));
					}
					else
						t |= (0x1 << chk );
					at45db_Buffer_Write( 1, addr.bits.ba, &t , 1 );
					at45db_BuffertoPage( 1, addr.bits.pa );				
					uart_buf[CMD_P4] = 0;
				}
				else
				{
					uart_buf[CMD_P4] = ERR_CMDPARAM;
				}
				nDataSize = 0;	
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
	}
}