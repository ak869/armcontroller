/*****************************************************************************
* netdhcp.c - 
*
* portions Copyright (c) 2001 by Cognizant Pty Ltd.
* portions Copyright (c) 2002 by Access Devices Ltd.
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
* 2002-01-03 Craig Graham <c_graham@hinge.mistral.co.uk>, Access Devices Ltd
*            Implemented DHCP (sort of, not fully, but works ok).
******************************************************************************
*/
#include "netconf.h"
#include "net.h"
#include "netbuf.h"
#include "netos.h"
#include "netdebug.h"
#include "netudp.h"
#include "netaddrs.h"
#include "netether.h"
#include "netip.h"
#include "netdhcp.h"
#include "nettimer.h"

// this is in netether.c
extern etherSetup mySetup;
extern u_int32_t localHost;
extern int inDHCP;

//#define DHCP_DEBUG(X) printf X
#define DHCP_DEBUG(X)
/**
 * Broadcast a DHCPDISCOVER message.
 * We cheat a little here, by fiddling our IP address instead of setting up the rest of
 * the stack to support broadcast stuff...
 */
static int DHCP_SendDiscover(DHCP_INFO* i)
{
	unsigned char buf[sizeof(DHCP_HEADER) + 100];
	unsigned char* option;
	struct sockaddr_in addr;
	DHCP_HEADER *h = (DHCP_HEADER*)buf;

	DHCP_DEBUG(("DHCP_SendDiscover()\n"));
	localHost = 0;
	option = (unsigned char*)(h + 1);
	h->op = DHCP_BOOTREQUEST;
	h->htype = DHCP_ETHERNET;
	h->hlen = 6;
	h->hops = 0;

	h->xid = htonl(i->xid);
	h->secs = 0;
	h->flags = htons(0x8000);
	h->ciaddr = 0;
	h->yiaddr = 0;
	h->siaddr = 0;
	h->giaddr = 0;
	memset(h->chaddr, 0, 16);
	memcpy(h->chaddr, mySetup.hardwareAddr, 6);
	memset(h->sname, 0, 64);
	memset(h->file, 0, 128);
	h->magic = DHCP_MAGIC;
	// set message type DHCPDISCOVER
	*option++ = DHCP_OPTION_MESSAGE_TYPE;
	*option++ = 1;
	*option++ = DHCPDISCOVER;
	// set client identifier (==MAC address)
	*option++ = DHCP_OPTION_CLIENT_IDENTIFIER;
	*option++ = 7;
	*option++ = DHCP_ETHERNET;
	memcpy(option, mySetup.hardwareAddr, 6);
	option += 6;
	// end option
	*option++ = DHCP_OPTION_END;
	// pad out to minimum DHCP packet length
	while (((long)(option-buf)) < 300)
		*option++ = DHCP_OPTION_PAD;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(BOOTPC);	// we have to send from bootp client port (68)
	memset(&addr.sin_addr, 0, 4);
	udpBind(i->s, &addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(BOOTPS);	// we have to send to bootp server port (67)
	memset(&addr.sin_addr, 0xff, 4); // broadcast address
	udpSendTo(i->s, buf, (long)(option-buf), &addr);
	i->state = DHCPS_DISCOVER;
    return 0;
}

/**
 * Send a DHCPREQUEST message.
 * We cheat a little here, by fiddling our IP address instead of setting up the rest of
 * the stack to support broadcast stuff...
 */
static int DHCP_SendRequest(DHCP_INFO* i)
{
	unsigned char buf[sizeof(DHCP_HEADER) + 100];
	unsigned char* option;
	DHCP_HEADER* h = (DHCP_HEADER*)buf;
	struct sockaddr_in addr;
//	u_int32_t tmp;

	DHCP_DEBUG(("DHCP_SendRequest()\n"));
	localHost = 0;

	option = (unsigned char*)(h + 1);
	h->op = DHCP_BOOTREQUEST;
	h->htype = DHCP_ETHERNET;
	h->hlen = 6;
	h->hops = 0;
	h->xid = htonl(i->xid);
	h->secs = 0;
	h->flags = htons(0x8000);
	h->ciaddr = 0;
	h->yiaddr = 0;
	h->siaddr = 0;
	h->giaddr = 0;
	memset(h->chaddr, 0, 16);
	memcpy(h->chaddr, mySetup.hardwareAddr, 6);
	memset(h->sname, 0, 64);
	memset(h->file, 0, 128);
	h->magic = DHCP_MAGIC;
	// set message type DHCPREQUEST
	*option++ = DHCP_OPTION_MESSAGE_TYPE;
	*option++ = 1;
	*option++ = DHCPREQUEST;
	// set client identifier ( == MAC address)
	*option++ = DHCP_OPTION_CLIENT_IDENTIFIER;
	*option++ = 7;
	*option++ = DHCP_ETHERNET;
	memcpy(option, mySetup.hardwareAddr, 6);
	option += 6;
	// set ip address we're requesting
	*option++ = DHCP_OPTION_REQUESTED_IP_ADDRESS;
	*option++ = 4;
	*option++ = (i->my_ip>>24) & 0xff;
	*option++ = (i->my_ip>>16) & 0xff;
	*option++ = (i->my_ip>>8) & 0xff;
	*option++ = (i->my_ip) & 0xff;
	// DHCP server's ip address
	*option++ = DHCP_OPTION_SERVER_IDENTIFIER;
	*option++ = 4;
	*option++ = (i->dhcp_server>>24) & 0xff;
	*option++ = (i->dhcp_server>>16) & 0xff;
	*option++ = (i->dhcp_server>>8)& 0xff;
	*option++ = (i->dhcp_server) & 0xff;
	// Let's make sure we get the DNS and gateway passed back.
	// Microsoft's DNS servers don't do this by default (unlike the Linux DHCP server),
	// so we must explicitly ask for them.
	*option++ = DHCP_OPTION_PARAMETER_LIST_REQUEST;
	*option++ = 3;
	*option++ = DHCP_OPTION_ROUTER;
	*option++ = DHCP_OPTION_DNS_SERVER;
	*option++ = DHCP_OPTION_SUBNET_MASK;
	// end option
	*option++ = DHCP_OPTION_END;
	// pad out to minimum DHCP packet length
	while (((long)(option-buf)) < 300)
		*option++ = DHCP_OPTION_PAD;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(BOOTPC);	// we have to send from bootp client port (68)
	memset(&addr.sin_addr, 0, 4);
	udpBind(i->s, &addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(BOOTPS);	// we have to send to bootp server port (67)
	memset(&addr.sin_addr, 0xff, 4); // broadcast address
	udpSendTo(i->s, buf, (long)(option-buf), &addr);
	i->state = DHCPS_REQUEST;
    return 0;
}

static void DHCP_GRTimeout(void* p)
{
	DHCP_INFO* i = (DHCP_INFO*)p;
	udpUnblockRead(i->s);
	i->err = -2;
}

static int DHCP_GetResponse(DHCP_INFO* i)
{
	long l;
	unsigned char option;
	unsigned char optionLength;
	u_int32_t tmp;

	DHCP_DEBUG(("DHCP_GetResponse()\n"));

	localHost = 0xffffffff;
__retry:
	i->err = 0;
	if (timerTempSeconds(DHCP_TIMEOUT,DHCP_GRTimeout,i)) {
		i->state = DHCPS_ABORT;
		return -1;
	}

	l  =  udpRead(i->s, &i->h, sizeof(DHCP_HEADER));
	if (i->err)	{
		DHCP_DEBUG(("DHCP_GetResponse():timeout\n"));
		i->state = DHCPS_TIMEOUT;
		return i->err;
	}

	timerCancel(DHCP_GRTimeout,i);
	if (l < 0)
		return l;
	DHCP_DEBUG(("got response, length = %ld\n",l));
	if (l < sizeof(DHCP_HEADER)) {
		i->state = DHCPS_ABORT;
		DHCP_DEBUG(("DHCP_GetResponse():short packet\n"));
		return -4;
	}
	NTOHL(i->h.xid);
	NTOHS(i->h.secs);
	NTOHS(i->h.flags);
	NTOHL(i->h.ciaddr);
	NTOHL(i->h.yiaddr);
	NTOHL(i->h.siaddr);
	NTOHL(i->h.giaddr);
	NTOHL(i->h.magic);
	if (i->h.xid != i->xid)	{
		DHCP_DEBUG(("wrong xid\n"));
		goto __retry;
	}
	if (i->h.magic != DHCP_MAGIC) {
		DHCP_DEBUG(("magic failled\n"));
		return -3;
	}
	DHCP_DEBUG(("seems ok :) - let's process options\n"));
	i->lastMessageType = DHCPERROR;
	do {
		l = udpRead(i->s, &option, 1);
		DHCP_DEBUG(("%ld : ",option));
		switch (option) {
		case DHCP_OPTION_END:
			DHCP_DEBUG(("end\n"));
			udpClose(i->s);
			i->s = udpOpen();
			break;
		case DHCP_OPTION_PAD:
			DHCP_DEBUG(("pad\n"));
			break;
		case DHCP_OPTION_SUBNET_MASK:
			udpRead(i->s, &optionLength, 1);
			udpRead(i->s, &i->subnet_mask, 4);
			NTOHL(i->subnet_mask);
			DHCP_DEBUG(("subnet = %s\n", ip_ntoa(i->subnet_mask)));
			break;
		case DHCP_OPTION_ROUTER:
			udpRead(i->s, &optionLength, 1);
			udpRead(i->s, &i->router, 4);
			NTOHL(i->router);
			optionLength >>= 2;
			while (--optionLength)
				udpRead(i->s, &tmp, 4);
			DHCP_DEBUG(("router = %s\n", ip_ntoa(i->router)));
			break;
		case DHCP_OPTION_DNS_SERVER:
			udpRead(i->s, &optionLength, 1);
			optionLength >>= 2;
			tmp = 0;
			DHCP_DEBUG(("dns server:\n"));
			while ((tmp < 2) && (optionLength)) {
				udpRead(i->s, &i->dns_server[tmp], 4);
				NTOHL(i->dns_server[tmp]);
				DHCP_DEBUG(("   %s\n", ip_ntoa(i->dns_server[tmp])));
				optionLength--;
                tmp++;
			}
			while (optionLength--)
				udpRead(i->s, &tmp, 4);
			break;

		case DHCP_OPTION_MESSAGE_TYPE:
			udpRead(i->s, &optionLength, 1);
			udpRead(i->s, &optionLength, 1);
			i->lastMessageType = (DHCP_MESSAGE_TYPE)optionLength;
			DHCP_DEBUG(("message type = %d\n", i->lastMessageType));
			break;

		case DHCP_OPTION_LEASE_TIME:
			udpRead(i->s, &optionLength, 1);
			udpRead(i->s, &i->lease_time, 4);
			NTOHL(i->lease_time);
			DHCP_DEBUG(("lease time = %ld\n", i->lease_time));
			break;

		case DHCP_OPTION_SERVER_IDENTIFIER:
			udpRead(i->s, &optionLength, 1);
			udpRead(i->s, &i->dhcp_server, 4);
			NTOHL(i->dhcp_server);
			DHCP_DEBUG(("DHCP server = %s\n", ip_ntoa(i->dhcp_server)));
			break;

		case DHCP_OPTION_RENEWAL_TIME:
			udpRead(i->s, &optionLength, 1);
			udpRead(i->s, &i->renewal_time, 4);
			NTOHL(i->renewal_time);
			DHCP_DEBUG(("renewal time = %ld\n", i->renewal_time));
			break;

		case DHCP_OPTION_REBINDING_TIME:
			udpRead(i->s, &optionLength, 1);
			udpRead(i->s, &i->rebinding_time, 4);
			NTOHL(i->rebinding_time);
			DHCP_DEBUG(("rebinding time = %ld\n", i->rebinding_time));
			break;

		default:
			udpRead(i->s, &optionLength, 1);
			DHCP_DEBUG(("unknown option %ld, length %ld\n", option, optionLength));
			while (optionLength--)
				udpRead(i->s, &tmp, 1);
			break;
		}
	} while(option != DHCP_OPTION_END);
	return 0;
}

static int DHCP_Begin(DHCP_INFO* i)
{
	DHCP_DEBUG(("DHCP_Begin()\n"));
	i->s = udpOpen();
	if (i->s < 0) {
		DHCP_DEBUG(("udpOpen() failled\n"));
		i->state = DHCPS_ABORT;
		return -1;
	}
	i->xid = OSTimeGet();
	inDHCP = 1;
	i->state = DHCPS_BEGIN;
	return 0;
}

static int DHCP_End(DHCP_INFO* i)
{
	DHCP_DEBUG(("DHCP_End()\n"));
	if (i->s >= 0) {
		inDHCP = 0;
		udpClose(i->s);
		return 0;
	}
	return -1;
}

int DHCP(void)
{
	DHCP_INFO i;
	int retry = DHCP_MAX_RETRYS;

	DHCP_DEBUG(("DHCP()\n"));
	if (DHCP_Begin(&i))
		return -1;
	do {
		switch (i.state) {
		case DHCPS_BEGIN:
			DHCP_SendDiscover(&i);
			break;
		case DHCPS_OK:
			break;
		case DHCPS_DISCOVER:
			if (DHCP_GetResponse(&i))
				break;
			switch(i.lastMessageType) {
			case DHCPOFFER:
				DHCP_DEBUG(("had an offer: %s\n",ip_ntoa(i.h.yiaddr)));
				i.my_ip = i.h.yiaddr;
				DHCP_SendRequest(&i);
				break;
			default:
				DHCP_DEBUG(("error1\n"));
				break;
			}
			break;
		case DHCPS_TIMEOUT:
			if (--retry) i.state = DHCPS_BEGIN;
			else         i.state = DHCPS_ABORT;
			break;
		case DHCPS_REQUEST:
			if (DHCP_GetResponse(&i))
				break;
			switch(i.lastMessageType) {
			case DHCPACK:
				DHCP_DEBUG(("got ACK :)\n"));
				i.state = DHCPS_OK;
				break;
			case DHCPNAK:
				if (--retry)
					i.state = DHCPS_BEGIN;
				else
					i.state = DHCPS_ABORT;
				break;
			default:
				DHCP_DEBUG(("error2\n"));
				break;
			}
			break;
		}
	} while ((i.state != DHCPS_ABORT) && (i.state != DHCPS_OK));
	DHCP_End(&i);
	if (i.state == DHCPS_OK) {
		// this is a really bad way of reconfiguring the ethernet - what we really need is
		// a way to reconfig it...
		DHCP_DEBUG(("DHCP(): success\n"));
		localHost = mySetup.localAddr = i.my_ip;
		mySetup.gatewayAddr = i.router;
		mySetup.subnetMask = i.subnet_mask;
		DHCP_DEBUG((" our IP =  %s\n", ip_ntoa(i.my_ip)));
		DHCP_DEBUG((" default gateway = %s\n", ip_ntoa(i.router)));
		DHCP_DEBUG((" subnet = %s\n", ip_ntoa(i.subnet_mask)));
	} else {
		DHCP_DEBUG(("DHCP(): failled\n"));
	}
	return (i.state == DHCPS_OK) ? 0 : -1;
}
