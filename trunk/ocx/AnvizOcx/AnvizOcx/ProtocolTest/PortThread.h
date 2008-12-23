// PortThread.h: interface for the CPortThread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PORTTHREAD_H__1509E167_5281_48F3_B387_4FAFD5E1C7BD__INCLUDED_)
#define AFX_PORTTHREAD_H__1509E167_5281_48F3_B387_4FAFD5E1C7BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ComPort.h"
#include "Thread.h"
#include "queque.h"

#define TIMEOUT_ID	0
#define LPARAM_ID	1
#define EVENT_ID	2
#define ERRCODE_ID	3

class CPortDataParam;

#define ERR_TIMEOUT		(0x01 + BUSPROTOCOL)
#define ERR_MEMORYPOOR	(0x02 + BUSPROTOCOL)

#define MAX_PACKSIZE	256

class CPortThread  : 
	public CBusProtocol,
	public CThread, 
	public CPort  
{

private:
	DWORD	m_ErrCode;
	CComPort *m_port;
	CQueue<CQParam> *m_qs;//,*m_qr;
	HANDLE m_Event[2];
	VOID *m_portAttrib;
public:	
	virtual VOID SendData(CProtocol *p, DWORD nTimeOut, LPVOID lParam);
	BOOL CreateThread(VOID);
	BOOL ReadData(CPortDataParam **p);
	BOOL WriteData(CPortDataParam *p );
	BOOL WriteData(BYTE *oBuf, DWORD oSize, DWORD nTimeOut,LPVOID lparam);
	BOOL WriteData(BYTE *oBuf, DWORD oSize);
	virtual DWORD GetErrCode(VOID);
	VOID SetPortAttrib(VOID *port);
	void ClearData(BYTE *Buffer, DWORD *nSize)
	{
		return;
	}
	BOOL ReadData(BYTE *iBuf, DWORD *iSize);

	VOID ClosePort(VOID);
	BOOL OpenPort();

	DWORD Run(LPVOID lparam);
	CPortThread();
	virtual ~CPortThread();


	BOOL SendData(CBusData * pVal);
	};

class CPortDataParam: 
	public CQParam,
	public CBusData
{
/*
protected:
	BYTE * allocRB(DWORD nSize);
	BYTE * allocSB(DWORD nSize);
*/

private:
	HANDLE	m_Event;
	HWND	m_hwnd;
	DWORD	m_msg;
	int		m_type;
	DWORD	m_ctime,m_stime,m_rtime;
	BYTE	*m_Buffer;
	int m_nSize;
	BOOL realloc(DWORD nSize);
	DWORD m_TimeOut;
	LPVOID m_lParam;
	void RecvOver(void);

public:
	virtual ULONG Release(VOID);
 	virtual VOID *GetParam(long id);
	virtual VOID SetParam(long id, VOID *lParam);
	virtual BYTE* GetBuffer(VOID);
	virtual DWORD GetBufferSize(VOID);
	virtual BOOL SetBuffer(BYTE *Buffer, int nSize);
	VOID SetSendTime(VOID);
	VOID UseMessage(HWND hwnd, DWORD msg);
	HANDLE UseEvent(VOID);

	CPortDataParam();
	CPortDataParam(BYTE *oBuf, int oSize, DWORD nTimeOut,LPVOID param);
	CPortDataParam(CProtocol *pPtl, DWORD nTimeOut,LPVOID param);
	virtual ~CPortDataParam();
	DWORD GetErrCode(void);
private:
	DWORD m_ErrCode;
	friend DWORD CPortThread::Run( LPVOID );
};
#endif // !defined(AFX_PORTTHREAD_H__1509E167_5281_48F3_B387_4FAFD5E1C7BD__INCLUDED_)
