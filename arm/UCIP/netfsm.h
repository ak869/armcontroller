/*****************************************************************************
* netfsm.h - Network Control Protocol Finite State Machine header file.
*
* Copyright (c) 1997 Global Election Systems Inc.
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
* 97-11-05 Guy Lancaster <glanca@gesn.com>, Global Election Systems Inc.
*	Original based on BSD code.
*****************************************************************************/
/*
 * fsm.h - {Link, IP} Control Protocol Finite State Machine definitions.
 *
 * Copyright (c) 1989 Carnegie Mellon University.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by Carnegie Mellon University.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * $Id: netfsm.h,v 1.3 2001/05/24 16:14:37 odin34 Exp $
 */

#ifndef NETFSM_H
#define NETFSM_H


/*****************************************************************************
************************* PUBLIC DEFINITIONS *********************************
*****************************************************************************/
/*
 * LCP Packet header = Code, id, length.
 */
#define HEADERLEN	(sizeof (u_char) + sizeof (u_char) + sizeof (u_short))


/*
 *  CP (LCP, IPCP, etc.) codes.
 */
#define CONFREQ		1		/* Configuration Request */
#define CONFACK		2		/* Configuration Ack */
#define CONFNAK		3		/* Configuration Nak */
#define CONFREJ		4		/* Configuration Reject */
#define TERMREQ		5		/* Termination Request */
#define TERMACK		6		/* Termination Ack */
#define CODEREJ		7		/* Code Reject */

/*
 * Link states.
 */
#define INITIAL		0		/* Down, hasn't been opened */
#define STARTING	1		/* Down, been opened */
#define CLOSED		2		/* Up, hasn't been opened */
#define STOPPED		3		/* Open, waiting for down event */
#define CLOSING		4		/* Terminating the connection, not open */
#define STOPPING	5		/* Terminating, but open */
#define REQSENT		6		/* We've sent a Config Request */
#define ACKRCVD		7		/* We've received a Config Ack */
#define ACKSENT		8		/* We've sent a Config Ack */
#define OPENED		9		/* Connection available */


/*
 * Flags - indicate options controlling FSM operation
 */
#define OPT_PASSIVE	1		/* Don't die if we don't get a response */
#define OPT_RESTART	2		/* Treat 2nd OPEN as DOWN, UP */
#define OPT_SILENT	4		/* Wait for peer to speak first */


/*
 * Timeouts.
 */
#define DEFTIMEOUT	3		/* Timeout time in seconds */
#define DEFMAXTERMREQS	2	/* Maximum Terminate-Request transmissions */
#define DEFMAXCONFREQS	10	/* Maximum Configure-Request transmissions */
#define DEFMAXNAKLOOPS	5	/* Maximum number of nak loops */


/*****************************************************************************
************************* PUBLIC DATA TYPES **********************************
*****************************************************************************/
/*
 * Each FSM is described by an fsm structure and fsm callbacks.
 */
typedef struct fsm {
    int unit;				/* Interface unit number */
    int protocol;			/* Data Link Layer Protocol field value */
    int state;				/* State */
    int flags;				/* Contains option bits */
    u_char id;				/* Current id */
    u_char reqid;			/* Current request id */
    u_char seen_ack;		/* Have received valid Ack/Nak/Rej to Req */
    int timeouttime;		/* Timeout time in milliseconds */
    int maxconfreqtransmits;/* Maximum Configure-Request transmissions */
    int retransmits;		/* Number of retransmissions left */
    int maxtermtransmits;	/* Maximum Terminate-Request transmissions */
    int nakloops;			/* Number of nak loops since last ack */
    int maxnakloops;		/* Maximum number of nak loops tolerated */
    struct fsm_callbacks* callbacks;/* Callback routines */
    char* term_reason;		/* Reason for closing protocol */
    int term_reason_len;	/* Length of term_reason */
} fsm;


typedef struct fsm_callbacks {
    void (*resetci)			/* Reset our Configuration Information */
		__P((fsm*));
    int  (*cilen)			/* Length of our Configuration Information */
		__P((fsm*));
    void (*addci) 			/* Add our Configuration Information */
		__P((fsm*, u_char*, int*));
    int  (*ackci)			/* ACK our Configuration Information */
		__P((fsm*, u_char*, int));
    int  (*nakci)			/* NAK our Configuration Information */
		__P((fsm*, u_char*, int));
    int  (*rejci)			/* Reject our Configuration Information */
		__P((fsm*, u_char*, int));
    int  (*reqci)			/* Request peer's Configuration Information */
		__P((fsm*, u_char*, int*, int));
    void (*up)				/* Called when fsm reaches OPENED state */
		__P((fsm*));
    void (*down)			/* Called when fsm leaves OPENED state */
		__P((fsm*));
    void (*starting)		/* Called when we want the lower layer */
		__P((fsm*));
    void (*finished)		/* Called when we don't want the lower layer */
		__P((fsm*));
    void (*protreject)		/* Called when Protocol-Reject received */
		__P((int));
    void (*retransmit)		/* Retransmission is necessary */
		__P((fsm*));
    int  (*extcode)			/* Called when unknown code received */
		__P((fsm*, int, u_char, u_char*, int));
    char *proto_name;		/* String name for protocol (for messages) */
} fsm_callbacks;


/*****************************************************************************
*********************** PUBLIC DATA STRUCTURES *******************************
*****************************************************************************/
/*
 * Variables
 */
extern int peer_mru[];		/* currently negotiated peer MRU (per unit) */


/*****************************************************************************
************************** PUBLIC FUNCTIONS **********************************
*****************************************************************************/

/*
 * Prototypes
 */
void fsm_init __P((fsm*));
void fsm_lowerup __P((fsm*));
void fsm_lowerdown __P((fsm*));
void fsm_open __P((fsm*));
void fsm_close __P((fsm*, char*));
void fsm_input __P((fsm*, u_char*, int));
void fsm_protreject __P((fsm*));
void fsm_sdata __P((fsm*, u_char, u_char, u_char*, int));


#endif

