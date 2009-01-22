/** 
 *  @file os.c
 *
 *  Operating system functions used by uCIP.
 *    
 *  Use this as a starting point to adapt uCIP 
 *  to your own operating system.
 */

#include "os.h"
#include "netos.h"
#include "..\netconf.h"
#include "..\netbuf.h"
#include "..\net.h"




void panic(char * msg)  /* panic message */
{}


// Get system time in jiffys, which is a system clock tick 


int gettime(struct tm * time)
{
	return 0;
}


#if HAVE_ANSI_TIME==0
// This function returns time in seconds since the first call.
// It's used but the ARP protocol in netether.c
// You can remove this if your OS/COMPILER already supports standard ANSI time functions
// or if you don't wish to use the ethernet feature of this stack.
// This functions uses mtime()!
ULONG time(ULONG *returnTime) 
{
  static ULONG timeStorage = 0;
  static ULONG lastTime = 0;
  ULONG newTime;
  ULONG timeDiff;

  if (timeStorage)
  {
    newTime = mtime();

    if (newTime >= lastTime)
      timeDiff = (newTime - lastTime) / 1000;
    else
      timeDiff = (0 - lastTime + newTime) / 1000;

    if (timeDiff >= 1 )
    {
      timeStorage += timeDiff;
      lastTime    += timeDiff * 1000;
    }
  }
  else
  {
    lastTime = mtime();
    timeStorage = 1;
  }

  if (returnTime) *returnTime = timeStorage;
  return timeStorage;
}
#endif

ULONG mtime()
{
    return OSTimeGet() * 10;
}
ULONG jiffyTime(void)
{
	return OSTimeGet();
}
extern u_long tick;
void OSTimeDly(u_short ms)
{
	u_long t;
	t = tick + ms;
	while( tick < t);
}
void msleep(u_short ms)
{
	OSTimeDly(ms * OS_TICKS_PER_SEC / 1000);
}

void delay(int milliseconds){
	OSTimeDly(milliseconds * OS_TICKS_PER_SEC / 1000);
}

LONG diffTime(ULONG time)
{
    return time - OSTimeGet();
}
long diffJTime(ULONG time)
{
	return time - OSTimeGet();
}
int clk_stat(void)
{
	return 0;
}
ULONG OSTimeGet(void)
{
	return tick;
}


/*------ semaphores ------*/
OS_EVENT* OSSemCreate(UWORD value)
{
	return NULL;
}

UWORD OSSemAccept(OS_EVENT *pevent)
{
	return 0;
}

UBYTE OSSemPost(OS_EVENT* pevent)
{
	return 0;
}

void OSSemPend(OS_EVENT* pevent, UWORD timeout, UBYTE* err)
{
	return;
}


/*-------- device I/O --------*/
#define FILE_DESC   int     /* the real one depends on your system */       
#define Nbuf void   /* the real one is defined in netbuf.h */

const char *nameForDevice(int fd) { return "unknown"; }

void nPut(FILE_DESC fd, NBuf * buffer)
{}

void nGet(FILE_DESC fd, NBuf ** buffer, UINT killdelay)  /* !!! check prototype */
{}
