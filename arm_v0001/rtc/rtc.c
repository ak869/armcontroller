#include "config.h"
void RTCInit(void)
{
	PREINT = Fpclk / 32768 - 1;
	PREFRAC = Fpclk - (Fpclk / 32768) * 32768;

	CCR = 0;
	
	YEAR = 2008;
	MONTH = 01;
	DOM = 01;
	DOW = 2;
	HOUR = 0;
	MIN = 0;
	
	CCR = 0x1;
	return;
}

uint8 ReadRTC(DATETIME *dat)
{
	uint32 t;
	t = CTIME0;
	dat->timelong.second = t & 0x3f;
	t >>= 8;
	dat->timelong.minute = t & 0x3f;
	t >>= 8;
	dat->timelong.hour = t & 0x1f;
	t >>= 8;
	dat->timelong.weeks = t & 0x7;
	
	t = CTIME1;
	dat->timelong.day = t & 0x1f;
	t >>= 8;
	dat->timelong.month = t & 0xf;
	t >>= 8;
	dat->timelong.year = t & 0x3f;	
	
	return TRUE;
}