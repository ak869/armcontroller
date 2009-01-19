/*****************************************************************************
* if_ne2k.c - NE2000 specific functions (or simply NE2000 driver)
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
*(yyyy-mm-dd)
* 2001-03-01 Mads Christiansen <mads@mogi.dk>, Partner Voxtream.
*            Original file.
*
* 2001-10-01 Craig Graham <c_graham@hinge.mistral.co.uk>.
*            NBuf's all the way...
*****************************************************************************/
//#include <config.h>
//#include <stdio.h>
//#include <string.h>

#include "../../netconf.h"
#include "../../netbuf.h"

#include "if_os.h"
#include "../../netifdev.h"
#include "if_ne2kr.h"
#include "if_ne2k.h"


// ***** INTERNAL TYPE DEFINES
typedef struct
{
  u_char Status;
  u_char NextPage;
  u_short Length;
} BufferHeader;

typedef union
{
  u_short Word;
  u_char  Uchar[2];
} Word;

// ***** PROTOTYPES

static NBuf *ReadBufferNBuf(BufferHeader *header);
#define ETHER_MIN_LEN 64
#define ETHER_MAX_LEN 1536

// ***** DEFINES
// Interrupt Mask Register Setup
// Packet received, packet sent, receive error, transmit error, buffer overflow
//     No interrupt for counter overflow!
#define IMR IMR_PRXE | IMR_OVWE

// Minimum packet size for the ethernet (this is without the trailing CRC)
#define MIN_PACKET_SIZE 60

// Driver statistics
static Ne2kStatistics Statistics;

// Next packet buffer pointer, used by Ne2kReceive
static u_char NextPacket;

u_char Ne2k_MacAddress[6] = {0x55, 0x55, 0x55, 0x12, 0x34, 0x56};
//extern EthernetAdress myMAC;
int Ne2k_MacAddressSet=0;

/**
 * Override the cards default MAC address
 * @param pointer to a 6byte array containing the MAC address to use
 */
 static u_char Ne2kInitialize(void);
void Ne2kSetMacAddress(const u_char *address)
{
    memcpy(Ne2k_MacAddress,address,6);
    Ne2kInitialize();
}

