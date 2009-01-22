/**
 * UDP Protocol Support for uC/IP.
 *
 * Copyright (c) 2001 by Intelligent Systems Software (UK) Ltd.  All rights reserved.
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
 ******************************************************************************
 * REVISION HISTORY
 *
 * 02-02-2001 Craig Graham <c_graham@hinge.mistral.co.uk>,Intelligent Systems Software (UK) Ltd
 *  First Version. Not based on anything really except RFC 768 (and Guy Lancaster's TCP
 *      protocol implementation as a basis for the checksum stuff).
 *(yyyy-mm-dd)
 * 2001-06-27 Robert Dickenson <odin@pnc.com.au>, Cognizant Pty Ltd.
 *      Added support for static array of UDP_QUEUE* removing dependancy on 
 *      malloc and free for all the usual reasons.
 * 2001-09-10 Mads Lind Christiansen <mc@voxtream.com>, Partner Voxtream
 *      Fixed UDP checksum problems and more.
 *      The UDP module should now be up and running.
 * 02-01-2002 Craig Graham <c_graham@hinge.mistral.co.uk>,Intelligent Systems Software (UK) Ltd
 *      Bugfixes, now works much more reliably (I've had networked Bomberman running over it
 *      as client and server, and it works fine).
 ******************************************************************************
 * NOTES
 *  This probably isn't very good, but it does work (at least well enough to support DNS lookups,
 *  which is what I wanted it for).
 *
 */
#include "netconf.h"
#include "net.h"
#include "nettimer.h"
#include "netbuf.h"
#include "netrand.h"
#include "netip.h"
#include "netiphdr.h"
#include "netudp.h"
#include "neticmp.h"

#include "netdebug.h"
#include "netos.h"

////////////////////////////////////////////////////////////////////////////////

/** Maximum number of udp connections at one time */
#define MAXUDP          4
#define FUDP_OPEN       1
#define FUDP_CONNECTED  2
#define FUDP_LISTEN     4
#define MAXUDPQUEUES    20

/*
#ifdef DEBUG_UDP
#define UDPDEBUG(A) printf A
#else
#define UDPDEBUG(A)
#endif
 */

/** Dump an nBuf chain */
#define DUMPCHAIN(A) {\
        NBuf* p;\
        int i; \
        for (p = (A); p; p = p->nextBuf) {\
            for (i = 0; i < p->len; i++) {\
                if ((i & 3)==0)\
                    UDPDEBUG(("\n[%d]:", i));\
                    UDPDEBUG(("0x%x,",p->data[i]));\
            }\
        }\
        UDPDEBUG(("\n"));\
    }

/**
 * Queue of incoming datagrams.
 * This maintains a list of nBuf chains, along with the source address and port they came from
 * to allow reponses to be sent to multiple peers from one unconnected socket
 */
typedef struct _udp_queue {
    /** Pointer to next chain */
    struct _udp_queue* next;
    /** Source address for this chain (machine byte order) */
    struct in_addr srcAddr;
    /** Source port for this chain (machine byte order) */
    u_int16_t srcPort;
    /** pointer to the head of the actual nBuf chain */
    NBuf* nBuf;
} UDP_QUEUE;

/**
 * UDP port control block
 */
typedef struct {
    unsigned long flags;
    /** incoming data semaphore (value is number of UDP_QUEUE's from head) */
    OS_EVENT* sem;
    /** accept address (network byte order) */
    struct in_addr acceptFromAddr;
    /** send to address (network byte order) */
    struct in_addr theirAddr;
    /** sendto/recvfrom port (network byte order) */
    u_int16_t theirPort;
    /** port number on local machine (network byte order) */
    u_int16_t ourPort;
    /** type of service */
    u_int16_t tos;
    /** Head of the queue of incoming datagrams */
    UDP_QUEUE* head;
    /** Last incoming datagram in the queue */
    UDP_QUEUE* tail;

#if ONETASK_SUPPORT > 0
  // When running in a single task, we want to use callback functions...
  void (*receiveEvent)(int ud, u_int16_t bytes);               /* Called when new data has arrived */
#endif

} UDPCB;

static UDPCB udps[MAXUDP];
static UDP_QUEUE udpqs[MAXUDPQUEUES];
static UDP_QUEUE* udp_free_list;

/** Port number auto-assigned by udpConnect if you've not already bound the socket when you connect it */
static int randPort = 0x0507;

