#include "config.h"

void debug_print(uint8 dat)
{
#ifdef DEBUG
#if DEBUG == 1

	U0THR = dat;
	while ((U0LSR & 0x40) == 0);

#else

	U1THR = dat;
	while ((U1LSR & 0x40) == 0);

#endif
#endif
}