static u_char Ne2kInitialize(void)
{
    u_char ReadData;
    UINT32 Test0;
    UINT32 Test1;
    int Count;



    // ***** Reset statistics
    memset(&Statistics, 0, sizeof(Statistics));


    // ***** Stop NIC
    OUTPORTB(NIC_CR, CR_STOP | CR_NO_DMA | CR_PAGE0);
    // Do a long wait to let the NIC finish receive/sending
    // THIS IS MANDATORY!
    LONGPAUSE;


    // ***** Detect NIC
    // Write 0x55 to 'Boundary Pointer Register' on page 0
    OUTPORTB(PG0W_BNRY, 0x55);
    PAUSE;


    // Write 0xaa to 'Physical Address Pointer Register2' on page 1
    OUTPORTB(NIC_CR, CR_STOP | CR_NO_DMA | CR_PAGE1);
    PAUSE;
    OUTPORTB(PG1W_PAR2, 0xaa);
    PAUSE;


    // Read 'Boundary Pointer Register' on page 0
    OUTPORTB(NIC_CR, CR_STOP | CR_NO_DMA | CR_PAGE0);
    PAUSE;
    Test0 = INPORTB(PG0R_BNRY);
    PAUSE;


    // Read 'Physical Address Pointer Register2' on page 1
    OUTPORTB(NIC_CR, CR_STOP | CR_NO_DMA | CR_PAGE1);
    PAUSE;
    Test1 = INPORTB(PG1R_PAR2);
    PAUSE;



    // ***** IF NIC is not found THEN RETURN FALSE
    if ((Test0 != 0x55) || (Test1 != 0xaa)) {
//        printf("NIC not found Test0=%lx Test1=%lx\n",Test0,Test1);
        return FALSE;
    }


    // ***** Read NIC's MAC address
    // We want to read MAC address, select transfer mode (word), no loopback, FIFO 4 words
    OUTPORTB(NIC_CR, CR_PAGE0 | CR_NO_DMA | CR_STOP );
    PAUSE;
    OUTPORTB(PG0W_DCR, DCR_FT1 | DCR_LS );
    PAUSE;

    // ***** Reset NIC
    // Stop NS 8390 CHIP, somewhere it states that issuing a read to
    // NIC address + 1fh (NIC_RESET) will issue a reset on the NIC! SO THIS IS DONE!
    ReadData = INPORTB(NIC_RESET);
    // Do a long wait for the 8390 to reset.
    // THIS IS MANDATORY!
    LONGPAUSE;
    OUTPORTB(NIC_RESET, ReadData); // THIS IS DONE IN A PACKET DRIVER ?
    PAUSE;

    // ***********************************************************************************
    // ***** The following initialization procedure is taken from the datasheet
    // ***** DP8390D/NS32490D NIC Network Interface Controller (July 1995) from National
    // ***** Semiconductor.
    // ***** 1. Stop NIC (again...)
    OUTPORTB(NIC_CR, CR_PAGE0 | CR_STOP | CR_NO_DMA );
    // Don't do a longpause, the NIC should already be stopped
    PAUSE;

    // ***** 2. Initialize Data Configuration Register (DCR) to normal operation,
    //          word wide transfer, 4 words FIFO threshold
    OUTPORTB(PG0W_DCR, DCR_FT1 | DCR_LS );
    PAUSE;

    // ***** 3. Clear Remote Byte Count Registers (RBCR0, RBCR1)
    OUTPORTB(PG0W_RBCR0, 0x00);
    PAUSE;
    OUTPORTB(PG0W_RBCR1, 0x00);
    PAUSE;

    // ***** 4. Initialize Receive Configuration Register (RCR) to accept broadcast packets and
    //          packets addressed to this NIC (MAC address).
    // NOTICE THAT SOME NE2000 CLONES HAVE ACCEPT BROADCAST AND ACCEPT MULTICAST BITS HARDWIRED TOGETHER!
    // SO IF YOU SET ONE YOU ALSO SET THE OTHER!
    OUTPORTB(PG0W_RCR, RCR_AB);
    PAUSE;

    // ***** 5. Place the NIC in Loopback Mode 1, internal loopback (Transmit Configuration Register).
    OUTPORTB(PG0W_TCR, TCR_LB0);
    PAUSE;

    // ***** 6. Initialize Page Start Register, Boundary Pointer & Page Stop Register
    OUTPORTB(PG0W_PSTART, RSTART_PG);
    PAUSE;
    OUTPORTB(PG0W_BNRY, RSTART_PG);
    PAUSE;
    OUTPORTB(PG0W_PSTOP, RSTOP_PG);
    PAUSE;

    // ***** 7. Clear Interrupt Status Register (ISR) by writing 0FFh to it..
    OUTPORTB(PG0W_ISR, 0xFF);
    PAUSE;

    // ***** 8. Initialize IMR (Interrupt Mask Register) to accept:
    OUTPORTB(PG0W_IMR, IMR);
    PAUSE;

    // ***** 9. Initialize Physical Address Registers (PAR0-PAR5) (MAC Address)
    // Select PAGE 1
    OUTPORTB(NIC_CR, CR_PAGE1 | CR_NO_DMA | CR_STOP);
    PAUSE;

    // Setup MAC address
    for (Count = 0; Count < 6; Count++) {
        OUTPORTB(PG1W_PAR0 + Count, Ne2k_MacAddress[Count]);
        PAUSE;
    }

    // ***** Initialize Multicast Address Registers to 00h (MAR0-MAR7) (don't accept multicast packets)
    for (Count = 0; Count < 8; Count++) {
        OUTPORTB(PG1W_MAR0 + Count, 0x00);
        PAUSE;
    }
//	OUTPORTB(PG1W_MAR1, 0x41);
//	OUTPORTB(PG1W_MAR3, 0x80);
    // ***** Initialize CURRent pointer to Boundary Pointer + 1
    OUTPORTB(PG1W_CURR, RSTART_PG+1);
    PAUSE;
    NextPacket = RSTART_PG + 1;

    // ***** 10. Start NIC
    OUTPORTB(NIC_CR, CR_PAGE0 | CR_NO_DMA | CR_START);
    PAUSE;

    // ***** 11. Initialize the Transmit Configuration Register for normal operation (out of loopback mode)
    OUTPORTB(PG0W_TCR, 0x00);
    PAUSE;

    // ***** RETURN TRUE
    return TRUE;
}


static u_char Ne2kStop(void)
{
    // ***** Stop NIC
    OUTPORTB(NIC_CR, CR_STOP | CR_NO_DMA | CR_PAGE0);
    PAUSE;

    // ***** Disable interrupts from NIC
    OUTPORTB(PG0W_IMR, 0x00);
    PAUSE;

    // Clear any generated interrupts
    OUTPORTB(PG0W_ISR, 0xff);
    PAUSE;
    return 0;
}



