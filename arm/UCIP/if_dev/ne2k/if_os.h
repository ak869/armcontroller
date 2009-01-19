/*****************************************************************************
* if_os.h - Implementation function library for interface drivers.
*
* portions Copyright (c) 2001 by Partner Voxtream A/S.
*
* The authors hereby grant permission to use, copy, modify, distribute,
* and license this software and its documentation for any purpose, provided
* that existing copyright notices are retained in all copies and that this
* notice and the following disclaimer are included verbatim in any 
* distributions. No written agreement, license, or royalty fee is required
* for any of the authorized uses.
*
* THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS *AS IS* AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
* IN NO EVENT SHALL THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
* THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
* REVISION HISTORY (please don't use tabs!)
*
*(dd-mm-yyyy)
* 01-03-2001 Mads Christiansen <mc@voxtream.com>, Partner Voxtream.
*            Original file.
*
*****************************************************************************/

#ifndef IF_OS_H
#define IF_OS_H

#include "os.h"
#include "crt.h"

typedef unsigned short UI16;
typedef unsigned long   UI32;


#ifndef UCHAR
typedef unsigned char UCHAR;
#endif

#ifndef UINT32
typedef unsigned int UINT32;
#endif

//#ifndef USHORT
//typedef unsigned short USHORT;
//#endif

#ifndef NULL
#define NULL ((void *) 0)
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

// ***** MACROS
// Add 1 us delay routine here if required by NIC (it is required by the old NS' DP8390)
// This delay might not be required by newer NE2000 compatible NIC's
//#define PAUSE {int __f,__k=1; for(__f=0; __f<50; __f++) __k+=rand(); }
#define PAUSE {}
// Add 1.6 ms delay routine here
#define LONGPAUSE { 	UI32 t=Ktime();	while(diffKtime(t)<1 && diffKtime(t) > -1 ); }

#define INPORTB(port)           inb(port)
#define INPORTW(port)           inw(port)
#define OUTPORTB(port, data)    outb((port),(data))
#define OUTPORTW(port, data)    outw((port),(data))

#define DISABLE_INTERRUPTS      
#define ENABLE_INTERRUPTS       

#ifndef INT_GENIO
#define INT_GENIO 0
#endif
#define DISABLE_NE2K_IRQ        disableInterupt(INT_GENIO)
#define ENABLE_NE2K_IRQ         enableInterupt(INT_GENIO)
//#define DISABLE_NE2K_IRQ
//#define ENABLE_NE2K_IRQ
#define SIGNAL_EOI              


#define	Ktime()	jiffyTime()
#define diffKtime(t)	diffJTime(t)
long diffJTime(ULONG time);
unsigned char inb(unsigned long port);
unsigned short inw(unsigned long port);
void outb(unsigned long port, unsigned char data);
void outw(unsigned long port, unsigned short data);
void disableInterupt(unsigned short intr);
void enableInterupt(unsigned short intr);

void Ne2kReceiveEvent(void);
void Ne2kTransmitEvent(void);


#endif
