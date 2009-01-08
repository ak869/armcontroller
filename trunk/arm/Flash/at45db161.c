/*
P0.4-MSCK
P0.5-MISO
P0.6-MOSI
P0.7-MCS
*/
#include "config.h"

#define FLASH_FREE			0
#define FLASH_A			1
#define FLASH_B			2
#define FLASH_C			3
#define FLASH_D			4
#define FLASH_BUFFER1_LOCK	0x10
#define	FLASH_BUFFER2_LOCK	0x20

#define MCS			PIN_MCS
static OS_EVENT *FlashSem;
static OS_EVENT *FlashBufSem;
static uint8 UseFlashTaskPro, prev_level;
uint8 FlashInit(void)
{
    UseFlashTaskPro = OS_PRIO_SELF;
    prev_level = FLASH_FREE;
    FlashSem = OSSemCreate(1);                    /* ”√”⁄ª•≥‚∑√Œ FLASH */
    FlashBufSem = OSSemCreate(1);
    if (FlashSem != NULL && FlashBufSem != NULL )
    {
    	if( (at45db_Status_reg_read() & 0x80) == 0 )
    	{
    		prev_level = FLASH_A;
    	}   
        return TRUE;
    }
    else
    {
        return FALSE;
    }	
}
/*
void at45db_Buffer_UnLock(uint8 id)
{
	OS_ENTER_CRITICAL();
	id <<= 4;
	prev_level &= ~id;
	OS_EXIT_CRITICAL();
}
*/
void FlashStart(uint8 level, uint8 id)
{
	uint8 err;
	
    if( UseFlashTaskPro != GetOSPrioCur() )
    {
    	OSSemPend(FlashSem, 0, &err);
    	UseFlashTaskPro = GetOSPrioCur();
    }
    
    
/*    
    err = prev_level & 0x0f;
    id <<= 4;
    if( err == FLASH_B )
    {
    	if( level == FLASH_C &&
    	(prev_level & 0xf0) != id )
    	{
    		prev_level |=  id;
    		break;
    	}else
    	{
    		at45db_Status_reg_read();
    		OSTimeDly(2);
    	}
    }else if( err == FLASH_D )
    {
    	at45db_Status_reg_read();
    	OSTimeDly(2);
    }
*/    
    
    
}
void FlashEnd(void)
{
    uint8 temp;    
    temp = GetOSPrioCur();
    if (temp == UseFlashTaskPro)
    {
        UseFlashTaskPro = OS_PRIO_SELF;
        OSSemPost(FlashSem);
    }	
}

uint8 at45db_Status_reg_read(void)
{
	uint8 rcv_data;
	int i;
	FlashStart(FLASH_C, 0);
    SSPStart();
	IOCLR = MCS;			
	SSPDR = 0xD7;
	SSPDR = 0xFF;
	
	for( i = 0; i < 2; i++)
	{
		rcv_data = SSPSR;
		while( !(rcv_data & SSP_RX_FIFO_NO_EMPTY) ) rcv_data = SSPSR;;
		rcv_data = SSPDR;
	}
		
	IOSET = MCS;		
	SSPEnd();
	for( i = 0; i < 8; i++);
	FlashEnd();
	return rcv_data;
}