void __irq Ne2kProcessInterrupts(void)
{
    register unsigned char i;
	rI_ISPC = BIT_EINT1;
    // ***** Disable netcard IRQ
    DISABLE_NE2K_IRQ;

    // ***** Disable interrupts from NIC (IMR = 0)
    OUTPORTB(PG0W_IMR, 0x00);
    PAUSE;

    i = INPORTB(PG0R_ISR);

    // ***** WHILE (ISR > 0)
    while ((i = INPORTB(PG0R_ISR)) & 0x1F) {
        PAUSE;

        // ***** ALL INTERRUPTS MUST BE CLEARED
        // ***** (except for OVW, which is cleared when calling Ne2kReceive)

        // ***** IF overwrite warning interrupt THEN
        if (i & ISR_OVW) {
            //printf("nei-OVW\n");
            PAUSE;
            // ***** CALL Ne2kReceiveEvent()
            Ne2kReceiveEvent();
        }
        else PAUSE;

        // ***** IF packet received interrupt THEN
        if (i & ISR_PRX) {
            //printf("nei-Rx\n");
            PAUSE;
            // ***** clear packet received interrupt status bit
            OUTPORTB(PG0W_ISR, ISR_PRX);
            PAUSE;
            // ***** CALL Ne2kReceiveEvent()
            Ne2kReceiveEvent();
        }
        else PAUSE;

        // ***** IF packet transmitted interrupt THEN
        if (i & ISR_PTX) {
            //printf("nei-Tx\n");
            PAUSE;
            // ***** clear packet transmitted interrupt status bit
            OUTPORTB(PG0W_ISR, ISR_PTX);
            PAUSE;
            // ***** CALL Ne2kTransmitEvent()
            Ne2kTransmitEvent();
        }
        else PAUSE;

        // ***** IF receive error interrupt THEN
        
		if (i & ISR_RXE) {
            //printf("nei-4\n");
            PAUSE;
            // ***** clear receive error interrupt status bit
            OUTPORTB(PG0W_ISR, ISR_RXE);
            PAUSE;
            // ***** update receive error statistics
            Statistics.ReceiveErrors++;
        }
        else PAUSE;

        // ***** IF transmit error interrupt THEN
        if (i & ISR_TXE) {
            //printf("nei-5\n");
            PAUSE;
            // ***** clear transmit error interrupt status bit
            OUTPORTB(PG0W_ISR, ISR_TXE);
            PAUSE;
            // ***** update transmit error statistics
            Statistics.TransmitErrors++;
            // ***** CALL Ne2kTransmitEvent()
            Ne2kTransmitEvent();
        }
        else PAUSE;

        /* NETWORK TALLY COUNTERS ARE NOT USED, THEY COULD BE USED FOR MORE PRECISE STATISTICS
        // ***** IF counter overflow interrupt THEN
        if (i & ISR_CNT) {
            PAUSE;
            // ***** clear counter overflow interrupt status bit
            OUTPORTB(PG0W_ISR, ISR_CNT);
            PAUSE;
            // ***** empty tally counters
            INPORTB(PG0R_CNTR0);
            PAUSE;
            INPORTB(PG0R_CNTR2);
            PAUSE;
            INPORTB(PG0R_CNTR3);
            PAUSE;
        }
        else PAUSE;
        */
    }
    // Enabling interrupts again, don't change this order or you might loose interrupts!
    DISABLE_INTERRUPTS;
    ENABLE_NE2K_IRQ;
    SIGNAL_EOI;
    ENABLE_INTERRUPTS;

    // ***** Enable interrupts from NIC (set IMR)
    OUTPORTB(PG0W_IMR, IMR); // If new or pending interrupts from NIC they should be generated here
    PAUSE;
}

u_short Ne2kReceiveReady(void)
{
//  	BufferHeader Header;
/*  	u_char Imr;
  	u_char lastfree,pend;
  	u_char cmd;
  	Word Word;
*/

	return 0;
/*
  // ***** Remember NIC IMR and disable interrupt from NIC (ATOMIC OPERATION!)
  DISABLE_INTERRUPTS;
  // Select PAGE 2
  OUTPORTB(NIC_CR, CR_PAGE2 | CR_NO_DMA | CR_START);
  PAUSE;
  // Read IMR register
  Imr = INPORTB(PG2R_IMR);
  PAUSE;
  // Select PAGE 0 again
  OUTPORTB(NIC_CR, CR_PAGE0 | CR_NO_DMA | CR_START);
  PAUSE;
  // Disable interrupts from NIC
  OUTPORTB(PG0W_IMR, 0x00);
  PAUSE;
  ENABLE_INTERRUPTS;

  // ***** Read the NIC packet header which is 4 bytes
  // ***** IF ReadBuffer(header, NULL, 0) THEN
  if (ReadBuffer(&Header, NULL, 0))
  {
    // ***** Restore NIC IMR
    OUTPORTB(PG0W_IMR, Imr);
    PAUSE;

    // ***** RETURN packet length field in header - 4 (we don't want to count buffer header)
    return Header.Length - 4;
  }

  // ***** Restore NIC IMR
  OUTPORTB(PG0W_IMR, Imr);
  PAUSE;
*/
  // ***** No packets in buffer
  // ***** RETURN FALSE
  return FALSE;
}

/**
 * Recieve packets from the Ne2k
 * @param flush 0=return an NBuf chain containing the data, 1=remove one packet from ring buffer
 * @param length Length of packet to retrieve
 * @return points to start of NBuf chain, or NULL if flushing...
 */