UDP_QUEUE* alloc_udp_q(void)
{
//    return (UDP_QUEUE*)malloc(sizeof(UDP_QUEUE));
    UDP_QUEUE* q = NULL;
    if (udp_free_list != NULL) {
        q = udp_free_list;
        udp_free_list = udp_free_list->next;
    }
    return q;
}

void free_udp_q(UDP_QUEUE* q)
{
//    free(q);
    q->srcPort = 0;
    q->next = udp_free_list;
    udp_free_list = q;
}

void udpInit(void)
{
    int i;
    UDPDEBUG(("udpInit()\n"));
    for (i = 0; i < MAXUDP; i++) {
        udps[i].flags = 0;
        udps[i].sem = OSSemCreate(0);
    }
    udp_free_list = NULL;
    for (i = MAXUDPQUEUES; i--; ) {
        free_udp_q(&udpqs[i]);
    }
}



#if ONETASK_SUPPORT > 0
int udpOpen(void (*receiveEvent)(int ud, u_int16_t bytes))
#else
int udpOpen(void)
#endif
{
    int i;
    UDPDEBUG(("udpOpen()\n"));
    OS_ENTER_CRITICAL();
    for (i = 0; (i < MAXUDP) && (udps[i].flags & FUDP_OPEN); i++);
    if (i == MAXUDP) {
        OS_EXIT_CRITICAL();
        return -1;
    }
    udps[i].flags |= FUDP_OPEN;
    udps[i].ourPort = udps[i].theirPort = 0;
    udps[i].theirAddr.s_addr[0] = udps[i].theirAddr.s_addr[1] = udps[i].theirAddr.s_addr[2] = udps[i].theirAddr.s_addr[3] = 0xff;
    udps[i].acceptFromAddr.s_addr[0] = udps[i].acceptFromAddr.s_addr[1] = udps[i].acceptFromAddr.s_addr[2] = udps[i].acceptFromAddr.s_addr[3] = 0xff;   /* Default to not accepting any address stuff */
    udps[i].head = udps[i].tail = NULL;
	
	#if ONETASK_SUPPORT > 0
	udps[i].receiveEvent = receiveEvent;
	#endif

    OS_EXIT_CRITICAL();
    return i;
}

int udpClose(int ud)
{
    if (!(udps[ud].flags & FUDP_OPEN)) return -1;
    udps[ud].flags = 0;
    return 0;
}

int udpConnect(u_int ud, const struct sockaddr_in *remoteAddr, u_char tos)
{
    if (!(udps[ud].flags & FUDP_OPEN)) return -1;
    udps[ud].acceptFromAddr = udps[ud].theirAddr = remoteAddr->sin_addr;
    udps[ud].theirPort = htons(remoteAddr->sin_port);
    udps[ud].tos = tos;
    if (udps[ud].ourPort == 0)
        udps[ud].ourPort = htons(randPort++);
    udps[ud].flags |= FUDP_CONNECTED;
    return 0;
}

int udpListen(u_int ud, int backLog)
{
    if (!(udps[ud].flags & FUDP_OPEN)) return -1;
    udps[ud].flags |= FUDP_LISTEN;
    return 0;
}

int udpBind(u_int ud, struct sockaddr_in* peerAddr)
{
    UDPDEBUG(("udpBind(%d,%lx)\n",ud,peerAddr));
    if (!(udps[ud].flags & FUDP_OPEN)) return -1;
    udps[ud].acceptFromAddr = peerAddr->sin_addr;
    // TODO: work out whether we should do the htons or the client ???
    udps[ud].ourPort = peerAddr->sin_port;
//    udps[ud].ourPort = htons(peerAddr->sin_port);
    return 0;
}

