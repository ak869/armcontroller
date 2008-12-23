#include "config.h"


static uint32 log_id;
static uint16 curr_pa;
void LogInit(void)
{
	uint32 pa;
/*
	read id
*/
	log_id = 0;
	
	pa = log_id / 528;
	pa /= (MAX_PAGE_COUNT - LOG_PAGE);
	
	pa += LOG_PAGE;
	
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

