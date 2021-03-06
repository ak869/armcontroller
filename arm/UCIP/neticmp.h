/*****************************************************************************
* neticmp.h - Network Internet Control Message Protocol header file.
*
* portions Copyright (c) 1998 Global Election Systems Inc.
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
* REVISION HISTORY
*
* 98-01-30 Guy Lancaster
*   Based on BSD and ka9q uC/OS sources for M68K.
*****************************************************************************/
/*
 * Copyright (c) 1982, 1986, 1993
 *  The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *  This product includes software developed by the University of
 *  California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *  @(#)ip_icmp.h   8.1 (Berkeley) 6/10/93
 */

/*
 * Interface Control Message Protocol Definitions.
 * Per RFC 792, September 1981.
 */


#ifndef NETICMP_H
#define NETICMP_H

/*************************
*** PUBLIC DEFINITIONS ***
*************************/
/*
 * Lower bounds on packet lengths for various types.
 * For the error advice packets must first insure that the
 * packet is large enought to contain the returned ip header.
 * Only then can we do the check to see if 64 bits of packet
 * data have been returned, since we need to check the returned
 * ip header length.
 */
#define ICMP_MINLEN     8                               /* abs minimum */
#define ICMP_TSLEN      (8 + 3 * sizeof (n_time))       /* timestamp */
#define ICMP_MASKLEN    12                              /* address mask */
#define ICMP_ADVLENMIN  (8 + sizeof (struct ip) + 8)    /* min */
#if defined(ADL_TARGET_PLATFORM)&&(ADL_TARGET_PLATFORM==ADL_TARGET_LS808)
#define ICMP_ADVLEN(p)  (8 + (((p)->icmp_ip.ip_hl_v & 0x0f) << 2) + 8)
#else
//db change
//#define ICMP_ADVLEN(p)  (8 + ((p)->icmp_ip.ip_hl << 2) + 8)
#define ICMP_ADVLEN(p)  (8 + (((p)->icmp_ip.ip_hl_v & 0x0f) << 2) + 8)
#endif
    /* N.B.: must separately check that ip_hl >= 5 */

/*
 * Definition of type and code field values.
 */
#define ICMP_ECHOREPLY              0       /* echo reply */
#define ICMP_UNREACH                3       /* dest unreachable, codes: */
#define ICMP_UNREACH_NET            0       /* bad net */
#define ICMP_UNREACH_HOST           1       /* bad host */
#define ICMP_UNREACH_PROTOCOL       2       /* bad protocol */
#define ICMP_UNREACH_PORT           3       /* bad port */
#define ICMP_UNREACH_NEEDFRAG       4       /* IP_DF caused drop */
#define ICMP_UNREACH_SRCFAIL        5       /* src route failed */
#define ICMP_UNREACH_NET_UNKNOWN    6       /* unknown net */
#define ICMP_UNREACH_HOST_UNKNOWN   7       /* unknown host */
#define ICMP_UNREACH_ISOLATED       8       /* src host isolated */
#define ICMP_UNREACH_NET_PROHIB     9       /* prohibited access */
#define ICMP_UNREACH_HOST_PROHIB    10      /* ditto */
#define ICMP_UNREACH_TOSNET         11      /* bad tos for net */
#define ICMP_UNREACH_TOSHOST        12      /* bad tos for host */
#define ICMP_SOURCEQUENCH           4       /* packet lost, slow down */
#define ICMP_REDIRECT               5       /* shorter route, codes: */
#define ICMP_REDIRECT_NET           0       /* for network */
#define ICMP_REDIRECT_HOST          1       /* for host */
#define ICMP_REDIRECT_TOSNET        2       /* for tos and net */
#define ICMP_REDIRECT_TOSHOST       3       /* for tos and host */
#define ICMP_ECHO                   8       /* echo service */
#define ICMP_ROUTERADVERT           9       /* router advertisement */
#define ICMP_ROUTERSOLICIT          10      /* router solicitation */
#define ICMP_TIMXCEED               11      /* time exceeded, code: */
#define ICMP_TIMXCEED_INTRANS       0       /* ttl==0 in transit */
#define ICMP_TIMXCEED_REASS         1       /* ttl==0 in reass */
#define ICMP_PARAMPROB              12      /* ip header bad */
#define ICMP_PARAMPROB_OPTABSENT    1       /* req. opt. absent */
#define ICMP_TSTAMP                 13      /* timestamp request */
#define ICMP_TSTAMPREPLY            14      /* timestamp reply */
#define ICMP_IREQ                   15      /* information request */
#define ICMP_IREQREPLY              16      /* information reply */
#define ICMP_MASKREQ                17      /* address mask request */
#define ICMP_MASKREPLY              18      /* address mask reply */