int udpRead(u_int ud, void* buf, long len)
{
    unsigned char* d;
    int rtn;
    NBuf* b;
    UDP_QUEUE* q;
    struct in_addr fromAddr;
    UBYTE err;

//    TRACE("udpRead(%d,%p,%ld)\n",ud,buf,len);

    if (!(udps[ud].flags & FUDP_OPEN)) return -1;
    d = (unsigned char*)buf;
    rtn = 0;
    OSSemPend(udps[ud].sem, 0, &err);
    if (udps[ud].head == NULL) {
        return -1;
    }
    fromAddr = udps[ud].theirAddr = udps[ud].head->srcAddr;
    udps[ud].theirPort = udps[ud].head->srcPort;

    UDPDEBUG(("fromAddr.s_addr = %08X,   udps[ud].head->srcAddr.s_addr = %08X\n", fromAddr.s_addr, udps[ud].head->srcAddr.s_addr));

    while ((udps[ud].head) && (len) && (fromAddr.s_addr == udps[ud].head->srcAddr.s_addr)) {
        // Get next nBuf
        b = udps[ud].head->nBuf;
        // While we have more buffer to copy out to AND
        // We have a queued nBuf
        while ((len) && (b)) {
        // While we have more buffer space to copy to AND
        // nBuf is not empty
//            while ((len) && (b->data != &b->body[b->len])) {
            while ( (len) && (b->len) )	{
		// Copy one byte
                *d++ = *b->data++;
                b->len--; 
                len--;
                rtn++;
            }
	    // If nBuf is empty
//            if (b->data == &b->body[b->len]) {
            if (!b->len) {
                OS_ENTER_CRITICAL();
                b = udps[ud].head->nBuf = nFree(b);
                OS_EXIT_CRITICAL();
            }
        }
        // If nBuf was freed (we need another one if any)
        if (b == NULL) {
            // Get next nBuf in queue
            q = udps[ud].head;
            OS_ENTER_CRITICAL();
            udps[ud].head = q->next;
            OS_EXIT_CRITICAL();
            free_udp_q(q);
            #if ONETASK_SUPPORT > 0
            #else
            if (udps[ud].head)
                OSSemPend(udps[ud].sem, 0, &err);
            #endif
        } else {
            #if ONETASK_SUPPORT > 0
            // nBuf was not freed but we have filled our buffer (buf) 
            return rtn;
            #else
            OSSemPost(udps[ud].sem);
            #endif
        }
    }
    if (udps[ud].head == NULL)
        udps[ud].tail = NULL;
    return rtn;
}

int udpPoll(int ud)
{
    if(udps[ud].head)
        return 1;
    else
        return 0;
}

void udpUnblockRead(u_int ud)
{
    OSSemPost(udps[ud].sem);
}

#if 1

int udpWrite(u_int ud, const void* buf, long len)
{
    NBuf* pNBuf;
    IPHdr* ipHdr;
    UDPHdr* udpHdr;
    long rtn = 0;
    long copied;
    u_int mtu;

    UDPDEBUG(("udpWrite()\n"));
    if (!(udps[ud].flags & FUDP_OPEN)) return -1;
    mtu = ipMTU(ntohl(udps[ud].theirAddr.s_addr));
    if (!mtu) {
        UDPDEBUG(("no route to host\n"));
        return -1;
    }
    while (len) {
        pNBuf = NULL;
#if ONETASK_SUPPORT > 0
		// We can't do a loop forever in a onetask OS
        nGET(pNBuf);
		// No more nBuf buffers available, should return what we have copied so far
		if (!pNBuf) return rtn;
#else
		// BUSY WAITING! (not nice)
        do {
            nGET(pNBuf);
        } while (pNBuf == NULL);
#endif
		// Reserve room for headers 
		pNBuf->len = pNBuf->chainLen = sizeof(IPHdr) + sizeof(UDPHdr);

		// Add payload
		copied = nAppend(pNBuf, (const char *)&((unsigned char *)buf)[rtn], MIN(mtu - sizeof(IPHdr) - sizeof(UDPHdr), len));
		if (copied && pNBuf) {
			len -= copied;
			rtn += copied;

			// Setup IP header and prepare it so we can compute the UDP checksum
			// Use the IP header as UDP pseudo header
			ipHdr = nBUFTOPTR(pNBuf, IPHdr *);
			memcpy(ipHdr->ip_src.s_addr, (u_char*)&localHost,4);	//db change
			//my change
			memcpy(ipHdr->ip_dst.s_addr, udps[ud].theirAddr.s_addr, 4);// db change
			ipHdr->ip_ttl = 0;
			ipHdr->ip_p = IPPROTO_UDP;
	        ipHdr->ip_sum = htons(copied + sizeof(UDPHdr));

			// Build the UDP header 
			udpHdr = (void *)(ipHdr + 1);
			udpHdr->srcPort = udps[ud].ourPort;
			udpHdr->dstPort = udps[ud].theirPort;
			udpHdr->checksum = 0;
            udpHdr->length = ipHdr->ip_sum;

			// Compute UDP header checksum
	        udpHdr->checksum = inChkSum(pNBuf, pNBuf->chainLen - 8, 8);

			// Build IP header
			// db change
			ipHdr->ip_hl_v = ((sizeof(IPHdr) >> 2) & 0x0f) | (4 << 4);
//			ipHdr->ip_hl = sizeof(IPHdr) >> 2;
			ipHdr->ip_tos = udps[ud].tos;
	        ipHdr->ip_len = copied + sizeof(IPHdr) + sizeof(UDPHdr);
			ipHdr->ip_id = IPNEWID();
			ipHdr->ip_off = 0;
	        ipHdr->ip_ttl = UDPTTL;
			ipHdr->ip_sum = 0;
			ipHdr->ip_sum = inChkSum(pNBuf, sizeof(IPHdr), 0);
		} else {
			// Nothing copied ?!? This can only happen if nBuf size is eq. to sizeof(IPHdr) + sizeof(UDPHdr)
			// AND there are no more buffers free
			// This situation isn't actually handled! But we will free nBuf anyway
			nFreeChain(pNBuf);
		}

        UDPDEBUG(("-src=%s port %ld dest=%s port=%ld\n", \
            ip_ntoa((ipHdr->ip_src.s_addr)),   \
            htons(udpHdr->srcPort),                     \
            ip_ntoa2((ipHdr->ip_dst.s_addr)),  \
            htons(udpHdr->dstPort)                      \
            ));

        // Pass the datagram to IP and we're done. 
				if (pNBuf) ipRawOut(pNBuf);
    }
    return rtn;
}

