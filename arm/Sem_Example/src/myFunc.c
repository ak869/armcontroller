#define IN_MYMATH

#include "config.h"
 
//OS_EXT  INT32U  OSTime;
uint32 GetOSPrioCur(void)
{
    return OSPrioCur;
}

uint32 GetOSTime(void)
{
	return OSTime;
}