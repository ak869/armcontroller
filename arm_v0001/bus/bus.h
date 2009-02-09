#ifndef _BUS_H
#define _BUS_H

#define NET_ADDR			0
#define OUTPIN1_ADDR		0x20
#define OUTPIN2_ADDR		0x40
#define MACHINE_ADDR		0x60

void BusInit(void);
void output(uint8 addr, uint8 data);
uint8 input( uint8 addr );
#endif