#endif

long udpRecvFrom(int ud, void* buf, long len, struct sockaddr_in* from)
{
    long rtn;

    UDPDEBUG(("udpRecvFrom()\n"));
    if (!(udps[ud].flags & FUDP_OPEN)) return -1;
    rtn = udpRead(ud, buf, len);
    if (rtn < 0) return rtn;
    from->sin_family = AF_INET;
    memcpy( from->sin_addr.s_addr, udps[ud].theirAddr.s_addr, 4);// db change
    from->sin_port = htons(udps[ud].theirPort);
    return rtn;
}

long udpSendTo(int ud, const void* buf, long len, const struct sockaddr_in* to)
{
    long rtn;

    UDPDEBUG(("udpSendTo()\n"));
    if (!(udps[ud].flags & FUDP_OPEN)) return -1;
    memcpy(udps[ud].theirAddr.s_addr, to->sin_addr.s_addr, 4);
    udps[ud].theirPort = htons(to->sin_port);
    if (udps[ud].ourPort == 0)
        udps[ud].ourPort = htons(randPort++);
    rtn = udpWrite(ud, buf, len);
    return rtn;
}

static UDPCB* udpResolveIncomingUDPCB(u_long srcAddr, u_int16_t port)
{
    int i;

    for (i = 0; (i < MAXUDP); i++) {
        if ((udps[i].flags & FUDP_OPEN) && 
            (udps[i].ourPort == port) &&
           ((udps[i].acceptFromAddr.s_addr == 0) ||
            (ntohl(udps[i].acceptFromAddr.s_addr) == srcAddr)))// db change
            return &udps[i];
    }
    return NULL;
}


////////////// CHECKSUM DEBUG STUFF  (can be removed later) ////////////////////////////////////////////////////
#if DEBUG_SUPPORT > 0			
u_int16 CalcChkSum(u_int16* addr, u_int16 count, u_int16 initial)
{
    register unsigned long sum;

    sum = initial;
    while (count > 1) {
        sum += (*addr++);
        count -= 2;
    }
    // Add left over byte if any
    if (count > 0) {
        sum += *(FAR u_char*)addr;
    }
    while (sum >> 16) {
        sum = (sum & 0xffff) + (sum >> 16);
    }
    return (u_int16)(~sum);
}

typedef struct {
	struct	in_addr ih_src;
	struct	in_addr ih_dst;
	u_char Zero;
	u_char Protocol;
	u_int16 Length;
} PseudoHdr;


u_int16 CalcPseudoHdr(FAR IPHdr* IPPtr, u_int16 Length)
{
    PseudoHdr   PsHdr;
    memcpy(&PsHdr.ih_src, &IPPtr->ip_src, sizeof(struct	in_addr));
    memcpy(&PsHdr.ih_dst, &IPPtr->ip_dst, sizeof(struct	in_addr));
    PsHdr.Zero = 0;
    PsHdr.Protocol = IPPtr->ip_p;
    PsHdr.Length = Length;
//    return ~CalcChkSum((u_int16*)&PsHdr, 12, 0);  // Return the checksum of the pseudo header
    return ~CalcChkSum((void *)&PsHdr, 12, 0);  // Return the checksum of the pseudo header
}

