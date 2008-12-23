#include "config.h"


static uint32 log_id;
static uint16 curr_pa;
#define DEVICE_TYPE		0x01234567
#define DEVICE_VER		0x00001001
void FsInit(void)
{
	uint32 ver;
	at45db_Page_Read( LOG_PAGE - 1, 0, (uint8*)&ver, sizeof(ver) );
	if( ver != DEVICE_TYPE )
		at45db_ChipErase();
	ver = DEVICE_TYPE;
	at45db_BufferWrite_PageProg(2,LOG_PAGE - 1, 0, (uint8*)&ver, sizeof(ver) );
	ver = DEVICE_VER;
	at45db_BufferWrite_PageProg(2,LOG_PAGE - 1, 4, (uint8*)&ver, sizeof(ver) );
}

void LogInit(void)
{
	uint16 pa;
	uint32 id;
	uint16 min_pa,max_pa,ba;	
	
	log_id = 0;
	

//	read id

	pa = LOG_PAGE;
	at45db_Page_Read( pa, 0, (uint8*)&id, 4 );
	log_id = id;
	
	min_pa = LOG_PAGE;
	max_pa = MAX_PAGE_COUNT - 1;
	while( max_pa != min_pa )
	{
		pa = ( (max_pa - min_pa) >> 1 ) + min_pa;	
		at45db_Page_Read( pa, 0, (uint8*)&id, 4 );
		if( log_id > id || id == 0xffffffff )
		{
			max_pa = pa;
		}else
		{
			log_id = id;
			min_pa = pa;
		}
	}
	
	max_pa = (528 - 1) >> 4;
	min_pa = 0;
	while( min_pa != max_pa )
	{
		ba = ( (max_pa - min_pa) >> 1 ) + min_pa;
		at45db_Page_Read( pa, ba * 16, (uint8*)&id, 4 );
		if( id == 0xffffffff )
		{
			max_pa = ba;
		}else
		{
			log_id = id;
			min_pa = ba;
		}	
	}
	
	if( log_id == 0xffffffff )
		log_id = 0;
	curr_pa =( pa & 0x0000ff80 );
}
void LogWrite(uint8 node, uint8 type, uint32 userid, uint32 ntime)
{
	int i;
	struct tag_log log;
	uint32 pa;
	uint16 ba;
	uint8 *t,chk;
	log.id = log_id;
	log.userid = userid;
	log.ntime = ntime;
	log.node = node;
	log.type = type;
	log.reserved = 0;
	t =(uint8 *) &log;
	chk = 0;
	for( i = 0; i < sizeof(struct tag_log) - 1; i++)
	{
		chk ^= t[i];
	}
	log.crc = chk;
	
	//write flash
	ba = log_id % 528;
	pa = log_id / 528;
	pa /= (MAX_PAGE_COUNT - LOG_PAGE);
	
	pa += LOG_PAGE;

	if( (pa & 0x0000ff80) != curr_pa )
	{
		at45db_BlockErase((uint16)pa);
		curr_pa =( pa & 0x0000ff80 );
	}	
	at45db_BufferWrite_PageProg(2, pa, ba, (uint8*)&log, 16);	
	log_id++;	
}