NBuf *Ne2kRxPacketInternal(int flush, int length)
{
    int Success;
    u_char Imr;
//    u_short start;
    BufferHeader Header;
    NBuf *rtn=NULL;
	u_char cmd;


    // ***** IF length > 1514 THEN RETURN FALSE
  if (length > 1514) return FALSE;

    // ***** Remember NIC IMR and disable interrupt from NIC (ATOMIC OPERATION!)
    DISABLE_INTERRUPTS;
    // Select PAGE 2
    OUTPORTB(NIC_CR, CR_PAGE2 | CR_NO_DMA | CR_START);
    PAUSE;
    // Read IMR register
    Imr = INPORTB(PG2R_IMR);
    PAUSE;
    // Select PAGE 0 again
    OUTPORTB(NIC_CR, CR_PAGE0 | CR_NO_DMA | CR_START);
    PAUSE;
    // Disable interrupts from NIC
    OUTPORTB(PG0W_IMR, 0x00);
    PAUSE;
    ENABLE_INTERRUPTS;

    // ***** Success = FALSE;
    Success = FALSE;



  	cmd = INPORTB(NIC_CR);

//				rtn=ReadBufferNBuf(&Header);
//				OUTPORTB(NIC_CR, cmd);

        rtn = ReadBufferNBuf(&Header);
        if (rtn)
        {
            // ***** Remove packet!
            // ***** NextPacket = Header.NextPage;
            NextPacket = Header.NextPage;

            // ***** Initialize Boundary (read) Pointer to the value of NextPacket - 1
            // ***** IF Boundary Pointer < RSTART_PG THEN BNDRY = RSTOP_PG - 1
            if ( (NextPacket - 1) < RSTART_PG )
                    OUTPORTB(PG0W_BNRY, RSTOP_PG - 1);
            else
                    OUTPORTB(PG0W_BNRY, NextPacket - 1);
            PAUSE;

            // ***** Success = TRUE
            Success = TRUE;

            // ***** Update statistics
            Statistics.BytesReceived += Header.Length - 4;

        }
    

    // ***** IF NIC buffer overwrite warning THEN
    if (INPORTB(PG0R_ISR) & ISR_OVW)
    {

				OUTPORTB(PG0W_RBCR0, 0);
				PAUSE;
				OUTPORTB(PG0W_RBCR1, 0);
				PAUSE;
				OUTPORTB(PG0W_TCR, TCR_LB0);
				PAUSE;
				OUTPORTB(PG0W_RCR, RCR_MON);//RCR_AB | RCR_AM
				PAUSE;
				OUTPORTB(NIC_CR, CR_START|CR_NO_DMA);
				PAUSE;
				OUTPORTB(PG0W_RCR, RCR_AB);
				PAUSE;
				OUTPORTB(PG0W_TCR, 0);   	
        PAUSE;

        // ***** 9. Reset the overwrite warning bit in the Interrupt Status Register.
        OUTPORTB(PG0W_ISR, ISR_OVW);
        PAUSE;
        
    }else{
        PAUSE;
    }

    // ***** Restore NIC IMR
    OUTPORTB(PG0W_IMR, Imr);
    PAUSE;
    OUTPORTB(NIC_CR, cmd);
    PAUSE;
    // ***** RETURN Success
    return rtn;
}


static u_short Ne2kTransmitReady(void)
{
  // ***** IF transmitting THEN RETURN FALSE
 	if (INPORTB(NIC_CR) & CR_TXP) return FALSE;
// 	OUTPORTB(NIC_CR, CR_PAGE0 | CR_NO_DMA | CR_START);
//  	if (INPORTB(PG0W_ISR) & ISR_PRX) 
//  	{
//	  	OUTPORTB(PG0W_ISR, ISR_PRX);
//	    PAUSE;
//    }
  // ***** RETURN TRUE
  	return TRUE;
}