u_int16 ToInt(u_int16 Indata)
{
    u_int16 swapped = (LOBYTE(Indata) << 8) | (HIBYTE(Indata));
    return swapped;
}

void RxUdp(NBuf* pNBuf)
{
    u_int16 UDPLength;
    u_int16 UDPChkSum;
    u_int16 ChkSum;
    UDPHdr* pUDPHdr = (UDPHdr*)(nBUFTOPTR(pNBuf, char*) + sizeof(IPHdr));
    IPHdr* pIPHdr = (IPHdr*)(nBUFTOPTR(pNBuf, char*));
    
    UDPLength = ntohs(pUDPHdr->length);
    UDPChkSum = pUDPHdr->checksum;
    pUDPHdr->checksum = 0;

    // First we evaluate the checksum to see if it is OK.
    ChkSum = CalcPseudoHdr(pIPHdr, pUDPHdr->length);
//    ChkSum = CalcChkSum((FAR u_int16*)pUDPHdr, UDPLength, ChkSum);
    ChkSum = CalcChkSum((void *)pUDPHdr, UDPLength, ChkSum);
    if (ChkSum != UDPChkSum) {
        TRACE("RxUdp(%p) FAIL", pNBuf);
    } else {
        TRACE("RxUdp(%p) PASS", pNBuf);
    }
    TRACE("  UDPChkSum: %04X ChkSum:%04X\n", UDPChkSum, ChkSum);
    pUDPHdr->checksum = UDPChkSum;
}
#endif
////////////////////////////////////////////////////////////////////////////////