void at45db_Buffer_Write( int id,uint16 ba, uint8 *buf, int nSize)
{
	int j;
	uint8 t;
	FlashStart(FLASH_C,id);
	while( (at45db_Status_reg_read() & 0x80) == 0 ) OSTimeDly(2);
	
	SSPStart();
	IOCLR = MCS;	
	if( id == 1 )
	{
		SSPDR = 0x84;
	}
	else
		SSPDR = 0x87;
		
	SSPDR = 0;
	SSPDR = (uint8)(ba >> 8);
	SSPDR = (uint8)ba;
	//4
	j = 0;
	while( nSize )
	{
		t = SSPRIS;
		while( !(t & SSP_TX_FIFO_HALF_EMPTY) ) t = SSPRIS;
		if( t & SSP_RX_FIFO_HALF_FULL )
			t = SSPDR;
		SSPDR = buf[j];		
		nSize--;
		j++;
	}
	
	t = SSPSR;
	while( !(t & SSP_TX_FIFO_EMPTY ) ) t = SSPSR;
	
	t = SSPSR;
	while( t & SSP_RX_FIFO_NO_EMPTY )
	{
		t = SSPDR;
		t = SSPSR;
	}
		
	IOSET = MCS;
	SSPEnd();
	for( j = 0; j < 8; j++);
	FlashEnd();
	return;
}
void at45db_Buffer_Read(int id, uint16 ba, uint8 *buf,int nSize)
{
	int j;
	uint8 t;
	FlashStart(FLASH_C,id);
	while( (at45db_Status_reg_read() & 0x80) == 0 ) OSTimeDly(2);
	SSPStart();	
	IOCLR = MCS;

	if( id == 1 )
		SSPDR = 0xD1;
	else
		SSPDR = 0xD3;
	SSPDR = 0;
	SSPDR = (uint8)(ba >> 8);
	SSPDR = (uint8)ba;
	SSPDR = 0xff;
	
	j = 0;
	nSize += 5;
	while( nSize + 5 )
	{
		t = SSPSR;
		while( !(t & SSP_RX_FIFO_NO_EMPTY ) ) t = SSPSR;
		if( j < 5 )
			buf[0] = SSPDR;
		else
			buf[j - 5] = SSPDR;
			
		if( nSize <= 5 ) SSPDR = 0xff;
		j++;
		nSize--;
	}
	IOSET = MCS;
	
	SSPEnd();
	for( j = 0; j < 8; j++);
	FlashEnd();
	return;	
}

void at45db_Comp_uint32(uint16 pa,uint16 ba, uint32 id, int nSize, uint16 *empty_p, uint16 *exist_p )
{
	int i,j;
	uint8 t,*id8;
	uint32 c;
	FlashStart(FLASH_A,0);
	while( (at45db_Status_reg_read() & 0x80) == 0 ) OSTimeDly(2);	
	SSPStart();
	IOCLR = MCS;
	
	SSPDR = 0x03;
	SSPDR = (uint8)(pa >> 6);
	SSPDR = (uint8)(pa << 2) + ((uint8)(ba >> 8) & 0x3) ;
	SSPDR = (uint8)ba;
	SSPDR = 0xff;
	SSPDR = 0xff;
	SSPDR = 0xff;
	SSPDR = 0xff;

	
	t = SSPRIS;
	while( !(t & SSP_RX_FIFO_HALF_FULL ) ) t = SSPRIS;
	t = SSPDR;
	t = SSPDR;
	t = SSPDR;
	t = SSPDR;
	
	SSPDR = 0xff;
	SSPDR = 0xff;
	SSPDR = 0xff;
	SSPDR = 0xff;	

	j = nSize;
	id8 = (uint8*)&c;
	while( j )
	{		
		t = SSPRIS;
		while( !(t & SSP_RX_FIFO_HALF_FULL ) ) t = SSPRIS;
		
		*id8 = SSPDR;
		id8++;
		*id8 = SSPDR;
		id8++;
		*id8 = SSPDR;
		id8++;
		*id8 = SSPDR;
		id8++;		
		if( id == c )
		{
			break;
		}else if( c == 0 || c == 0xffffffff)
		{
			*empty_p = j;
		}
		SSPDR = 0xff;
		SSPDR = 0xff;
		SSPDR = 0xff;
		SSPDR = 0xff;
		id8 = (uint8*)&c;
		j--;
		
/*			
		if( j < 4 )
			t = SSPDR;
		else
		{
			c >>= 8;
			*id8 = SSPDR;			
			bytes++;
		}
		if( bytes == 4 )
		{
			if( c == id )
			{
				break;
			}
			else
			{
				if( c == 0 || c == 0xffffffff)
					*empty_p = j;
				bytes = 0;
				c = 0;
			}
		}
		if( nSize > 4 )
		{
			SSPDR = 0xff;
		}
*/		
		
	}
	
	t = SSPSR;
	while( !(t & SSP_TX_FIFO_EMPTY ) ) t = SSPSR;
	t = SSPSR;
	while( t & SSP_RX_FIFO_NO_EMPTY )
	{
		t = SSPDR;
		t = SSPSR;
	}

	
	IOSET = MCS;
	*exist_p = ( nSize - j );
	*empty_p = ( nSize - *empty_p );
		
	SSPEnd();
	for( i = 0; i < 8; i++);
	FlashEnd();
	return;
}
void at45db_Page_Read(uint16 pa,uint16 ba, uint8* buf, int nSize)
{
	int j;	
	uint8 t;
	FlashStart(FLASH_A,0);
	while( (at45db_Status_reg_read() & 0x80) == 0 ) OSTimeDly(2);
	SSPStart();	
	IOCLR = MCS;

	SSPDR = 0x03;
	SSPDR = (uint8)(pa >> 6);
	SSPDR = (uint8)(pa << 2) + ((uint8)(ba >> 8) & 0x3);
	SSPDR = (uint8)ba;
	
	

	j = 0;
	nSize += 4;
	while( nSize )
	{
		t = SSPSR;
		while( !(t & SSP_RX_FIFO_NO_EMPTY ) ) t = SSPSR;
		if( j < 4 )
			buf[0] = SSPDR;
		else
		{
			buf[j-4] = SSPDR;
		}
		if( 4 < nSize )
		{
			SSPDR = 0xff;
		}
		j++;
		nSize--;
	}


	IOSET = MCS;
		
	SSPEnd();
	for( j = 0; j < 8; j++);
	FlashEnd();
	return;	
}


