// PortThread.cpp: implementation of the CPortThread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PortThread.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define MAX_QUEQUE_SIZE	3
CPortThread::CPortThread()
{
	m_qs = new CQueue<CBusData *>(MAX_QUEQUE_SIZE);
//	m_qr = new CQueque(MAX_QUEQUE_SIZE);
	m_port = new CComPort();
	m_Event[0] = m_qs->m_EvNoEmpty;
	m_Event[1] = m_EventExit;
	m_portAttrib = NULL;
}

CPortThread::~CPortThread()
{
//	delete m_qr;
	delete m_qs;
	delete m_port;
}

DWORD CPortThread::Run(LPVOID lparam)
{
	DWORD ret;
	DWORD nBytes;
	BYTE	buf[MAX_PACKSIZE];
	CBusData *p;
	
	while(1)
	{
		Sleep(30);
		ret = WaitForMultipleObjects(2, m_Event, FALSE, INFINITE);
		switch( ret - WAIT_OBJECT_0 )
		{
		case 0:			
			m_qs->OutQueue( &p);
			m_port->SetTimeOut( (DWORD)( p->GetParam(TIMEOUT_ID) ) );
//			p->SetSendTime();
			m_port->WriteData(p->GetBuffer(), p->GetBufferSize());
			nBytes = sizeof(buf);			
			m_port->ReadData(buf, (DWORD *)&nBytes);
			p->SetBuffer(buf, nBytes);
			if( p->GetBufferSize() == 0 )
				p->SetParam(ERRCODE_ID, (void *)ERR_TIMEOUT);
			p->SetParam(SETEVENT_ID,NULL);
			break;
		case 1:
			return 0;
		}
	}
	return 0;
}

BOOL CPortThread::OpenPort()
{
	return m_port->OpenCom(_T("COM2"));
//	TRUE;
}

VOID CPortThread::ClosePort(VOID)
{
	m_port->ClosePort();
}

BOOL CPortThread::WriteData(BYTE *oBuf, DWORD oSize, DWORD nTimeOut,LPVOID lparam)
{
	CPortDataParam *p = new CPortDataParam(oBuf, oSize, nTimeOut, lparam);
	if( m_qs->InQueue(p) )
		return TRUE;
	m_ErrCode = m_qs->GetErrCode();
	return FALSE;
}

BOOL CPortThread::ReadData(BYTE *iBuf, DWORD *iSize)
{
/*	CPortDataParam *p;
	WaitForSingleObject(m_qr->m_EvNoEmpty, INFINITE);
	m_qr->OutQueque((CQParam**)&p);
	if( p->GetErrCode() )
	{
		m_ErrCode = p->GetErrCode();
		delete p;
		return FALSE;
	}
	if( p->ReadRecvBufferSize() > *iSize )
	{
		delete p;
		m_ErrCode = Err_MEMORYPOOR;
		return FALSE;
	}
	*iSize = p->ReadRecvBufferSize();
	*iSize = p->ReadRecvBuffer(iBuf, *iSize);
*/	
	return TRUE;
}

CPortDataParam::CPortDataParam()
{
	m_Buffer = NULL;
	m_nSize = 0;

	m_TimeOut = 0;
	m_lParam = NULL;
	m_ErrCode = 0;

	m_ctime = GetTickCount();

	m_Event = NULL;
	m_hwnd = NULL;
	m_msg = 0;
	m_type = 0;
}
CPortDataParam::CPortDataParam(	CProtocol *pPtl,DWORD nTimeOut, LPVOID lParam)
{
	m_nSize = 0;
	m_Buffer = NULL;
	if( !realloc( pPtl->CopyBufferSize() ) )
	{
		m_ErrCode = ERR_MEMORYPOOR;
		return;
	}
	if(  !pPtl->CopyBuffer(m_Buffer, m_nSize) )
	{
		m_ErrCode = ERR_MEMORYPOOR;
		LocalFree(m_Buffer);
		m_nSize = 0;
		return;
	}
	m_TimeOut = nTimeOut;
	m_lParam = lParam;

	m_ctime = GetTickCount();
	m_Event = NULL;
	m_hwnd = NULL;
	m_msg = 0;
	m_type = 0;
}
CPortDataParam::CPortDataParam(BYTE *Buf, int nSize, DWORD nTimeOut, LPVOID lparam)
{
	m_nSize = 0;
	m_Buffer = NULL;
	m_TimeOut = nTimeOut;
	m_lParam = lparam;
	if( !realloc(nSize) )
	{
		m_ErrCode = ERR_MEMORYPOOR;
		return;
	}
	CopyMemory(m_Buffer, Buf, nSize);
	m_ErrCode = 0;
	m_ctime = GetTickCount();

	m_Event = NULL;
	m_hwnd = NULL;
	m_msg = 0;
	m_type = 0;
}
CPortDataParam:: ~CPortDataParam()
{
	TCHAR disp[128];
	if( m_Event )
		CloseHandle(m_Event);
	if( m_Buffer )
	{
		LocalFree(m_Buffer);
		m_Buffer = NULL;
		m_nSize = 0;
	}
 
	wsprintf(disp,_T("object[0x%08lx]:Exist Time(%d), Tran Time(%d)\n"),
		(unsigned int)this,GetTickCount() - m_ctime, m_stime);
	OutputDebugString(disp);
}
ULONG CPortDataParam::Release(VOID)
{
	delete this;
	return 0;
}


