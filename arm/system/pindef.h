#ifndef _PIN_DEF_H
#define _PIN_DEF_H

#define PIN_DOOR1_BIT		25

#define PIN_MEGNET1_BIT		21
#define PIN_EXIT1_BIT		16
#define PIN_MEGNET2_BIT		25
#define PIN_EXIT2_BIT		25

#define PIN_MSCK_BIT		17
#define PIN_MISO_BIT		18
#define PIN_MOSI_BIT		19
#define PIN_MCS_BIT			20	

#define PIN_MSCK		( 1 << PIN_MSCK_BIT )
#define PIN_MISO		( 1 << PIN_MISO_BIT )
#define PIN_MOSI		( 1 << PIN_MOSI_BIT )
#define PIN_MCS			( 1 << PIN_MCS_BIT )
//#define MDRY		0x800000

#define PIN_DOOR1	( 1 << PIN_DOOR1_BIT )
#define PIN_MEGNET1	( 1 << PIN_MEGNET1_BIT )
#define PIN_EXIT1	( 1 << PIN_EXIT1_BIT )
#define PIN_MEGNET2 ( 1 << PIN_MEGNET2_BIT )
#define PIN_EXIT2	( 1 << PIN_EXIT2_BIT )

#endif