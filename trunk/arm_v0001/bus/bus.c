#include "config.h"
#define CS_EN()		IO1SET = PIN_CSE
#define CS_DS()		IO1CLR = PIN_CSE
#define ALE_EN()	IOSET = PIN_ALE
#define ALE_DS()	IOCLR = PIN_ALE
#define WE_EN()		IO1CLR = PIN_WE
#define WE_DS()		IO1SET = PIN_WE
#define RD_EN()		IO1CLR = PIN_RD
#define RD_DS()		IO1SET = PIN_RD
#define SET_DATA(x)	IO1PIN = ((IO1PIN & (~0xff0000)) | (x << 16));
static OS_EVENT *BusSem;

void BusInit( void )
{
	PINSEL2 = 0;
	CS_DS();
	ALE_DS();
	WE_DS();
	RD_DS();
	IODIR |= (PIN_ALE);
	IO1DIR |= (PIN_WE|PIN_RD|PIN_CSE);
	BusSem = OSSemCreate(0);
}
void output(uint8 addr, uint8 data)
{
	uint8 err;
//	OSSemPend(BusSem, 0, &err);
	//set ale
	ALE_EN();
	//set dir
	IO1DIR |= 0xff0000; 
	//set data
	SET_DATA(addr);
	//clear alt
	ALE_DS();
	//set cs
	CS_EN();
	//set data
	SET_DATA(data);
	//clear we
	WE_EN();
	//delay
/*	__asm
	{
		nop
		nop
		nop
	}
*/
	//set we
	WE_DS();
	
	//clear cs 
	CS_DS();
	//clear dir
	IO1DIR &= ~(0xff0000);
	OSSemPost(BusSem);
}
uint8 input( uint8 addr)
{
	uint8 ret,err;
//	OSSemPend(BusSem, 0, &err);
	//set alt
	ALE_EN();
	//set dir
	IO1DIR |= 0xff0000;
	//set data
	SET_DATA(addr);
	//clear alt
	ALE_DS();
	//clear	dir
	IO1DIR &= ~(0xff0000);
	
	//clear cs
	CS_EN();
	//clear rd
	RD_EN();
	//delay
/*	__asm
	{
		nop
		nop
		nop
	}
*/	//get data	
	ret = (IO1PIN >> 16);
	//set rd
	RD_DS();
	//clear cs 
	CS_DS();
	OSSemPost(BusSem);
	return ret;
}