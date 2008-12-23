// PLT0001.h: interface for the CPLT0001 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLT0001_H__F836DE6A_BF55_43C6_B9C5_A5A433B3EC4B__INCLUDED_)
#define AFX_PLT0001_H__F836DE6A_BF55_43C6_B9C5_A5A433B3EC4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#define PROTOCOL_VERSION	0xf1
//#include "PortThread.h"
#include "basecls.h"

#define ERR_PACK		(0x07 + ERR_PROTOCOL)
#define ERR_MACHINENO	(0x01 + ERR_PROTOCOL)
#define ERR_VERSION		(0x02 + ERR_PROTOCOL)
#define ERR_CHECK		(0x03 + ERR_PROTOCOL)
#define ERR_NOACK		(0x04 + ERR_PROTOCOL)
#define ERR_ACK			(0x05 + ERR_PROTOCOL)
#define ERR_BUFFERSIZE	(0x06 + ERR_PROTOCOL)
//protocol


class CPLT0001:public CProtocol
{
private:
	DWORD m_ErrCode;
	DWORD version;
	BOOL Analysis_DataPack(BYTE *Buf, int nSize);
	BOOL Analysis_AckPack(BYTE *Buf, int nSize);
	DWORD Construction_LongPack(BYTE *Buf, int nSize);
	DWORD Construction_ShortPack(BYTE *Buf, int nSize);
public:
	DWORD GetErrCode(VOID);

	virtual DWORD CopyBufferSize(VOID);
	virtual DWORD  CopyBuffer(BYTE *Buffer, int nSize);
	virtual BOOL  GetBuffer(BYTE *Buffer, int nSized );
	BOOL  GetBuffer(CBusData *Buf);
	CPLT0001();
	CPLT0001(BYTE *Buf, int nSize);
	virtual ~CPLT0001();
	BYTE m_CMD;
	BYTE m_P1;
	BYTE m_P2;
	BYTE m_P3;
	BYTE m_P4;
	BYTE m_addr;
	BYTE *m_data;
	DWORD m_dataSize;
	enum
	{
		shortCMD = 0,
		longCmd,
		shortAck,
		longAck
	} type;
};

#endif // !defined(AFX_PLT0001_H__F836DE6A_BF55_43C6_B9C5_A5A433B3EC4B__INCLUDED_)
