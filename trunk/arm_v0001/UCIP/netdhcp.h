/*****************************************************************************
* netdhcp.h - 
*
* portions Copyright (c) 2001 by Cognizant Pty Ltd.
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
* 2001-06-01 Robert Dickenson <odin@pnc.com.au>, Cognizant Pty Ltd.
*            Original file.
* 2002-01-03 Craig Graham <c_graham@hinge.mistral.co.uk>
*            Filled in all the gubbins in this file.... (based on RFC 2131/2132)
******************************************************************************
*/
#ifndef _NETDHCP_H_
#define _NETDHCP_H_

/** Timeout waiting for response from DHCP server in seconds */
#define DHCP_TIMEOUT 3
/** Number of retries before we give up */
#define DHCP_MAX_RETRYS 4

/** Magic number in DHCP packet */
#define DHCP_MAGIC 0x63825363

typedef enum {
	DHCPS_BEGIN,
	DHCPS_DISCOVER,
	DHCPS_REQUEST,
	DHCPS_OK,
	DHCPS_ABORT,
	DHCPS_TIMEOUT
} DHCP_STATE;

typedef enum {
	DHCPDISCOVER=1,
	DHCPOFFER=2,
	DHCPREQUEST=3,
	DHCPDECLINE=4,
	DHCPACK=5,
	DHCPNAK=6,
	DHCPRELEASE=7,
	DHCPINFORM=8,
	DHCPERROR=-1
} DHCP_MESSAGE_TYPE;

typedef struct {
	unsigned char op;
	unsigned char htype;
	unsigned char hlen;
	unsigned char hops;
	u_int32_t xid;
	u_int16_t secs;
	u_int16_t flags;
	u_int32_t ciaddr;
	u_int32_t yiaddr;
	u_int32_t siaddr;
	u_int32_t giaddr;
	unsigned char chaddr[16];
	unsigned char sname[64];
	unsigned char file[128];
	u_int32_t magic;
} DHCP_HEADER;

typedef struct {
	u_int32_t my_ip;
	u_int32_t dhcp_server;
	u_int32_t router;
	u_int32_t subnet_mask;
	u_int32_t dns_count;
	u_int32_t dns_server[2];
	u_int32_t xid;
	u_int32_t lease_time;
	u_int32_t renewal_time;
	u_int32_t rebinding_time;
	int err;
	int s;
	DHCP_STATE state;
	DHCP_HEADER h;
	DHCP_MESSAGE_TYPE lastMessageType;
} DHCP_INFO;

typedef enum {
	DHCP_BOOTREQUEST=1,
	DHCP_BOOTREPLY=2
} DHCP_OP;

typedef enum {
	DHCP_ETHERNET=1
} DHCP_HTYPE;

/**
 * DHCP Option codes, courtesy of RFC2132
 */