void at45db_PagetoBuffer(int id, uint16 pa)
{
	int i;
	uint8 t;
	FlashStart(FLASH_B,id);
	while( (at45db_Status_reg_read() & 0x80) == 0 )
		 OSTimeDly(2);
	SSPStart(); 	
	IOCLR = MCS;

	if( id == 1 )
		SSPDR = 0x53;
	else
		SSPDR = 0x55;
	SSPDR = (uint8)( pa >> 6);//PA6	
	SSPDR = (uint8)(pa << 2);//BA8
	SSPDR =  0;//BA0

	t = SSPSR;
	while( !(t & SSP_TX_FIFO_EMPTY ) ) t = SSPSR;
	
	i = 4;	
	do{
		t = SSPDR;
		i--;
	}while( i );
	
	

	IOSET = MCS;		
	SSPEnd();
	for( i = 0; i < 8; i++);
	FlashEnd();
	return;	
}

void at45db_BuffertoPage(int id, uint16 pa)
{
	int i;
	uint8 t;
	FlashStart(FLASH_B,id);
	while( (at45db_Status_reg_read() & 0x80) == 0 ) OSTimeDly(2);
	SSPStart();
	IOCLR = MCS;

	if( id == 1 )
		SSPDR = 0x83;
	else
		SSPDR = 0x86;
	SSPDR = (uint8)( pa >> 6);//PA6	
	SSPDR = (uint8)(pa << 2);//BA8
	SSPDR =  0;//BA0

	t = SSPSR;
	while( !(t & SSP_TX_FIFO_EMPTY ) ) t = SSPSR;
	
	i = 4;	
	do{
		t = SSPDR;
		i--;
	}while( i );

	IOSET = MCS;
	SSPEnd();
	for( i = 0; i < 8; i++);	
	FlashEnd();
	return;		
}

void at45db_BuffertoPageNoErase(int id, uint16 pa)
{
	int i;
	uint8 t;	
	FlashStart(FLASH_B,id);
	while( (at45db_Status_reg_read() & 0x80) == 0 ) OSTimeDly(2);
	SSPStart();	
	IOCLR = MCS;

	if( id == 1 )
		SSPDR = 0x88;
	else
		SSPDR = 0x89;
	SSPDR = (uint8)( pa >> 6);//PA6	
	SSPDR = (uint8)(pa << 2);//BA8
	SSPDR =  0;//BA0

	
	t = SSPSR;
	while( !(t & SSP_TX_FIFO_EMPTY ) ) t = SSPSR;
	
	i = 4;	
	do{
		t = SSPDR;
		i--;
	}while( i );
	
	IOSET = MCS;	
	SSPEnd();
	for( i = 0; i < 8; i++);
	FlashEnd();	
	return;		
}