int Ne2kTransmit(const u_char *packet, u_short length)
{
  int Timeout, Count;
  u_char Imr;
  u_char CrdaLow, CrdaHigh;

//    printf("Ne2kTransmit\n");

  // ***** IF transmitting THEN RETURN FALSE
  if (!Ne2kTransmitReady()) return FALSE;

  // ***** IF (length < 14) OR (length > 1514) THEN RETURN FALSE
  if ((length < 14) || (length > 1514)) return FALSE;

  // ***** Remember NIC IMR and disable interrupt from NIC (ATOMIC OPERATION!)
  DISABLE_INTERRUPTS;
  // Select PAGE 2
  OUTPORTB(NIC_CR, CR_PAGE2 | CR_NO_DMA | CR_START);
  PAUSE;
  // Read IMR register
  Imr = INPORTB(PG2R_IMR);
  PAUSE;
  // Select PAGE 0 again
  OUTPORTB(NIC_CR, CR_PAGE0 | CR_NO_DMA | CR_START);
  PAUSE;
  // Disable interrupts from NIC
  OUTPORTB(PG0W_IMR, 0x00);
  PAUSE;
  ENABLE_INTERRUPTS;

  // ***** Clear REMOTE DMA COMPLETE bit in ISR
  OUTPORTB(PG0W_ISR, ISR_RDC);
  PAUSE;

  // ***********************************************************************************
  // ***** Due to two non synchronized state machines in the NIC, you should always do a 
  // ***** Remote Read (called a dummy read) before a Remote Write.
  // ***** This is stated in the datasheet DP8390D/NS32490D NIC Network Interface Controller
  // ***** (July 1995) from National  Semiconductor. 

  // ***** 1. Set Remote Byte Count to a value > 0 and Remote Start Address to unused RAM 
  //          (like transmit start page - 1) (REMEMBER THESE VALUES!)
  CrdaLow = 0;
  CrdaHigh = TSTART_PG - 1;

  OUTPORTB(PG0W_RBCR0, 1);
  PAUSE;
  OUTPORTB(PG0W_RBCR1, 0);
  PAUSE;
  OUTPORTB(PG0W_RSAR0, CrdaLow);
  PAUSE;
  OUTPORTB(PG0W_RSAR1, CrdaHigh);
  PAUSE;

  // ***** 2. Issue the "dummy" Remote Read command
  OUTPORTB(NIC_CR, CR_START | CR_DMA_READ);
  PAUSE;

  // ***** 3. Read the current remote DMA address (CRDA) (both bytes)
  // ***** 4. Compare to previous CRDA value, if different go to step 6
  // ***** 5. Delay and go to step 3.
  // timeout < 100 === leave us with appr. 200us timeout (which is a lot)
  // (this timeout is not impl. in NS' datasheet, but it's better to be on the safe side)
  for (Timeout = 0; Timeout < 50; Timeout++)
  {
    if (CrdaLow != INPORTB(PG0R_CRDA0)) break;
    PAUSE;
    if (CrdaHigh != INPORTB(PG0R_CRDA1)) break;
    PAUSE;
  }

  // ***** 6. Setup for the Remote Write command
  // *****     Stop REMOTE DMA 
  OUTPORTB(NIC_CR, CR_START | CR_NO_DMA);
  PAUSE;

  // *****     Initialize Transmit Byte Count Registers to packet length and MIN. MIN_PACKET_SIZE bytes 
  if (length < MIN_PACKET_SIZE)
  { 
    // Padding required
    OUTPORTB(PG0W_TBCR0, MIN_PACKET_SIZE);
    PAUSE;
    OUTPORTB(PG0W_TBCR1, 0);
    PAUSE;
  }
  else
  { 
    // No padding required
    OUTPORTB(PG0W_TBCR0, (length & 0xFF));
    PAUSE;
    OUTPORTB(PG0W_TBCR1, ((length >> 8) & 0xFF) );
    PAUSE;
  }

  // ***** Update statistics (before making length an even value!)
  Statistics.BytesTransmitted += length;
  Statistics.PacketsTransmitted++;

  // *****     We use word transfer mode, so make length an even value
  length &= 0xfffe;
  length++;

  // *****     Initialize Remote Byte Count Register (DMA) to packet length 
  OUTPORTB(PG0W_RBCR0, (length & 0xFF));
  PAUSE;
  OUTPORTB(PG0W_RBCR1, ((length >> 8) & 0xFF));
  PAUSE;

  // *****     Initialize  Remote Start Address Register to address of NIC transmit buffer  
  OUTPORTB(PG0W_RSAR0, 0);
  PAUSE;
  OUTPORTB(PG0W_RSAR1, TSTART_PG);
  PAUSE;

  // ***** 7. Issue the Remote DMA WRITE 
  // *****     Start DMA Write
  OUTPORTB(NIC_CR, CR_START | CR_DMA_WRITE);
  PAUSE;

  // *****     Write data to NIC
//  for (Count = 0; Count < length; Count += 2) OUTPORTW(NIC_DATAPORT, packet[Count] | (packet[Count+1] << 8));
  for (Count = 0; Count < length; Count += 1) OUTPORTB(NIC_DATAPORT, packet[Count]);
  // ***** Wait for Remote DMA to complete (should be instantly, but we have to wait anyway)
  // timeout < 200 === leave us with appr. 200us timeout (which is a lot)
  // (this timeout is not impl. in NS' datasheet, but it's better to be on the safe side)
  for (Timeout = 0; Timeout < 200; Timeout++)
  {
    if (INPORTB(PG0R_ISR) & ISR_RDC) break;
    PAUSE;
  }

  // ***** Clear REMOTE DMA COMPLETE bit in ISR
  OUTPORTB(PG0W_ISR, ISR_RDC);
  PAUSE;

  // ***** Initialize Transmit Page Start Register
  OUTPORTB(PG0W_TPSR, TSTART_PG);
  PAUSE;

  // ***** Start transmission
  OUTPORTB(NIC_CR, CR_START | CR_NO_DMA | CR_TXP);
  PAUSE;

  // ***** Restore NIC IMR
  OUTPORTB(PG0W_IMR, Imr);
  PAUSE;

  // ***** RETURN TRUE
  return TRUE;
}

static void Ne2kTxNBuf(NBuf *pNBuf)
{
    unsigned char *p_d;
    long l;
    int i;
    NBuf *n;

//    printf("TxNBuf:\n");

    n=pNBuf;
    l=pNBuf->len;
    p_d = (unsigned char*)pNBuf->data;
    i=0;
    while(n)
    {
        if(l==0)
        {
            // next nBuf
            n=n->nextBuf;
            if(n)
            {
                l=n->len;
                p_d = (unsigned char*)n->data;
            }
        }else{
            l--;
			OUTPORTB(NIC_DATAPORT, *p_d++);
        }
    }
}

