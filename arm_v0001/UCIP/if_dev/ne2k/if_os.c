/*****************************************************************************
* if_os.c - Implementation function library for interface drivers.
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
#ifndef IF_OS_C
#define IF_OS_C

#include "..\..\netconf.h"
#include "..\..\netbuf.h"
#include "..\..\netifdev.h"
#include "if_ne2k.h"
#include "if_os.h"

extern Interface *ne2kEthInterface;

////////////////////////////////////////////////////////////////////////////////
/*
UI32 Ktime(void)
{
    return 0;
}
int diffKtime(UI32 t)
{
    return 0;
}
*/
unsigned char inb(unsigned long port)
{
    return (*(unsigned char *)port);
}
unsigned short inw(unsigned long port)
{
    return (*(unsigned short *)port);
}
void outb(unsigned long port, unsigned char data)
{
	(*(unsigned char *)port) = data;
}
void outw(unsigned long port, unsigned short data)
{
	(*(unsigned short *)port) = data;
}
void disableInterupt(unsigned short intr)
{
	rINTMSK |= BIT_EINT1;//Service available EINT
}
void enableInterupt(unsigned short intr)
{
	rINTMSK &= (~BIT_EINT1);//Service available EINT
}
////////////////////////////////////////////////////////////////////////////////


void Ne2kReceiveEvent(void) 
{
  // Will be called for every packet received by the NIC
  // TO DO: EMPTY PACKETS FROM NIC
  //        You can use Ne2kReceiveReady(...) to verify that a packet is available and
  //        to get the size of the available packet (which is needed!)
  //        Use Ne2kReceive(...) to get the next available packet
  //        Ne2kReceive MUST BE CALLED, SINCE IT HANDLES BUFFER OVERWRITE WARNINGS
  //        Sorry but Ne2kReceive does not (currently) support NBufs.
  //        - so here would be a good place to put the received ethernet packet in NBufs
  //        - and maybe add it to an input queue 
    ne2kEthInterface->rxEventCnt++;

    //printf("Ne2kRecieveEvent\n");
//    ADL_isem_post(ne2kEthInterface->pSemIF);
#ifdef OS_DEPENDENT
	OSSemPost((OS_EVENT*)ne2kEthInterface->pSemIF);
#endif
  //Ne2kReceive(NULL, 0);
}


void Ne2kTransmitEvent(void)
{
//	OSSemPost((OS_EVENT*)ne2kEthInterface->pSemIF);
}

extern NBuf* Ne2kRxPacketInternal(int flush, int length);

NBuf* Ne2kRxPacket(void)
{

    NBuf* inChain;
    UI16 l = 0;
//    l = Ne2kReceiveReady();
//    	printf("Ne2kRxPacket: packet length=%d\n",l);
//		Ne2kReceive(NULL, 0);
    inChain = Ne2kRxPacketInternal(0, l);

    return inChain;
}

#endif
