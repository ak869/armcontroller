struct prhdr {
	u_char	pr_status;	/* is this a good packet, same as ds0_rsr */
	u_char	pr_nxtpg;	/* next page of packet or next packet */
	u_char	pr_sz0;
	u_char	pr_sz1;
};
neintr(unit)
{
	register struct ne_softc *ns = &ne_softc[unit];
	u_char cmd,isr;

	/* Save cmd, clear interrupt */
	cmd = inb (nec+ds_cmd);
loop:
	isr = inb (nec+ds0_isr);
	outb(nec+ds_cmd,DSCM_NODMA|DSCM_START);
	outb(nec+ds0_isr, isr);

	/* Receiver error */
	if (isr & DSIS_RXE) {
		/* need to read these registers to clear status */
		(void) inb(nec+ ds0_rsr);
		(void) inb(nec+ 0xD);
		(void) inb(nec + 0xE);
		(void) inb(nec + 0xF);
		ns->ns_if.if_ierrors++;
	}

	/* We received something; rummage thru tiny ring buffer */
	if (isr & (DSIS_RX|DSIS_RXE|DSIS_ROVRN)) {
		u_char pend,lastfree;

		outb(nec+ds_cmd, DSCM_START|DSCM_NODMA|DSCM_PG1);
		pend = inb(nec+ds1_curr);
		outb(nec+ds_cmd, DSCM_START|DSCM_NODMA|DSCM_PG0);
		lastfree = inb(nec+ds0_bnry);

		/* Have we wrapped? */
		if (lastfree >= RBUFEND/DS_PGSIZE)
			lastfree = RBUF/DS_PGSIZE;
		if (pend < lastfree && ns->ns_cur < pend)
			lastfree = ns->ns_cur;
		else	if (ns->ns_cur > lastfree)
			lastfree = ns->ns_cur;

		/* Something in the buffer? */
		while (pend != lastfree) { //是否为空
			u_char nxt;

			/* Extract header from microcephalic board */
			nefetch(&ns->ns_ph,lastfree*DS_PGSIZE,	//读取头
				sizeof(ns->ns_ph));
			ns->ns_ba = lastfree*DS_PGSIZE+sizeof(ns->ns_ph);	//定下初始位置

			/* Incipient paranoia */
			if (ns->ns_ph.pr_status == DSRS_RPC ||		/* for dequna's */
				ns->ns_ph.pr_status == 0x21)
				nerecv (ns);


			nxt = ns->ns_ph.pr_nxtpg ;

			/* Sanity check */
			if ( nxt >= RBUF/DS_PGSIZE && nxt <= RBUFEND/DS_PGSIZE
				&& nxt <= pend)
				ns->ns_cur = nxt;
			else	ns->ns_cur = nxt = pend;

			/* Set the boundaries */
			lastfree = nxt;
			outb(nec+ds0_bnry, pred(nxt));
			outb(nec+ds_cmd, DSCM_START|DSCM_NODMA|DSCM_PG1);
			pend = inb(nec+ds1_curr);
			outb(nec+ds_cmd, DSCM_START|DSCM_NODMA|DSCM_PG0);
		}
		outb(nec+ds_cmd, DSCM_START|DSCM_NODMA);
	}

	/* Transmit error */
	if (isr & DSIS_TXE) {
		ns->ns_flags &= ~DSF_LOCK;
		/* Need to read these registers to clear status */
		ns->ns_if.if_collisions += inb(nec+ds0_tbcr0);
		ns->ns_if.if_oerrors++;
	}

	/* Packet Transmitted */
	if (isr & DSIS_TX) {
		ns->ns_flags &= ~DSF_LOCK;
		++ns->ns_if.if_opackets;
		ns->ns_if.if_collisions += inb(nec+ds0_tbcr0);
	}

	/* Receiver ovverun? */
	if (isr & DSIS_ROVRN) {
		log(LOG_ERR, "ne%d: error: isr %x\n", ns-ne_softc, isr
			/*, DSIS_BITS*/);
		outb(nec+ds0_rbcr0, 0);
		outb(nec+ds0_rbcr1, 0);
		outb(nec+ds0_tcr, DSTC_LB0);
		outb(nec+ds0_rcr, DSRC_MON);
		outb(nec+ds_cmd, DSCM_START|DSCM_NODMA);
		outb(nec+ds0_rcr, DSRC_AB);
		outb(nec+ds0_tcr, 0);
	}

	/* Any more to send? */
	outb (nec+ds_cmd, DSCM_NODMA|DSCM_PG0|DSCM_START);
	nestart(&ns->ns_if);
	outb (nec+ds_cmd, cmd);
	outb (nec+ds0_imr, 0xff);

	/* Still more to do? */
	isr = inb (nec+ds0_isr);
	if(isr) goto loop;
}

nerecv(ns)
	register struct ne_softc *ns;
{
	int len,i;

	ns->ns_if.if_ipackets++;
	len = ns->ns_ph.pr_sz0 + (ns->ns_ph.pr_sz1<<8);
	if(len < ETHER_MIN_LEN || len > ETHER_MAX_LEN)
		return;

	/* this need not be so torturous - one/two bcopys at most into mbufs */
	nefetch(ns->ns_pb, ns->ns_ba, min(len,DS_PGSIZE-sizeof(ns->ns_ph)));
	if (len > DS_PGSIZE-sizeof(ns->ns_ph)) {
		int l = len - (DS_PGSIZE-sizeof(ns->ns_ph)), b ;
		u_char *p = ns->ns_pb + (DS_PGSIZE-sizeof(ns->ns_ph));

		if(++ns->ns_cur > 0x7f) ns->ns_cur = 0x46;
		b = ns->ns_cur*DS_PGSIZE;
		
		while (l >= DS_PGSIZE) {
			nefetch(p, b, DS_PGSIZE);
			p += DS_PGSIZE; l -= DS_PGSIZE;
			if(++ns->ns_cur > 0x7f) ns->ns_cur = 0x46;
			b = ns->ns_cur*DS_PGSIZE;
		}
		if (l > 0)
			nefetch(p, b, l);
	}
	/* don't forget checksum! */
	len -= sizeof(struct ether_header) + sizeof(long);
			
	neread(ns,(caddr_t)(ns->ns_pb), len);
}
nefetch (up, ad, len) caddr_t up; {
	u_char cmd;

	cmd = inb(nec+ds_cmd);
	outb (nec+ds_cmd, DSCM_NODMA|DSCM_PG0|DSCM_START);

	/* Setup remote dma */
	outb (nec+ds0_isr, DSIS_RDC);
	outb (nec+ds0_rbcr0, len);
	outb (nec+ds0_rbcr1, len>>8);
	outb (nec+ds0_rsar0, ad);
	outb (nec+ds0_rsar1, ad>>8);

	/* Execute & extract from card */
	outb (nec+ds_cmd, DSCM_RREAD|DSCM_PG0|DSCM_START);
	insw (nec+ne_data, up, len/2);

	/* Wait till done, then shutdown feature */
	while ((inb (nec+ds0_isr) & DSIS_RDC) == 0) ;
	outb (nec+ds0_isr, DSIS_RDC);
	outb (nec+ds_cmd, cmd);
}