DWORD CPortDataParam::GetErrCode()
{
	return m_ErrCode;
}



VOID CPortThread::SetPortAttrib(VOID *port)
{
	m_portAttrib = port;
}

DWORD CPortThread::GetErrCode(VOID)
{
	return m_ErrCode;
}

BOOL CPortThread::WriteData(BYTE *oBuf, DWORD oSize)
{
	return WriteData(oBuf, oSize, 1000, NULL);
}

BOOL CPortThread::WriteData(CBusData *p)
{

	if( m_qs->InQueue(p) )
		return TRUE;
	m_ErrCode = m_qs->GetErrCode();
	return	TRUE;
}

BOOL CPortThread::ReadData(CBusData **p)
{
/*	WaitForSingleObject(m_qr->m_EvNoEmpty, INFINITE);
	m_qr->OutQueque((CQParam **)p);
	if( (*p)->GetErrCode() )
	{
		m_ErrCode = (*p)->GetErrCode();
		delete p;
		return FALSE;
	}
*/
	return TRUE;
}


BOOL CPortThread::CreateThread(VOID)
{
	return ((CThread*)this)->CreateThread(NULL);
}

VOID CPortDataParam::RecvOver(VOID)
{
	m_stime = GetTickCount() - m_stime;
	switch( m_type )
	{
	case 1:
		::SetEvent(m_Event);
		break;
	case 2:
		::PostMessage(m_hwnd, m_msg, 0, (LPARAM)this);
		break;
	}
}

HANDLE CPortDataParam::UseEvent(VOID)
{
	m_type = 1;
	if( m_Event == NULL )
	{
		return m_Event = CreateEvent(NULL, FALSE, FALSE, NULL);
	}
	ResetEvent(m_Event);
	return m_Event;
}
//::PostMessage(((CConnect*)p)->hWnd, WM_MYMSG, (WPARAM)p, 0 );

VOID CPortDataParam::UseMessage(HWND hwnd, DWORD msg)
{
	m_type = 2;
	m_hwnd = hwnd;
	m_msg = msg;
}

VOID CPortDataParam::SetSendTime(VOID)
{
	m_stime = GetTickCount();
 }

DWORD CPortDataParam::GetBufferSize()
{
	return m_nSize;
}
BYTE *CPortDataParam::GetBuffer()
{
	return m_Buffer;
}
BOOL CPortDataParam::realloc(DWORD nSize)
{
	if( m_Buffer != NULL )
		LocalFree(m_Buffer);
	m_Buffer = (BYTE *)LocalAlloc(LPTR, nSize);
	if( m_Buffer )
	{
		m_nSize = nSize;
		return TRUE;
	}
	return FALSE;
}
VOID * CPortDataParam::GetParam(long id)
{
	  switch(id)
	  {
		  case TIMEOUT_ID:
			  return (VOID *)m_TimeOut;
		  case LPARAM_ID:
			  return m_lParam;
		  default:
			  return NULL;
	  }
}
VOID  CPortDataParam::SetParam(long id, VOID *lParam)
{
	switch(id)
	{
		case TIMEOUT_ID:
			m_TimeOut = (DWORD)lParam;
			break;
		case LPARAM_ID:
			m_lParam = lParam;
			break;
		case ERRCODE_ID:
			m_ErrCode = (DWORD)lParam;
			break;
		case EVENT_ID:
		    RecvOver();
			break;
	}
}

BOOL CPortDataParam::SetBuffer(BYTE *Buffer, int nSize)
{
	if( m_nSize < nSize )
	{
		if( m_Buffer )
		{
			LocalFree(m_Buffer);
		}
		m_Buffer = (BYTE *)LocalAlloc(LPTR,nSize);
	}
	if( m_Buffer )
	{
		m_nSize = nSize;
		return TRUE;
	}
	m_nSize = 0;
	return FALSE;
}
BOOL CBusPortThread::SendData(CBusData * pVal)
{
	return WriteData(pVal);
}
BOOL CBusPortThread::SendData(CProtocol *p, DWORD nTimeOut, LPVOID lParam)
{
	HANDLE e;
	CPortDataParam *t = NULL;
	m_ErrCode = 0;
	try
	{		
		t = new CPortDataParam(p, nTimeOut, lParam);
		if( !t->GetBufferSize() )
		{
			throw t->GetErrCode();	
		}
		e = t->UseEvent();
		
		if( !SendData((CBusData*)t) )
		{
			throw CPortThread::GetErrCode();
		}

		WaitForSingleObject(e, INFINITE);
		if( t->GetErrCode() )
			throw t->GetErrCode();

		if( !p->GetBuffer((CBusData *)t) )
			throw p->GetErrCode();
	}
	catch(DWORD err)
	{
		m_ErrCode = err;
	}
	if( t )
		delete t;
	if( m_ErrCode )
		return FALSE;
	return TRUE;
}

BOOL CPortThread::OpenPort(TCHAR *port, LONG baundrate)
{
	return m_port->OpenCom(port, baundrate);
}