#define ICMP_MAXTYPE                18


/************************
*** PUBLIC DATA TYPES ***
************************/
/*
 * Structure of an icmp header.
 */
typedef struct icmp {
    u_char  icmp_type;      /* type of message, see below */
    u_char  icmp_code;      /* type sub code */
    u_short icmp_cksum;     /* ones complement cksum of struct */
    union {
        u_char ih_pptr;         /* ICMP_PARAMPROB */
        struct in_addr ih_gwaddr;   /* ICMP_REDIRECT */
        struct ih_idseq {
            n_short icd_id;
            n_short icd_seq;
        } ih_idseq;
        short ih_void;

        /* ICMP_UNREACH_NEEDFRAG -- Path MTU Discovery (RFC1191) */
        struct ih_pmtu {
            n_short ipm_void;    
            n_short ipm_nextmtu;
        } ih_pmtu;
    } icmp_hun;
#define icmp_pptr   icmp_hun.ih_pptr
#define icmp_gwaddr icmp_hun.ih_gwaddr
#define icmp_id     icmp_hun.ih_idseq.icd_id
#define icmp_seq    icmp_hun.ih_idseq.icd_seq
#define icmp_void   icmp_hun.ih_void
#define icmp_pmvoid icmp_hun.ih_pmtu.ipm_void
#define icmp_nextmtu    icmp_hun.ih_pmtu.ipm_nextmtu
    union {
        struct id_ts {
            u_char its_otime[4];
            u_char its_rtime[4];
            u_char its_ttime[4];
        } id_ts;
        struct id_ip  {
            struct ip idi_ip;
            /* options and then 64 bits of data */
        } id_ip;
        u_char  id_mask[4];
        char    id_data[1];
    } icmp_dun;
#define icmp_otime  icmp_dun.id_ts.its_otime
#define icmp_rtime  icmp_dun.id_ts.its_rtime
#define icmp_ttime  icmp_dun.id_ts.its_ttime
#define icmp_ip     icmp_dun.id_ip.idi_ip
#define icmp_mask   icmp_dun.id_mask
#define icmp_data   icmp_dun.id_data
} IcmpHdr;


/*
 * Variables related to this implementation
 * of the internet control message protocol.
 */
typedef struct {
/* statistics related to icmp packets generated */
    u_int   icps_error;         /* # of calls to icmp_error */
    u_int   icps_oldshort;      /* no error 'cuz old ip too short */
    u_int   icps_oldicmp;       /* no error 'cuz old was icmp */
    u_int   icps_outhist[ICMP_MAXTYPE + 1];
/* statistics related to input messages processed */
    u_int   icps_badcode;       /* icmp_code out of range */
    u_int   icps_tooshort;      /* packet < ICMP_MINLEN */
    u_int   icps_checksum;      /* bad checksum */
    u_int   icps_badlen;        /* calculated bound mismatch */
    u_int   icps_reflect;       /* number of responses */
    u_int   icps_inhist[ICMP_MAXTYPE + 1];
} IcmpStats;



/***********************
*** PUBLIC FUNCTIONS ***
***********************/
void icmpInit(void);

/*
 * Generate an error packet of type error
 * in response to bad packet ip.
 */
//void icmp_error(NBuf *nb, int ih_void; int type, int code, n_long dest);
// <<<< changed int to u_char by RD for portability
void icmp_error(NBuf* nb, u_char type, u_char code, n_long dest);


/*
 * Process a received ICMP message.
 */
//void icmpInput(NBuf* inBuf, int ipHdrLen);
// <<<< changed int to short by RD for portability
void icmpInput(NBuf* inBuf, short ipHdrLen);

#define ICMP_INFOTYPE(type) \
    ((type) == ICMP_ECHOREPLY || (type) == ICMP_ECHO || \
    (type) == ICMP_ROUTERADVERT || (type) == ICMP_ROUTERSOLICIT || \
    (type) == ICMP_TSTAMP || (type) == ICMP_TSTAMPREPLY || \
    (type) == ICMP_IREQ || (type) == ICMP_IREQREPLY || \
    (type) == ICMP_MASKREQ || (type) == ICMP_MASKREPLY)
    
#endif