typedef enum {
//    Code
//   +-----+
//   |  0  |
//   +-----+
	DHCP_OPTION_PAD=0,
//    Code   Len        Subnet Mask
//   +-----+-----+-----+-----+-----+-----+
//   |  1  |  4  |  m1 |  m2 |  m3 |  m4 |
//   +-----+-----+-----+-----+-----+-----+
	DHCP_OPTION_SUBNET_MASK=1,

//    Code   Len        Time Offset
//   +-----+-----+-----+-----+-----+-----+
//   |  2  |  4  |  n1 |  n2 |  n3 |  n4 |
//   +-----+-----+-----+-----+-----+-----+
	DHCP_OPTION_TIME_OFFSET=2,

//    Code   Len         Address 1               Address 2
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
//   |  3  |  n  |  a1 |  a2 |  a3 |  a4 |  a1 |  a2 |  ...
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
	DHCP_OPTION_ROUTER=3,

//    Code   Len         Address 1               Address 2
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
//   |  4  |  n  |  a1 |  a2 |  a3 |  a4 |  a1 |  a2 |  ...
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
	DHCP_OPTION_TIME_SERVER=4,

//    Code   Len         Address 1               Address 2
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
//   |  5  |  n  |  a1 |  a2 |  a3 |  a4 |  a1 |  a2 |  ...
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
	DHCP_OPTION_NAME_SERVER=5,

//    Code   Len         Address 1               Address 2
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
//   |  6  |  n  |  a1 |  a2 |  a3 |  a4 |  a1 |  a2 |  ...
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
	DHCP_OPTION_DNS_SERVER=6,

//    Code   Len         Address 1               Address 2
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
//   |  7  |  n  |  a1 |  a2 |  a3 |  a4 |  a1 |  a2 |  ...
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
	DHCP_OPTION_LOG_SERVER=7,

//    Code   Len         Address 1               Address 2
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
//   |  8  |  n  |  a1 |  a2 |  a3 |  a4 |  a1 |  a2 |  ...
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
	DHCP_OPTION_COOKIE_SERVER=8,

//    Code   Len         Address 1               Address 2
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
//   |  9  |  n  |  a1 |  a2 |  a3 |  a4 |  a1 |  a2 |  ...
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
	DHCP_OPTION_LPR_SERVER=9,

//    Code   Len                 Host Name
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
//   |  12 |  n  |  h1 |  h2 |  h3 |  h4 |  h5 |  h6 |  ...
//   +-----+-----+-----+-----+-----+-----+-----+-----+--
	DHCP_OPTION_HOST_NAME=12,

//    Code   Len        Domain Name
//   +-----+-----+-----+-----+-----+-----+--
//   |  15 |  n  |  d1 |  d2 |  d3 |  d4 |  ...
//   +-----+-----+-----+-----+-----+-----+--
	DHCP_OPTION_DOMAIN_NAME=15,

//    Code   Len          Address
//   +-----+-----+-----+-----+-----+-----+
//   |  50 |  4  |  a1 |  a2 |  a3 |  a4 |
//   +-----+-----+-----+-----+-----+-----+
	DHCP_OPTION_REQUESTED_IP_ADDRESS=50,
	
//    Code   Len         Lease Time
//   +-----+-----+-----+-----+-----+-----+
//   |  51 |  4  |  t1 |  t2 |  t3 |  t4 |
//   +-----+-----+-----+-----+-----+-----+
	DHCP_OPTION_LEASE_TIME=51,

//           Value   Message Type
//           -----   ------------
//             1     DHCPDISCOVER
//             2     DHCPOFFER
//             3     DHCPREQUEST
//             4     DHCPDECLINE
//             5     DHCPACK
//             6     DHCPNAK
//             7     DHCPRELEASE
//             8     DHCPINFORM
//
//    Code   Len  Type
//   +-----+-----+-----+
//   |  53 |  1  | 1-9 |
//   +-----+-----+-----+
	DHCP_OPTION_MESSAGE_TYPE=53,

//    Code   Len            Address
//   +-----+-----+-----+-----+-----+-----+
//   |  54 |  4  |  a1 |  a2 |  a3 |  a4 |
//   +-----+-----+-----+-----+-----+-----+
	DHCP_OPTION_SERVER_IDENTIFIER=54,

//    Code   L7en   Option Codes
//   +-----+-----+-----+-----+---
//   |  55 |  n  |  c1 |  c2 | ...
//   +-----+-----+-----+-----+---
	DHCP_OPTION_PARAMETER_LIST_REQUEST=55,

//    Code   Len         T1 Interval
//   +-----+-----+-----+-----+-----+-----+
//   |  58 |  4  |  t1 |  t2 |  t3 |  t4 |
//   +-----+-----+-----+-----+-----+-----+
	DHCP_OPTION_RENEWAL_TIME=58,

//    Code   Len         T2 Interval
//   +-----+-----+-----+-----+-----+-----+
//   |  59 |  4  |  t1 |  t2 |  t3 |  t4 |
//   +-----+-----+-----+-----+-----+-----+
	DHCP_OPTION_REBINDING_TIME=59,

//   Code   Len   Type  Client-Identifier
//   +-----+-----+-----+-----+-----+---
//   |  61 |  n  |  t1 |  i1 |  i2 | ...
//   +-----+-----+-----+-----+-----+---
	DHCP_OPTION_CLIENT_IDENTIFIER=61,

//    Code
//   +-----+
//   | 255 |
//   +-----+
	DHCP_OPTION_END=255
} DHCP_OPTION_TAG;

#define BOOTPS 67
#define BOOTPC 68

#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
extern "C" {
#endif

extern int DHCP(void);

#if defined(_LANGUAGE_C_PLUS_PLUS)||defined(__cplusplus)||defined(c_plusplus)
}
#endif

#endif /* _NETDHCP_H_ */
