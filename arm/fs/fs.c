#include "config.h"


static uint32 log_id;
static uint16 curr_pa;
#define DEVICE_TYPE		0x01234567
#define DEVICE_VER		0x00001001
uint8 calc_crc(uint8 * buf, int nSize)
{
	uint8 chk;
	int i;
	chk = 0;
	for( i = 0; i < nSize; i++)
	{
		chk ^= buf[i]; 
	}
	return chk;
}
void FormatFlash(void)
{
	uint8 buf[36 + 16];
	uint16 pa,ba;
	int i,j,x;
	
	struct tag_doorstatus *pstate;
	struct tag_doorgroup *pgroup;
	struct tag_attrib *pattr;
	
	pattr = (struct tag_attrib *)(buf + GROUP_SIZE);
	pgroup = (struct tag_doorgroup *)buf;
	pstate = (struct tag_doorstatus *)buf;
	
	at45db_ChipErase();
	// other page
	
	// state page
	ba = 0;
	pa = DOOR_STATE_PAGE;
	for( j = 0; j < FULL_DOORS; j++)
	{
		for( i = 0; i < 8; i++)
		{
			pstate->t.hour_start = 0;
			pstate->t.hour_end = 23;
			pstate->t.minute_start = 0;
			pstate->t.minute_end = 59;
			pstate->t.weeks =0x7f;
			pstate->t.other = 0;
			pstate->param = 0;
			if( i == 0 )
				pstate->type = SAFE_TYPE;
			else 
				pstate->type = NONE_TYPE;
			buf[ DOOR_STATE_SIZE - 1] = calc_crc(buf, DOOR_STATE_SIZE - 1);
			at45db_Buffer_Write(2, ba, buf, DOOR_STATE_SIZE);
			ba += DOOR_STATE_SIZE;
		}
		if( ba >= 528 )
		{
			at45db_BuffertoPageNoErase(2, pa);
			pa++;
			ba = 0;
		}
	}
	// group page
	ba = 0;
	pa = GROUP_PAGE;
	for( j = 0; j < FULL_DOORS; j++)
	{
	//attrib
		pattr->megnet = 0;
		pattr->button = 0;
		pattr->feedback = 1;
		pattr->alarm = 0;
		pattr->other = 0;
		pattr->door_submarine = 0;
		pattr->reserved = 0;	
		pattr->link = 0;
		pattr->door_delay = 6;
		pattr->megnet_delay = 6;
		pattr->card_delay = 20;
		pattr->card	= 1;
		ba = 0;		
		for( x = 0; x < 14; x++)
		{	
			for( i = 0; i < 8; i++)
			{
				pgroup->t[i].hour_start = 0;			
				pgroup->t[i].hour_start = 0;
				pgroup->t[i].minute_start = 0;

				if( i == 0 && x == 0) pgroup->t[i].hour_end = 0x23;
				else pgroup->t[i].hour_end = 0;
				if( i == 0 && x == 0) pgroup->t[i].minute_end = 0x59;
				else pgroup->t[i].minute_end = 0;

				pgroup->t[i].weeks = 0x7f;
				pgroup->t[i].other = 0x00;
			}
			pgroup->param = 0;
			pgroup->power = 100;
			buf[GROUP_SIZE - 1] = calc_crc(buf, GROUP_SIZE - 1);
			if( i == 7 )
				at45db_Buffer_Write(2, ba, buf, GROUP_SIZE + ATTRIB_SIZE );
			else
				at45db_Buffer_Write(2, ba, buf, GROUP_SIZE );
			
			ba += GROUP_SIZE;			
		}
		at45db_BuffertoPageNoErase(2, pa);
		pa++;
		
	}	
	
}

void FsInit(void)
{
	uint32 ver;
	at45db_Page_Read( LOG_PAGE - 1, 0, (uint8*)&ver, sizeof(ver) );
	if( ver != DEVICE_TYPE )
	{
		at45db_ChipErase();
		FormatFlash();
		ver = DEVICE_TYPE;
		at45db_BufferWrite_PageProg(2,LOG_PAGE - 1, 0, (uint8*)&ver, sizeof(ver) );
		ver = DEVICE_VER;
		at45db_BufferWrite_PageProg(2,LOG_PAGE - 1, 4, (uint8*)&ver, sizeof(ver) );
	}
	at45db_Page_Read( LOG_PAGE - 1, 4, (uint8*)&ver, sizeof(ver) );
	
/*	if (ver != DEVICE_VER && (ver & 0x00001000)
	{
			
	}
*/	
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

