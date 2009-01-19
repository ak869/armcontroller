/** 
    @file os.h

    Operating system functions used by uCIP.

    Use this as a starting point to adapt uCIP 
    to your own operating system.
*/                                                                                    

#ifndef _OS_H_
#define _OS_H_
#include "config.h"

#define AVOS	0	/** @todo see netchat.c and FIX */

#define HAVE_ANSI_TIME		0
#define HAVE_ANSI_STDIO		0
#define FORCE_16BIT_INT		AVOS
#define INT_MAX				65535
#define ULONG_MAX			(unsigned long)4294967295
#ifdef __IAR_SYSTEMS_ICC
#define COMPILER_BROKEN_BITFIELD	/* does not support char bitfields ?? */
#endif	

/*################## uC/OS ###################*/

#ifndef UINT
#define UINT	unsigned int
#endif
#ifndef ULONG
#define ULONG	unsigned long int
#endif
                 
void msleep(uint16 ms);
void delay(int milliseconds);
LONG diffTime(ULONG time);
long diffJTime(ULONG time);
int clk_stat(void);
ULONG OSTimeGet(void);


/*################## AVOS ###################*/

void panic(char * msg);

/*-------- time management --------*/


/*-------- ANSI time.h ------------*/
#if HAVE_ANSI_TIME==0
#define _TIME_H_
struct tm
{ 
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
	int tm_gmtoff;
	char *tm_zone;
};

ULONG time(ULONG *); 		// placeholder for standard ANSI C time
int gettime(struct tm * time);   /* standard ANSI C */
#endif
#endif /* _OS_H_ */