void udpInput(NBuf* inBuf, u_int ipHeadLen)
{
    IPHdr* ipHdr;               /* Ptr to IP header in output buffer. */
    UDPHdr* udpHdr;             /* Ptr to UDP header in output buffer. */
    UDPCB* udpCB;
    u_int16_t recv_chkSum,calc_chkSum;

    ipHdr = nBUFTOPTR(inBuf, IPHdr*);
    UDPDEBUG(("udpInput()\n"));
  //  DUMPCHAIN(inBuf);
    if (inBuf == NULL) {
        UDPDEBUG(("udpInput: Null input dropped\n"));
        return;
    }

    /*
     * Strip off the IP options.  The UDP checksum includes fields from the
     * IP header but without the options.
     */
    if (ipHeadLen > sizeof(IPHdr)) {
        inBuf = ipOptStrip(inBuf, ipHeadLen);
        ipHeadLen = sizeof(IPHdr);
    }

    /*
     * Get IP and UDP header together in first nBuf.
     */
    if (inBuf->len < sizeof(UDPHdr) + sizeof(IPHdr)) {
        if ((inBuf = nPullup(inBuf, sizeof(UDPHdr) + ipHeadLen)) == 0) {
            UDPDEBUG(("udpInput: Runt packet dropped\n"));
            return;
        }
    }
    ipHdr = nBUFTOPTR(inBuf, IPHdr*);

    /*
     * Note: We use ipHeadLen below just in case we kept an option with
     *  the IP header.
     */
    udpHdr = (UDPHdr*)((char*)ipHdr + ipHeadLen);
//my change
    UDPDEBUG(("src=%s port %ld dest=%s port=%ld\n", \
        ip_ntoa(ipHdr->ip_src.s_addr),   \
        htons(udpHdr->srcPort),                     \
        ip_ntoa2(ipHdr->ip_dst.s_addr),  \
        htons(udpHdr->dstPort)                      \
        ));
    UDPDEBUG(("length=%d\n",htons(udpHdr->length)));
//    UDPDEBUG(("checksum=%04X\n", htons(udpHdr->checksum)));
//    UDPDEBUG(("nbuf_chkSum=%04X\n", udpHdr->checksum));

    /* Save the received checksum for validating the packet */
//    recv_chkSum = htons(udpHdr->checksum);
    recv_chkSum = udpHdr->checksum;
    udpHdr->checksum = 0;

    /*
     * Prepare the header for the UDP checksum.
     */
    ipHdr->ip_ttl = 0;
//    ipHdr->ip_sum = htons(ipHdr->ip_len - sizeof(IPHdr));
//    ipHdr->ip_sum = htons(ipHdr->ip_len) - sizeof(IPHdr);
    ipHdr->ip_sum = udpHdr->length;

    /* Calculate the checksum on the packet */
//    calc_chkSum = inChkSum(inBuf, inBuf->chainLen - 8, 8);
//    calc_chkSum = inChkSum(inBuf, inBuf->len - 8, 8);
//    calc_chkSum = inChkSum(inBuf, ntohs(udpHdr->length) + 12, 8);
    calc_chkSum = inChkSum(inBuf, ntohs(udpHdr->length) + 12, 8);

//    UDPDEBUG(("inChkSum  =%04X\n", inChkSum(inBuf, ToInt(udpHdr->length), sizeof(IPHdr))));
//    UDPDEBUG(("CalcChkSum=%04X\n", CalcChkSum((u_int16*)udpHdr, ToInt(udpHdr->length), 0)));
//    UDPDEBUG((" HeaderSum =%04X\n", inChkSum(inBuf, 12, 8)));
//    UDPDEBUG(("~CalcPseudo=%04X\n", ~CalcPseudoHdr(ipHdr, udpHdr->length) & 0xFFFF));
//    UDPDEBUG(("udpHdr->length=%04X\n",udpHdr->length));
//    UDPDEBUG(("calc_chkSum=%04X\n",calc_chkSum));
//    UDPDEBUG("recv_chkSum=%04X\n",recv_chkSum);
//    UDPDEBUG(("inBuf->len=%04X\n",inBuf->len));

    if (recv_chkSum != calc_chkSum) {
        // checksum failed, junk the packet - as UDP isn't a connection oriented protocol,
        //  we don't need to inform the sender, we can simply throw the packet away
        UDPDEBUG(("chkSum FAILED - recv_chkSum=%04X, calc_chkSum=%04X\n", recv_chkSum, calc_chkSum));

#if DEBUG_SUPPORT > 0			
        udpHdr->checksum = recv_chkSum;
        RxUdp(inBuf);
#endif

        nFreeChain(inBuf);
        return;
    }


	// If we have received an empty UDP packet (no payload) discard it
	if (inBuf->chainLen <= (sizeof(IPHdr) + sizeof(UDPHdr))) {
		// Free "memory"
		nFreeChain(inBuf);
		return;
	}

    /* Try to find an open udp port to receive the incoming packet */
//    udpCB = udpResolveIncomingUDPCB(ipHdr->ip_src.s_addr, udpHdr->dstPort);
    udpCB = udpResolveIncomingUDPCB(ntohl(ipHdr->ip_src.s_addr), ntohs(udpHdr->dstPort));
    if (udpCB == NULL) {

		// Only reflect the packet if it is a unicast!!!
		if (ntohl(ipHdr->ip_dst.s_addr) == localHost) {
            /* if port not open, or port is not listening for connections from that address reflect the packet */
            UDPDEBUG(("udpInput: port %ld not open, sending icmp_error\n", udpHdr->dstPort));
            icmp_error(inBuf, ICMP_UNREACH,ICMP_UNREACH_PORT, 0);
		}
        return;
    }

    /* Add NBuf chain to the incoming data queue for the port */
//    inBuf->data = (unsigned char*)(udpHdr + 1);
    if (udpCB->tail) {
        udpCB->tail->next = alloc_udp_q();
        if (udpCB->tail->next == NULL) {
            goto UDP_ALLOC_FAILED;
        }
        udpCB->tail = udpCB->tail->next;
    } else {
        udpCB->head = udpCB->tail = alloc_udp_q();
        if (udpCB->tail == NULL) {
            goto UDP_ALLOC_FAILED;
        }
    }
    udpCB->tail->next = NULL;
    udpCB->tail->srcAddr = ipHdr->ip_src;
    udpCB->tail->srcPort = udpHdr->srcPort;
    udpCB->tail->nBuf = inBuf;

    // **** Remove IP and UDP header stuff
	nTrim(NULL, &udpCB->tail->nBuf, sizeof(IPHdr) + sizeof(UDPHdr));

#if ONETASK_SUPPORT > 0
    if (udpCB->receiveEvent) 
          // Data received so notify user, 
          udpCB->receiveEvent((int)(udpCB - &udps[0]), udpCB->tail->nBuf->chainLen); 
#else
    /* finally, post a semaphore to wake up anyone waiting for data on this UDP port */
    OSSemPost(udpCB->sem);
#endif
 
    return;

UDP_ALLOC_FAILED:
    UDPDEBUG(("udpInput: port %ld, out of udp queue buffers\n", udpHdr->dstPort));
    return;
}