void at45db_PageErase(uint16 pa)
{

	int i;
	uint8 t;
	FlashStart(FLASH_B,0);
	while( (at45db_Status_reg_read() & 0x80) == 0 ) OSTimeDly(2);
	SSPStart();	
	IOCLR = MCS;

	SSPDR = 0x81;
	SSPDR = (uint8)( pa >> 6);//PA6	
	SSPDR = (uint8)(pa << 2);//BA8
	SSPDR =  0;//BA0

	t = SSPSR;
	while( !(t & SSP_TX_FIFO_EMPTY ) ) t = SSPSR;
	
	i = 4;	
	do{
		t = SSPDR;
		i--;
	}while( i );
	
//	MSPI_SendData((uint8)( pa >> 6));//PA6	
//	MSPI_SendData((uint8)(pa << 2) );//BA8
//	MSPI_SendData(0);//BA0

	IOSET = MCS;		
	SSPEnd();
	for( i = 0; i < 8; i++);
	FlashEnd();
	return;

}

void at45db_BlockErase(uint16 pa)
{
	int i;
	uint8 t;
	FlashStart(FLASH_B,0);
	while( (at45db_Status_reg_read() & 0x80) == 0 ) OSTimeDly(2);
	SSPStart();	
	IOCLR = MCS;

	SSPDR = 0x50;
	SSPDR = (uint8)( pa >> 6);//PA6	
	SSPDR = (uint8)(pa << 2);//BA8
	SSPDR =  0;//BA0

	t = SSPSR;
	while( !(t & SSP_TX_FIFO_EMPTY ) ) t = SSPSR;
	
	i = 4;	
	do{
		t = SSPDR;
		i--;
	}while( i );		
	IOSET = MCS;			
	SSPEnd();
	for( i = 0; i < 8; i++);
	FlashEnd();
	return;

}
void at45db_ChipErase(void)
{
	int i;
	uint8 t;
	FlashStart(FLASH_B,0);
	while( (at45db_Status_reg_read() & 0x80) == 0 ) OSTimeDly(2);
	SSPStart();	
	IOCLR = MCS;
	
	SSPDR = 0xC7;
	SSPDR = 0x94;//PA6	
	SSPDR = 0x80;//BA8
	SSPDR = 0x9a;//BA0

	t = SSPSR;
	while( !(t & SSP_TX_FIFO_EMPTY ) ) t = SSPSR;
	
	i = 4;	
	do{
		t = SSPDR;
		i--;
	}while( i );		
	IOSET = MCS;			
	SSPEnd();
	for( i = 0; i < 8; i++);
	FlashEnd();
	return;

}
void at45db_BufferWrite_PageProg(int id, uint16 pa,uint16 ba,uint8* buf, int nSize)
{
	int j;
	uint8 t;
	FlashStart(FLASH_B,id);
	while( (at45db_Status_reg_read() & 0x80) == 0 ) OSTimeDly(2);
	SSPStart();
	IOCLR = MCS;
	if( id == 1 )
		SSPDR = 0x82;
	else
		SSPDR = 0x85;
		
	SSPDR = (uint8)(pa >> 6);
	SSPDR = (uint8)(pa << 2) + (uint8)(ba >> 8);
	SSPDR = (uint8)ba;


	j = 0;
	while( nSize )
	{
		t = SSPRIS;
		while( !(t & SSP_TX_FIFO_HALF_EMPTY) ) t = SSPRIS;
		if( t & SSP_RX_FIFO_HALF_FULL )
			t = SSPDR;
		SSPDR = buf[j];		
		nSize--;
		j++;
	}
	
	t = SSPSR;
	while( !(t & SSP_TX_FIFO_EMPTY ) ) t = SSPSR;
	
	t = SSPSR;
	while( t & SSP_RX_FIFO_NO_EMPTY )
	{
		t = SSPDR;
		t = SSPSR;
	}
	
//	MSPI_SendData((uint8)( pa >> 6));//PA6	
//	MSPI_SendData((uint8)(pa << 2) + (uint8)(ba >> 8) );//BA8
//	MSPI_SendData((uint8)ba);//BA0
	

	IOSET = MCS;
	SSPEnd();
	for( j = 0; j < 8; j++);
	FlashEnd();
	return;	
	
}