//static u_char dbgseq=1;

static u_char Ne2kTxPacket(NBuf *pNBuf)
{
  int Timeout;
//  int Count;
  u_char Imr;
  u_char CrdaLow, CrdaHigh;
    u_short length;//,padding,lTx;

//    printf("Ne2kTxPacket\n");

    // ***** IF transmitting THEN RETURN FALSE
  if (!Ne2kTransmitReady()) return FALSE;

    length=nChainLen(pNBuf);

//    printf("Ne2kTxPacket: length=%d\n",length);

  // ***** IF (length < 14) OR (length > 1514) THEN RETURN FALSE
  if ((length < 14) || (length > 1514)) return FALSE;

  // ***** Remember NIC IMR and disable interrupt from NIC (ATOMIC OPERATION!)
  DISABLE_INTERRUPTS;
  // Select PAGE 2
  OUTPORTB(NIC_CR, CR_PAGE2 | CR_NO_DMA | CR_START);
  PAUSE;
  // Read IMR register
  Imr = INPORTB(PG2R_IMR);
  PAUSE;
  // Select PAGE 0 again
  OUTPORTB(NIC_CR, CR_PAGE0 | CR_NO_DMA | CR_START);
  PAUSE;
  // Disable interrupts from NIC
  OUTPORTB(PG0W_IMR, 0x00);
  PAUSE;
  ENABLE_INTERRUPTS;

  // ***** Clear REMOTE DMA COMPLETE bit in ISR
  OUTPORTB(PG0W_ISR, ISR_RDC);
  PAUSE;

  // ***********************************************************************************
  // ***** Due to two non synchronized state machines in the NIC, you should always do a
  // ***** Remote Read (called a dummy read) before a Remote Write.
  // ***** This is stated in the datasheet DP8390D/NS32490D NIC Network Interface Controller
  // ***** (July 1995) from National  Semiconductor.

  // ***** 1. Set Remote Byte Count to a value > 0 and Remote Start Address to unused RAM
  //          (like transmit start page - 1) (REMEMBER THESE VALUES!)
  CrdaLow = 0;
  CrdaHigh = TSTART_PG - 1;

  OUTPORTB(PG0W_RBCR0, 1);
  PAUSE;
  OUTPORTB(PG0W_RBCR1, 0);
  PAUSE;
  OUTPORTB(PG0W_RSAR0, CrdaLow);
  PAUSE;
  OUTPORTB(PG0W_RSAR1, CrdaHigh);
  PAUSE;

  // ***** 2. Issue the "dummy" Remote Read command
  OUTPORTB(NIC_CR, CR_START | CR_DMA_READ);
  PAUSE;

  // ***** 3. Read the current remote DMA address (CRDA) (both bytes)
  // ***** 4. Compare to previous CRDA value, if different go to step 6
  // ***** 5. Delay and go to step 3.
  // timeout < 100 === leave us with appr. 200us timeout (which is a lot)
  // (this timeout is not impl. in NS' datasheet, but it's better to be on the safe side)
  for (Timeout = 0; Timeout < 50; Timeout++)
  {
    if (CrdaLow != INPORTB(PG0R_CRDA0)) break;
    PAUSE;
    if (CrdaHigh != INPORTB(PG0R_CRDA1)) break;
    PAUSE;
  }

  // ***** 6. Setup for the Remote Write command
  // *****     Stop REMOTE DMA
  OUTPORTB(NIC_CR, CR_START | CR_NO_DMA);
  PAUSE;

  // *****     Initialize Transmit Byte Count Registers to packet length and MIN. MIN_PACKET_SIZE bytes
  if (length < MIN_PACKET_SIZE)
  {
//        printf("padding: length=%d, actual sent packet=%d\n",length,MIN_PACKET_SIZE);
//        padding=MIN_PACKET_SIZE-length;
//        length=MIN_PACKET_SIZE;

    // Padding required
    OUTPORTB(PG0W_TBCR0, MIN_PACKET_SIZE);
    PAUSE;
    OUTPORTB(PG0W_TBCR1, 0);
    PAUSE;
  }else{
//        padding=0;
//    }
    // No padding required
    OUTPORTB(PG0W_TBCR0, (length & 0xFF));
    PAUSE;
    OUTPORTB(PG0W_TBCR1, ((length >> 8) & 0xFF) );
    PAUSE;
  }

  // ***** Update statistics (before making length an even value!)
  Statistics.BytesTransmitted += length;
  Statistics.PacketsTransmitted++;

  // *****     We use word transfer mode, so make length an even value
  length += length&1;

  // *****     Initialize Remote Byte Count Register (DMA) to packet length
  OUTPORTB(PG0W_RBCR0, (length & 0xFF));
  PAUSE;
  OUTPORTB(PG0W_RBCR1, ((length >> 8) & 0xFF));
  PAUSE;

  // *****     Initialize  Remote Start Address Register to address of NIC transmit buffer
  OUTPORTB(PG0W_RSAR0, 0);
  PAUSE;
  OUTPORTB(PG0W_RSAR1, TSTART_PG);
  PAUSE;

  // ***** 7. Issue the Remote DMA WRITE
  // *****     Start DMA Write
  OUTPORTB(NIC_CR, CR_START | CR_DMA_WRITE);
  PAUSE;

  // *****     Write data to NIC
    Ne2kTxNBuf(pNBuf);

    // send padding
/*    while(padding>0)
    {
        padding-=2;
        OUTPORTW(NIC_DATAPORT,dbgseq);
    }
    dbgseq++;*/
  // ***** Wait for Remote DMA to complete (should be instantly, but we have to wait anyway)
  // timeout < 200 === leave us with appr. 200us timeout (which is a lot)
  // (this timeout is not impl. in NS' datasheet, but it's better to be on the safe side)
  for (Timeout = 0; Timeout < 200; Timeout++)
  {
    if (INPORTB(PG0R_ISR) & ISR_RDC) break;
    PAUSE;
  }

  // ***** Clear REMOTE DMA COMPLETE bit in ISR
  OUTPORTB(PG0W_ISR, ISR_RDC);
  PAUSE;

  // ***** Initialize Transmit Page Start Register
  OUTPORTB(PG0W_TPSR, TSTART_PG);
  PAUSE;

  // ***** Start transmission
  OUTPORTB(NIC_CR, CR_START | CR_NO_DMA | CR_TXP);
  PAUSE;

  // ***** Restore NIC IMR
  OUTPORTB(PG0W_IMR, Imr);
  PAUSE;

  // ***** RETURN TRUE
  return TRUE;
}