////////////////////////////////////////////////////////////////////////////////
#if 0

int udpWrite(u_int ud, const void* buf, long len)
{
    NBuf* pNBuf;
    NBuf* pNBufTail;
    IPHdr* ipHdr;
    UDPHdr* udpHdr;
    long rtn = len;
    long segLen;
    long packetLen;
    const unsigned char* d;
    u_int mtu;

    UDPDEBUG(("udpWrite()\n"));
    if (!(udps[ud].flags & FUDP_OPEN)) return -1;
    mtu = ipMTU(htonl(udps[ud].theirAddr.s_addr));
    if (!mtu) {
        UDPDEBUG(("no route to host\n"));
        return -1;
    }
    while (len) {
        pNBuf = NULL;
#if ONETASK_SUPPORT > 0
		// We can't do a loop forever in a onetask OS
        nGET(pNBuf);
		// No more nBuf buffers available, should return what we have copied so far
		if (!pNBuf) return rtn;
#else
		// BUSY WAITING! (not nice)
        do {
            nGET(pNBuf);
        } while (pNBuf == NULL);
#endif
        pNBufTail = pNBuf;
        packetLen = MIN(mtu, sizeof(IPHdr) + sizeof(UDPHdr) + len);

        /* build IP header */
        ipHdr = nBUFTOPTR(pNBufTail, IPHdr*);
        ipHdr->ip_v = 4;
        ipHdr->ip_hl = sizeof(IPHdr) / 4;
        ipHdr->ip_tos = udps[ud].tos;
        ipHdr->ip_len = packetLen;
        ipHdr->ip_id = IPNEWID();
        ipHdr->ip_off = 0;
        ipHdr->ip_ttl = 0;
        ipHdr->ip_p = IPPROTO_UDP;
        ipHdr->ip_sum = htons(ipHdr->ip_len - sizeof(IPHdr));

        memcpy(ipHdr->ip_src.s_addr, (u_char)&localHost, 4);
//        ipHdr->ip_dst.s_addr = htonl(udps[ud].theirAddr.s_addr);
        ipHdr->ip_dst.s_addr = udps[ud].theirAddr.s_addr;

        pNBuf->chainLen = packetLen;
        packetLen -= sizeof(IPHdr);

        /* Build the UDP header */
        udpHdr = (UDPHdr*)(ipHdr + 1);
        udpHdr->srcPort = udps[ud].ourPort;
        udpHdr->dstPort = udps[ud].theirPort;
        udpHdr->length = packetLen;
        udpHdr->checksum = 0;
        pNBufTail->data = (unsigned char*)(udpHdr+1);
        pNBufTail->len = sizeof(IPHdr) + sizeof(UDPHdr);
        packetLen -= sizeof(UDPHdr);
        len -= packetLen;


        UDPDEBUG(("-src=%s port %ld dest=%s port=%ld\n", \
            ip_ntoa((ipHdr->ip_src.s_addr)),   \
            htons(udpHdr->srcPort),                     \
            ip_ntoa2((ipHdr->ip_dst.s_addr)),  \
            htons(udpHdr->dstPort)                      \
            ));

        /* copy data to nBuf chain */
        d = (unsigned char*)buf;
        while (packetLen) {
            segLen = MIN(NBUFSZ - pNBufTail->len, packetLen);
            memcpy(pNBufTail->data, d, segLen);
            pNBufTail->len += segLen;
            packetLen -= segLen;
            if (packetLen) {
                do {
                    nGET(pNBufTail->nextBuf);
                } while (!pNBufTail->nextBuf);
                pNBufTail = pNBufTail->nextBuf;
                pNBufTail->nextBuf = NULL;
                pNBufTail->len = 0;
            }
        }
        pNBuf->data = pNBuf->body;
        udpHdr->checksum = inChkSum(pNBuf, pNBuf->chainLen - 8, 8);
        ipHdr->ip_ttl = UDPTTL;
      //  DUMPCHAIN(pNBuf);
        /* Pass the datagram to IP and we're done. */
        ipRawOut(pNBuf);
    }
    return rtn;
}

#endif
