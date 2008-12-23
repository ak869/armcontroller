#ifndef _COM_H
#define _COM_H
//Flash opertion


#define PLT_VERSION				0xf1
/*
P1		:nSize;
P2 - P4 :Flash addr
*/
#define GETLONGDATA				0x01		//Short
#define SETLONGDATA				0x42		//Long
#define SETBYTEDATA				0x03		//Short
#define SETBITDATA				0x04		//Short
#define ESAREFLASH				0x05

//TIME opertion
#define SETDATETIME				0x46		//Long
#define GETDATETIME				0x07		//Short

//User opertion
#define ADDUSER					0x48		//Long
#define USERLIST				0x09		//Short
#define DELUSER					0x10

//Log opertion
#define DOWNLOADLOG				0x0a		//Short
#define DELLOG					0x0b		//Short

//Machine opertion
/*
	P1	: node(0xff:test)
	P2	: opertion
*/
#define SETSTATUE				0x0c		//Short
#define GETSTATUS				0x0d		//Short


//net module
#define SETNETMODULE			0x4e		//Long
#define GETNETMODULE			0x0f		//Short


#define CMD_FLAG				0x0
#define CMD_CMD					0x1
#define CMD_P1					0x2
#define CMD_P2					0x3
#define CMD_P3					0x4
#define CMD_P4					0x5
#define CMD_ADDR				0x6
#define CMD_XOR					0x7
#define CMD_SIZE				0x8
#define DATA_PACK_FLAG			0x8
#define DATA_PACK_DATA			0x9

/*
node	

door1	:	0
door2	:	1

test	:	0xff;

*/

#define TEST_NODE	0xFF


#define SUCCESSED_ACK			0x00
#define BUSY_ACK				0x01
#define CHECK_ACK				0x02
#define ERR_READFLASH_ACK		0x03
#define ERR_PARAM_ACK			0x04
#define ERR_TYPE_ACK			0x05
#define ERR_WRITEFLASH_ACK		0x06
#define ERR_NOLOG_ACK			0x07
#define ERR_DATABASE_FULL_ACK 	0x08
#define ERR_NOUSER_ACK			0x09
#define ERR_CMD					0x0a
#define ERR_CMDPARAM			0x0b
#define ERR_NODENOEXIST			0x0c
#define ERR_USERNOEXIST			0x0d
/*
old		0xf5
lu_new	0xf6
my_new	0xf1






*/
#endif