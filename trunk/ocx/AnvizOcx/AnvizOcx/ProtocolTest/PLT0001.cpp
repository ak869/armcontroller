// PLT0001.cpp: implementation of the CPLT0001 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PLT0001.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
/*
	b7	cmd:0/ack:1
	b6	Short:0/long:1
	b5 - b0 cmd
*/

#define CMD_FLAG				0x0
#define CMD_CMD					0x1
#define CMD_P1					0x2
#define ACK_DATAPACKSIZE		0x2
#define CMD_P2					0x3
#define CMD_P3					0x4
#define CMD_P4					0x5
#define ACK_RETURN				0x5
#define CMD_ADDR				0x6
#define CMD_XOR					0x7
#define CMD_SIZE				0x8
#define ACK_SIZE				0x8
#define PLT_VERSION				0xf1
CPLT0001::CPLT0001(BYTE *Buf, int nSize)
{
	m_ErrCode = 0;
	version = PLT_VERSION;
	m_data = NULL;
	m_dataSize = 0;
	Analysis_AckPack(Buf, nSize);
}
CPLT0001::CPLT0001()
{
	m_data = NULL;
	m_ErrCode = 0;
	version = PLT_VERSION;
	m_dataSize = 0;
}
CPLT0001::~CPLT0001()
{

}
BOOL CPLT0001::GetBuffer(CBusData *Buf)
{
	return Analysis_AckPack(Buf->GetBuffer(),Buf->GetBufferSize());
}
BOOL CPLT0001::GetBuffer(BYTE *Buffer, int nSize)
{
	return Analysis_AckPack(Buffer, nSize);
}
DWORD CPLT0001::CopyBuffer(BYTE *Buffer, int nSize)
{
	if( m_data == NULL )
	{
		return Construction_ShortPack(Buffer, nSize);
	}
	return Construction_LongPack(Buffer, nSize);
}
DWORD CPLT0001::CopyBufferSize(void)
{
	if( m_data == NULL )
	{
		return CMD_SIZE;
	}
	return CMD_SIZE + m_dataSize + 2;
}

BOOL CPLT0001::Analysis_AckPack(BYTE *Buf, int nSize)
{
	BYTE chk;
	int i;
	chk = 0;
	if( nSize < CMD_SIZE )
	{
		m_ErrCode = ERR_PACK;
		return FALSE;
	}
	if( Buf[CMD_FLAG] != (BYTE)version )
	{
		m_ErrCode = ERR_VERSION;
		return FALSE;
	}
	for( i = CMD_CMD; i < ACK_SIZE; i++ )
	{
		chk ^= Buf[i];
	}
	if( chk != 0 )
	{
		m_ErrCode =  ERR_CHECK;
		return FALSE;
	}

	if( (Buf[CMD_CMD] & 0x80) != 0x80 )
	{
		m_ErrCode = ERR_NOACK;
		return FALSE;
	}

	if( (m_CMD & 0x3f) != (Buf[CMD_CMD] & 0x3f) )
	{
		m_ErrCode = ERR_ACK;
		return FALSE;		
	}

	if( m_addr != Buf[CMD_ADDR])
	{
		m_ErrCode = ERR_MACHINENO;
		return FALSE;
	}

	m_P1 = Buf[CMD_P1];
	m_P2 = Buf[CMD_P2];
	m_P3 = Buf[CMD_P3];
	m_P4 = Buf[CMD_P4];

	if( (Buf[CMD_CMD] & 0x40) == 0x40 ) //is long pack
	{
		
		return Analysis_DataPack(Buf + ACK_SIZE, nSize - ACK_SIZE);
	}
	type = shortAck;
	return TRUE;
}

BOOL CPLT0001::Analysis_DataPack(BYTE *Buf, int nSize )
{
	BYTE chk;
	int i;
	chk = 0;
	if( nSize <= 2 )
	{
		m_ErrCode = ERR_PACK;
		return FALSE;
	}
	if( Buf[CMD_FLAG] != (BYTE)version )
	{
		m_ErrCode = ERR_VERSION;
		return FALSE;
	}
	for( i = 1; i < nSize; i++ )
	{
		chk ^= Buf[i];
	}
	if( chk != 0 )
	{
		m_ErrCode =  ERR_CHECK;
		return FALSE;
	}
	m_data = Buf + 1;
	type = longAck;
	m_dataSize = nSize - 2;
	return TRUE;
}

DWORD CPLT0001::Construction_ShortPack(BYTE *Buffer, int nSize)
{
	 BYTE chk;
	 if( nSize < CMD_SIZE )
	 {
		 m_ErrCode = ERR_BUFFERSIZE;
		 return 0xffffffff;
	 }
	 Buffer[CMD_FLAG] = (BYTE)version;
	 Buffer[CMD_CMD] = m_CMD;
	 Buffer[CMD_P1] = m_P1;
	 Buffer[CMD_P2] = m_P2;
	 Buffer[CMD_P3] = m_P3;
	 Buffer[CMD_P4] = m_P4;
	 Buffer[CMD_ADDR] = m_addr;
	 chk = 0;
	 for( int i = CMD_CMD; i < CMD_SIZE - 1; i++)
		chk ^= Buffer[i];
	 Buffer[CMD_XOR] = chk;
	 return CMD_SIZE;
}

DWORD CPLT0001::Construction_LongPack(BYTE *Buf, int nSize)
{
	 BYTE chk;
	 int i;
	 if( nSize < CMD_SIZE + m_dataSize + 2 )
	 {
		m_ErrCode = ERR_BUFFERSIZE;
		return 0xFFFFFFFF;
	 }
	 Buf[CMD_FLAG] = (BYTE)version;
	 Buf[CMD_CMD] = m_CMD;
	 Buf[CMD_P1] = (BYTE)m_dataSize;
	 Buf[CMD_P2] = m_P2;
	 Buf[CMD_P3] = m_P3;
	 Buf[CMD_P4] = m_P4;
	 Buf[CMD_ADDR] = m_addr;
	 chk = 0;
	 for( i = CMD_CMD; i < CMD_SIZE - 1; i++)
		chk ^= Buf[i];
	 Buf[CMD_XOR] = chk;

	 CopyMemory( Buf + CMD_SIZE + 1, m_data, m_dataSize );
	 Buf[CMD_SIZE] = (BYTE)version;
	 chk = 0;
	 for( i = CMD_SIZE + 1; i < m_dataSize + CMD_SIZE + 1; i++ )
		 chk ^= Buf[i];
	 Buf[i] = chk;
	 return (CMD_SIZE + m_dataSize + 2);
}

DWORD CPLT0001::GetErrCode(VOID)
{
	return m_ErrCode;
}
