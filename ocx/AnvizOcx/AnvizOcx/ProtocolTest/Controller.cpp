// Protocol.cpp: implementation of the CProtocol class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Controller.h"
#include "Plt0001.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CController::CController(CBusProtocol *p, BYTE dn)
{
	m_port = (CBusProtocol *)p;
	m_ErrCode = 0;
	m_addr = dn;
}
CController::CController()
{
	m_port = NULL;
	m_ErrCode = 0;
	m_addr = 0;
}

CController::~CController()
{

}

union tag_flashaddr
{
	struct
	{
		DWORD ba : 10;
		DWORD pa : 12;
		DWORD reserved : 10;
	}bits;
	DWORD addr;
	BYTE value[4];
};

#define PLT_VERSION             0xf1
/*
P1		:nSize; 2 \
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
	P1	: node(0xff:test)  C 
	P2	: opertion    
*/
#define SETSTATUE				0x0c		//Short 
#define GETSTATUS				0x0d		//Short 


//net module
#define SETNETMODULE			0x4e		//Long 
#define GETNETMODULE			0x0f		//Short 





/*

*/

#define DOOR1	0
#define DOOR2	8

#define TEST	255

enum
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
/*
F1 0C FF AA 00 00 01 58 
F1 0D FF 00 00 00 01 F3 
*/
BOOL CController::Test()
{
	BYTE t;
	if( !SetStatus( test, 0xaa) )
		return FALSE;
	t = 0;
	GetStatus(test, &t);
	if( t == 0xaa )
		return TRUE;
	return FALSE;
}

BOOL CController::GetLongData( WORD pa, WORD ba, BYTE *Buf, DWORD nSize)
{

	BOOL ret;
	union tag_flashaddr addr;
	CPLT0001 *p = new CPLT0001();
	addr.addr = 0;
	addr.bits.pa = pa;
	addr.bits.ba = ba;
	
	p->m_CMD = GETLONGDATA;
	p->m_P1 = (BYTE)nSize;
	p->m_P2 = addr.value[2];
	p->m_P3 = addr.value[1];
	p->m_P4	= addr.value[0];
	p->m_addr = m_addr;
//	p->Construction_ShortPack();
//	p->m_TimeOut = 1000;			//Timeout
//	p->m_lParam = NULL;
	
	try
	{
		if( !m_port->SendData(p, 1000, NULL ) )
			throw m_port->GetErrCode();

		if( p->m_P4 != 0 )
		{
			throw (DWORD)p->m_P4;
		}

		if( p->m_dataSize < nSize )
			nSize = p->m_dataSize;

		CopyMemory( Buf, p->m_data, nSize);
		
		ret = TRUE;
	}
	catch(DWORD ErrCode)
	{
		m_ErrCode = ErrCode;
		ret = FALSE;
	}
	delete p;
	return ret;
}


BOOL CController::SetByteData(WORD pa, WORD ba, BYTE Buf)
{

	BOOL ret;
	union tag_flashaddr addr;
	CPLT0001 *p = new CPLT0001();
	addr.addr = 0;
	addr.bits.pa = pa;
	addr.bits.ba = ba;
	
	p->m_CMD = SETBYTEDATA;
	p->m_P1 = Buf;
	p->m_P2 = addr.value[2];
	p->m_P3 = addr.value[1];
	p->m_P4	= addr.value[0];
	p->m_addr = m_addr;

	try
	{
		if( !m_port->SendData(p, 1000, NULL ) )
			throw m_port->GetErrCode();

		if( p->m_P4 != 0 )
		{
			throw (DWORD)p->m_P4;
		}

		ret = TRUE;
	}
	catch(DWORD ErrCode)
	{
		m_ErrCode = ErrCode;
		ret = FALSE;
	}
	delete p;
	return ret;
}

BOOL CController::SetBitData( WORD pa, WORD ba, BYTE Bit, BYTE nBits )
{
	BOOL ret;
	union tag_flashaddr addr;
	CPLT0001 *p = new CPLT0001();

	addr.addr = 0;
	addr.bits.pa = pa;
	addr.bits.ba = ba;
	
	p->m_CMD = SETBITDATA;
	p->m_P1 = ( (nBits & 0xf) << 4 ) | Bit;
	p->m_P2 = addr.value[2];
	p->m_P3 = addr.value[1];
	p->m_P4	= addr.value[0];
	p->m_addr = m_addr;



	try
	{
		if( !m_port->SendData(p, 1000, NULL ) )
			throw m_port->GetErrCode();

		if( p->m_P4 != 0 )
		{
			throw (DWORD)p->m_P4;
		}

		ret = TRUE;
	}
	catch(DWORD ErrCode)
	{
		m_ErrCode = ErrCode;
		ret = FALSE;
	}
	delete p;
	return ret;
}

