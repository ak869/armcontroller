#include "config.h"
unsigned int wd1_data;
unsigned int wd2_data;
unsigned char wd1_count;
unsigned char wd2_count;
void WDInit(void)
{
	PINSEL0 = ( PINSEL0 & (~0xC0000000) ) | 0x80000000;
	PINSEL1 = ( PINSEL1 & (~0x00000003) ) | 0x00000001;
	IODIR &= ~(PIN_READER1_WD0_BIT | PIN_READER2_WD0_BIT);
	
	EXTMODE |= 5;
	EXTPOLAR |= 5;
	wd1_data = 0;
	wd2_data = 0;
	wd1_count = 0;
	wd2_count = 0;
}
unsigned int WD1_26_check( void )
{
	unsigned int ret;
	unsigned int chk;
	int i;
	wd1_data >>= 5;
	ret = 0;
	chk = 0;
	for( i = 0; i < 13; i++ )
	{
		chk ^= (( wd1_data >> i) & 0x1 );
	}
	if( chk )
		goto exit_Weigand1;
	
	chk = 1;
	for( ; i < 26; i++ )
	{
		chk ^= (( wd1_data >> i) & 0x1);
	}
	if( chk )
		goto exit_Weigand1;
		
	ret = wd1_data >> 1;
exit_Weigand1:
	wd1_data = 0;
	wd1_count = 0;
	return ret;
}
void WD1_RST(void)
{
	OS_ENTER_CRITICAL();
	wd1_data = 0;
	wd1_count = 0;
	OS_EXIT_CRITICAL();
}
unsigned int WD2_26_check( void )
{
	unsigned int ret;
	int i;
	unsigned int chk;
	wd2_data >>= 5;
	ret = 0;
	chk = 0;
	for( i = 0; i < 13; i++ )
	{
		chk ^= (( wd2_data >> i ) & 0x1);
	}
	if( chk )
		goto exit_Weigand2;
			
	chk = 1;
	for( ; i < 26; i++ )
	{
		chk ^= (( wd2_data >> i) & 0x1);
	}
	if( chk )
		goto exit_Weigand2;
		
	ret = wd2_data >> 1;
exit_Weigand2:
	wd2_data = 0;
	wd2_count = 0;
	return ret;	
}
void WD2_RST(void)
{
	OS_ENTER_CRITICAL();
	wd2_data = 0;
	wd2_count = 0;
	OS_EXIT_CRITICAL();
}
void WD1_Exception(void)//EINT2
{
	uint32 t;
	OS_ENTER_CRITICAL();
//	if( (EXTINT & 0x4) != 0 )
	EXTINT = 0x4;
	
	if(wd1_count >= 32 )
	{
		wd1_data = 0;
		wd1_count = 0;
	}
	t = IOPIN;
	wd1_data >>= 1;
	wd1_data |= ((t >> PIN_READER1_WD0_BIT) << 31 ) & 0x80000000;	//P0.12
	wd1_count++;
	VICVectAddr = 0x00;
	OS_EXIT_CRITICAL();
}

void WD2_Exception(void)//EINT0
{
	OS_ENTER_CRITICAL();
	EXTINT = 0x1;
	if(wd2_count > 32 )
	{
		wd2_data = 0;
		wd2_count = 0;
	}
	wd2_data >>= 1;
	wd2_data |= (IOPIN << (31 - PIN_READER2_WD0_BIT) ) & 0x80000000;  //P0.13
	wd2_count++;
	VICVectAddr = 0x00;
	OS_EXIT_CRITICAL();
}