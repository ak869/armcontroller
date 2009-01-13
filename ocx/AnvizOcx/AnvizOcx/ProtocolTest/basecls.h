#pragma once

class CPort  
{
public:
	CPort(){}
	virtual ~CPort(){}
	virtual BOOL OpenPort(void) = 0;
	virtual VOID ClosePort(void) = 0;
	virtual BOOL ReadData(BYTE *Buffer, DWORD *nSize) = 0;
	virtual BOOL WriteData(BYTE *Buffer, DWORD nSize) = 0;
	virtual void ClearData(BYTE *Buffer, DWORD *nSize) = 0;
	virtual DWORD GetErrCode(void) = 0;

};


class CBusData
{
public:
	CBusData(){}
	virtual ~CBusData(){}
	virtual BYTE *GetBuffer(void) = 0;
	virtual DWORD GetBufferSize(void) = 0;
	virtual BOOL SetBuffer(BYTE *Buf, int nSize) = 0;
	virtual VOID *GetParam(long id) = 0;
	virtual VOID SetParam(long id, VOID *lParam) = 0;
	virtual DWORD GetErrCode(void) = 0;
//	virtual void RecvOver(void) = 0;
};

class CBus
{
public:
	CBus(){}
	virtual ~CBus(){}
	virtual BOOL SendData(CBusData *p) = 0;
	virtual DWORD GetErrCode(void) = 0;
};
#define ERR_PROTOCOL	0x1000
class CProtocol
{
public:
	CProtocol(){}
	virtual ~CProtocol(){}
	virtual DWORD GetErrCode(VOID) = 0;
	virtual DWORD CopyBufferSize(VOID) = 0;
	virtual DWORD CopyBuffer(BYTE *Buffer, int nSize) = 0;
	virtual BOOL GetBuffer(BYTE *Buffer, int nSize) = 0;
	virtual BOOL GetBuffer(CBusData *Buffer) = 0;
};
#define BUSPROTOCOL	0x2000
class CBusProtocol : 
	public CBus
{
public:
	CBusProtocol(){}
	virtual ~CBusProtocol(){}
	virtual BOOL SendData(CProtocol *p, DWORD nTimeout, LPVOID lParam) = 0;
};
#define ERR_DEVICE	0x3000
class CDevice
{
public:
	CDevice(){}
	virtual ~CDevice(){}

	virtual ULONG InRelease(void) = 0;
	virtual ULONG InAddRef(void) = 0;
	virtual void LinkBusPort(CBusProtocol *port) = 0;
	virtual void LoopFunc(void)
	{
		return;
	}
};