BOOL CController::SetLongData(WORD pa, WORD ba, BYTE *Buf, DWORD nSize)
{
	BOOL ret;
	union tag_flashaddr addr;
	CPLT0001 *p = new CPLT0001();

	addr.addr = 0;
	addr.bits.pa = pa;
	addr.bits.ba = ba;
	
	p->m_CMD = SETLONGDATA;
	p->m_P1 = (BYTE)nSize;
	p->m_P2 = addr.value[2];
	p->m_P3 = addr.value[1];
	p->m_P4	= addr.value[0];
	p->m_addr = m_addr;
	p->m_data = Buf;
	p->m_dataSize = nSize;
	try
	{
		if( !m_port->SendData(p, 1000, NULL ) )
			throw m_port->GetErrCode();

		if( p->m_P4 != 0 )
		{
			throw (DWORD)p->m_P4;
		}

		if( p->m_dataSize < nSize )
			nSize = p->m_dataSize;

		CopyMemory( Buf, p->m_data, nSize);
		
		ret = TRUE;
	}
	catch(DWORD ErrCode)
	{
		m_ErrCode = ErrCode;
		ret = FALSE;
	}
	delete p;
	return ret;
}

BOOL CController::EsareFlash(WORD pa)
{

	return TRUE;
}

BOOL CController::SetStatus(BYTE node, BYTE opertion)
{

	BOOL ret;
	CPLT0001 *p = new CPLT0001();

	p->m_CMD = SETSTATUE;
	p->m_P1 = node;
	p->m_P2  = opertion;
	p->m_P3 = 0;
	p->m_P4  = 0;
	p->m_addr = m_addr;
	try
	{
		if( !m_port->SendData(p, 1000, NULL ) )
			throw m_port->GetErrCode();
		if( p->m_P4 != 0 )
		{
			throw (DWORD)p->m_P4;
		}

		ret = TRUE;
	}
	catch(DWORD ErrCode)
	{
		m_ErrCode = ErrCode;
		ret = FALSE;
	}
	delete p;
	return ret;
}

BOOL CController::GetStatus(BYTE node, BYTE *state)
{
	BOOL ret;
	CPLT0001 *p = new CPLT0001();

	p->m_CMD = GETSTATUS;
	p->m_P1 = node;
	p->m_P2  = 0;
	p->m_P3 = 0;
	p->m_P4  = 0;
	p->m_addr = m_addr;

	try
	{
		if( !m_port->SendData(p, 1000, NULL ) )
			throw m_port->GetErrCode();

		if( p->m_P4 != 0 )
		{
			throw (DWORD)p->m_P4;
		}
		*state = p->m_P1;
		ret = TRUE;
	}
	catch(DWORD ErrCode)
	{
		m_ErrCode = ErrCode;
		ret = FALSE;
	}
	delete p;
	return ret;
}

VOID CController::SetMachineAddr(BYTE dn)
{
	m_addr = dn;
}

BYTE CController::GetMachineAddr(VOID)
{
	return m_addr;
}

VOID CController::LinkBusPort(CBusProtocol *port)
{
	m_port = port;
}


BOOL CController::User_Add(DWORD nID, BYTE *nGroup, int nSize, BYTE attrib)
{
	BOOL ret;
	BYTE Buf[11];
	int i;
	CPLT0001 *p = new CPLT0001();

	Buf[0] = (nID & 0xff);
	Buf[1] = (nID >> 8) & 0xff;
	Buf[2] = (nID >> 16) & 0xff;
	Buf[3] = (nID >> 24) & 0xff;

	for( i = 0; i < nSize; i++)
		Buf[4 + i] = nGroup[i];	

	Buf[4 + i] = attrib;

	p->m_CMD = ADDUSER;
	p->m_P2 = 0;
	p->m_P3 = 0;
	p->m_P4	= 0;
	p->m_addr = m_addr;
	p->m_data = Buf;
	p->m_dataSize = 1 + 4 + i;
	try
	{
		if( !m_port->SendData(p, 1000, NULL ) )
			throw m_port->GetErrCode();

		if( p->m_P4 != 0 )
		{
			throw (DWORD)p->m_P4;
		}
		
		ret = TRUE;
	}
	catch(DWORD ErrCode)
	{
		m_ErrCode = ErrCode;
		ret = FALSE;
	}
	delete p;
	return ret;

}

BOOL CController::User_Del(DWORD nID)
{
	BOOL ret;


	CPLT0001 *p = new CPLT0001();



	p->m_CMD = DELUSER;
	p->m_P1 = (nID & 0xff);
	p->m_P2 = (nID >> 8) & 0xff;
	p->m_P3 = (nID >> 16) & 0xff;
	p->m_P4	= (nID >> 24) & 0xff;
	p->m_addr = m_addr;

	try
	{
		if( !m_port->SendData(p, 1000, NULL ) )
			throw m_port->GetErrCode();

		if( p->m_P4 != 0 )
		{
			throw (DWORD)p->m_P4;
		}
		
		ret = TRUE;
	}
	catch(DWORD ErrCode)
	{
		m_ErrCode = ErrCode;
		ret = FALSE;
	}
	delete p;
	return ret;
}

DWORD CController::GetErrCode(VOID)
{
	return m_ErrCode;
}

DWORD CController::GetMaxGroupNum(void)
{
	return GROUP_NUMBER;	
}

DWORD CController::GetGroupMaxTimeListNum(void)
	{
		return GROUP_TIMELIST_NUM;
	}

ULONG CController::InAddRef()
	{
		return 0;
	}

ULONG CController::InRelease()
	{		
		return 0;
	}
void CController::UlinkBusPort()
	{
// 		delete m_port;
		m_port = NULL;
	}
