// ComPort.h: interface for the CComPort class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPORT_H__17AED028_8AAA_46DE_BDBB_34B367D8E539__INCLUDED_)
#define AFX_COMPORT_H__17AED028_8AAA_46DE_BDBB_34B367D8E539__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "basecls.h"
class CComPort : public CPort   
{
private:
	OVERLAPPED read_o,write_o;
	HANDLE m_hCom;
	DWORD m_ErrCode;
public:
	BOOL OpenCom(TCHAR *port, LONG baundrate);
	VOID SetTimeOut(DWORD RecvTimeOut);
	void ClearData(BYTE *Buffer, DWORD *nSize);
	DWORD GetErrCode(void);

	BOOL WriteData(BYTE *Buffer, DWORD nSize);
	BOOL ReadData(BYTE *Buffer,DWORD *nSize);
	void CloseCom(void);
	BOOL OpenPort(void);
	VOID ClosePort(void);
	BOOL OpenCom(TCHAR *);
	CComPort();
	virtual ~CComPort();

};

#endif // !defined(AFX_COMPORT_H__17AED028_8AAA_46DE_BDBB_34B367D8E539__INCLUDED_)
