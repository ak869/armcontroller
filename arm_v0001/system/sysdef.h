#ifndef _SYSTEM_DEF_H
#define _SYSTEM_DEF_H
/*
enum e_node
{
	door1 =	0,
	megnet1,
	exit1,
	ctrl1,
	reader1,
	alarm1,
	state1,
	other1,

	door2,
	megnet2,
	exit2,
	ctrl2,
	reader2,
	alarm2,
	state2,
	other2,

	reader_power	=	128,
	net_module,
	rtc,
	flash,
	
	machine	=	254,

	test	
};
*/
#define DEVICE_TYPE		0x01234567
#define DEVICE_VER		0x00001001

#define MEGNET_NODE			0
#define EXIT_NODE			1
#define OTHER_NODE			2
#define ALARM_NODE			3
#define READER_NODE			4
#define DOOR_NODE			5
#define	CTRL_NODE			6

#define EXT_NODE			7

#define IN_NODES			2


#define READERDOOR1				0x00
#define READERDOOR2				0x08
#define READERDOOR3				0x10
#define READERDOOR4				0x18
#define READERDOOR5				0x20
#define READERDOOR6				0x28
#define READERDOOR7				0x30
#define READERDOOR8				0x38
#define READERDOOR9				0x40
#define READERDOOR10			0x48
#define READERDOOR11			0x50
#define READERDOOR12			0x58 
#define READERDOOR13			0x60 
#define READERDOOR14			0x68 
#define READERDOOR15			0x70 
#define READERDOOR16			0x78

#define LOCAL_DOORS				1
#define FULL_DOORS				16


#endif