void Ne2kGetStatistics(Ne2kStatistics *statistics)
{
  DISABLE_INTERRUPTS;

  // Copy statistics to caller
  memcpy(statistics, &Statistics, sizeof(Statistics));

  ENABLE_INTERRUPTS;
}



/**
 * Read NE2K ring buffer data into an NBuf chain
 */
NBuf * nefetch_nbuf(NBuf *curNBuf, u_short ad, u_short len)
{
	u_char cmd;
	u_short Count;
	u_short countNBuf = 0;
				cmd = INPORTB(NIC_CR);
	
        OUTPORTB(PG0W_RSAR0, (ad & 0xff));
        PAUSE;
        OUTPORTB(PG0W_RSAR1, (ad >> 8)&0xff);
        PAUSE;
        OUTPORTB(PG0W_RBCR0, (len & 0xff));
        PAUSE;
        OUTPORTB(PG0W_RBCR1, (len >> 8)&0xff);
        PAUSE;
        
 				countNBuf =  curNBuf->len;    	

				/* Execute & extract from card */
				OUTPORTB(NIC_CR,  CR_DMA_READ | CR_START);
        for (Count = 0; Count<len; Count+=1)
        {

            if(countNBuf<NBUFSZ)
            {
            		curNBuf->data[countNBuf++] = INPORTB(NIC_DATAPORT);
                curNBuf->len+=1;
            }else{
                do{
                    nGET(curNBuf->nextBuf);
                }while(!curNBuf->nextBuf);
                curNBuf=curNBuf->nextBuf;
                curNBuf->nextBuf=NULL;
                curNBuf->data[0] = INPORTB(NIC_DATAPORT);
                curNBuf->len=1;
                countNBuf=1;
            }
        }	    
				while((INPORTB (PG0R_ISR) & ISR_RDC) == 0) ;
				OUTPORTB(PG0R_ISR, ISR_RDC);	
				OUTPORTB(NIC_CR, cmd);	

 		return curNBuf;	
}
void nefetch (u_char *up, u_short ad, u_short len){
	u_char cmd;
	u_short i;
				cmd = INPORTB(NIC_CR);
	
        OUTPORTB(PG0W_RSAR0, (ad & 0xff));
        PAUSE;
        OUTPORTB(PG0W_RSAR1, (ad >> 8)&0xff);
        PAUSE;
        OUTPORTB(PG0W_RBCR0, (len & 0xff));
        PAUSE;
        OUTPORTB(PG0W_RBCR1, (len >> 8)&0xff);
        PAUSE;
        	

				/* Execute & extract from card */
				OUTPORTB(NIC_CR,  CR_DMA_READ | CR_START);
		    for( i = 0; i < len; i++)
		    {
		    	*up++ = INPORTB(NIC_DATAPORT);		    	
		    }
				while((INPORTB (PG0R_ISR) & ISR_RDC) == 0) ;
				OUTPORTB(PG0R_ISR, ISR_RDC);	
				OUTPORTB(NIC_CR, cmd);
}
/*
void nerecv( NBuf *curNBuf, u_short length)
{

        
 //       countNBuf = length > (DS_PGSIZE - sizeof(*header))?(PG_SIZE - sizeof(*header)):length;        
;			
}
*/
static NBuf *ReadBufferNBuf(BufferHeader *header)
{
 //   u_char Save_curr;
//    Word Word;
    int countNBuf;
    NBuf *curNBuf = NULL,*head = NULL;
    u_char pend, lastfree;
    u_short  length,start;

    //printf("ReadBufferNBuf(header=%p,length=%d)\n",header,length);

    // ***** Clear REMOTE DMA COMPLETE bit in ISR
    OUTPORTB(PG0W_ISR, ISR_RDC);
    PAUSE;

    // ***** Make length an even value

    // ***** Read CURR
    // Read Current Page of rcv ring
    // Go to page 1
  	OUTPORTB(NIC_CR, CR_PAGE1 | CR_NO_DMA | CR_START);
  	PAUSE;
		pend = INPORTB(PG1R_CURR);
		PAUSE;
		OUTPORTB(NIC_CR, CR_PAGE0 | CR_NO_DMA | CR_START);
		PAUSE;
		lastfree = INPORTB(PG0R_BNRY);
		PAUSE;

		/* Have we wrapped? */
		if (lastfree >= RSTOP_PG)
			lastfree = RSTART_PG;
		if (pend < lastfree && NextPacket < pend)
			lastfree = NextPacket;
		else
			if (NextPacket > lastfree)
				lastfree = NextPacket;
	


    // Go to page 0
    OUTPORTB(NIC_CR, CR_START | CR_NO_DMA | CR_PAGE0);
    PAUSE;

//    printf("NextPacket=%x Save_curr=%x\n",NextPacket,Save_curr);

    // ***** LOOP WHILE CURR <> NextPacket  - While we have a packet in buffer
    while (pend != lastfree)
    {
//       printf("NextPacket=%x, setting up DMA read\n",NextPacket);
			u_char nxt;
	        // Setup Remote Byte Counts and Remote Start Address to read length + 4 bytes for buffer header
			nefetch((u_char *)header, lastfree * PG_SIZE, sizeof(*header));
			length = header->Length;
	        // ***** Issue the Remote Read command
			start = lastfree*PG_SIZE+sizeof(*header);
			if (!(header->Status == RSR_PRX ||		/* for dequna's */
				header->Status == 0x21))
				goto exitrecv;	
			if(length < ETHER_MIN_LEN || length > ETHER_MAX_LEN)
				goto exitrecv;
	    
	    do{
	    	nGET(curNBuf);
	    }while(!curNBuf);
	
	    countNBuf = 0;
	    curNBuf->len = 0;
	    curNBuf->nextBuf = NULL;
	    head = curNBuf;
	    head->chainLen = length;
	    head->nextChain = NULL;

	  	curNBuf = nefetch_nbuf(curNBuf, start, (length > (PG_SIZE - sizeof(*header))?(PG_SIZE - sizeof(*header)):length) );
	       	
			if (length > PG_SIZE - sizeof(*header)) 
			{
				int l = length - (PG_SIZE-sizeof(*header)) ;
		
				if(++NextPacket > 0x7f) 
					NextPacket = 0x46;
					
				start = NextPacket*PG_SIZE;
						
				while (l >= PG_SIZE) {
					curNBuf = nefetch_nbuf(curNBuf, start, PG_SIZE);
					l -= PG_SIZE;
					if(NextPacket >= RSTOP_PG) NextPacket = RSTART_PG;
					start = NextPacket*PG_SIZE;
				}
				if (l > 0)
	//				nefetch(p, start, l);
					curNBuf = nefetch_nbuf(curNBuf, start, l);
			}
exitrecv:			
				nxt = header->NextPage ;
			
				/* Sanity check */
				if ( nxt >= RSTART_PG && nxt < RSTOP_PG && nxt <= pend)
					NextPacket = nxt;
				else	
					NextPacket = nxt = pend;
			
						/* Set the boundaries */
				lastfree = nxt;
				OUTPORTB(PG0W_BNRY, nxt);
				OUTPORTB(NIC_CR, CR_START|CR_NO_DMA|CR_PAGE1);
				pend = INPORTB(PG1R_CURR);
				OUTPORTB(NIC_CR, CR_START|CR_NO_DMA|CR_PAGE0);
		    OUTPORTB(PG0W_ISR, ISR_RDC);
		    PAUSE;	
		    if(head)
		    	break;	
		
		}
		OUTPORTB(NIC_CR, CR_START|CR_NO_DMA|CR_PAGE0);
		return head;	
}


u_char Ne2kStart(void)
{
    return Ne2kInitialize();
}

static u_char statistics(if_statistics* pStats)
{
    return FALSE;
}

static void ProcessISQ(Interface* pInterface)
{
}

Interface *ne2kEthInterface;

extern NBuf *Ne2kRxPacket(void);

u_char Ne2k_DriverEntry(Interface* pInterface)
{
    pInterface->start = Ne2kStart;
    pInterface->stop = Ne2kStop;
    pInterface->receive = Ne2kRxPacket;
    pInterface->receive_ready = Ne2kReceiveReady;
    pInterface->transmit = Ne2kTxPacket;
    pInterface->transmit_ready = Ne2kTransmitReady;
    pInterface->statistics = statistics;
    pInterface->interrupt = ProcessISQ;
    ne2kEthInterface=pInterface;

    return 0;
}
