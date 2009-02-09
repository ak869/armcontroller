#ifndef _PIN_DEF_H
#define _PIN_DEF_H


//PIN0
//#define PIN_DOOR1_BIT		18

#define PIN_MEGNET1_BIT		4
#define PIN_EXIT1_BIT		5
#define PIN_MEGNET2_BIT		6
#define PIN_EXIT2_BIT		7

#define PIN_MSCK_BIT		17
#define PIN_MISO_BIT		18
#define PIN_MOSI_BIT		19
#define PIN_MCS_BIT			21
#define PIN_MRDY_BIT		20

#define PIN_DE_RE0			23
#define PIN_DE_RE1			11	

#define PIN_READER1_WD0_BIT		12
#define PIN_READER2_WD0_BIT		13

//INT2
#define PIN_READER1_WDINT		15
//INT0
#define PIN_READER2_WDINT		16

#define PIN_READER1_ALARM		25
#define PIN_READER2_ALARM		26

#define PIN_ALE_BIT				31



//PIN1			
#define PIN_WE_BIT				24
#define PIN_RD_BIT				25
#define PIN_BUSCS_BIT			26



#define PIN_MSCK		( (unsigned int)1 << PIN_MSCK_BIT )
#define PIN_MISO		( (unsigned int)1 << PIN_MISO_BIT )
#define PIN_MOSI		( (unsigned int)1 << PIN_MOSI_BIT )
#define PIN_MCS			( (unsigned int)1 << PIN_MCS_BIT )
//#define MDRY		0x800000


#define PIN_MEGNET1	( (unsigned int)1 << PIN_MEGNET1_BIT )
#define PIN_EXIT1	( (unsigned int)1 << PIN_EXIT1_BIT )

#define PIN_MEGNET2 ( (unsigned int)1 << PIN_MEGNET2_BIT )
#define PIN_EXIT2	( (unsigned int)1 << PIN_EXIT2_BIT )

#define PIN_ALE		( (unsigned int)1 << PIN_ALE_BIT )
#define PIN_WE		( (unsigned int)1 << PIN_WE_BIT )
#define PIN_RD		( (unsigned int)1 << PIN_RD_BIT )
#define PIN_CSE		( (unsigned int)1 << PIN_BUSCS_BIT )


#define PIN_DOOR1			(OUTPIN1_ADDR + 0)
#define PIN_DOOR2			(OUTPIN1_ADDR + 1)
#define PIN_BEEP1			(OUTPIN1_ADDR + 2)
#define PIN_BEEP2			(OUTPIN1_ADDR + 3)
#define PIN_NRST			(OUTPIN1_ADDR + 4)
#define PIN_READER_POWER	(OUTPIN1_ADDR + 5)
#define	PIN_BEEP			(OUTPIN1_ADDR + 6)
#define PIN_L_BL			(OUTPIN1_ADDR + 7)
#define	PIN_LCD_RS			(OUTPIN2_ADDR + 0)
#define PIN_LED1			(OUTPIN2_ADDR + 1)
#define PIN_LED2			(OUTPIN2_ADDR + 2)
#define PIN_LED3			(OUTPIN2_ADDR + 3)
#define PIN_LED4			(OUTPIN2_ADDR + 4)
#define	PIN_CTRL1			(OUTPIN2_ADDR + 5)
#define PIN_CTRL2			(OUTPIN2_ADDR + 6)

#define PIN_MACHINE			(MACHINE_ADDR)
#define	SETOUTPIN(x,y)		output(x,y)
//#define MACHINE_NO			(~input(PIN_MACHINE))
#define MACHINE_NO			1
#endif