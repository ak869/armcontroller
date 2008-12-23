// Thread.cpp: implementation of the CThread class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Thread.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CThread::CThread()
{
	m_ExitOver = CreateEvent(NULL,FALSE,FALSE,NULL);
	m_EventExit = CreateEvent(NULL,FALSE,FALSE,NULL);
		m_IsExit = TRUE;
}

CThread::~CThread()
{
	if( !m_IsExit )
	{
		ExitThread();
	}
	CloseHandle(m_ExitOver);
	CloseHandle(m_EventExit);
}

BOOL CThread::CreateThread(LPVOID lparam)
{
	this->m_lparam = lparam;
	ResetEvent(m_ExitOver);
	ResetEvent(m_EventExit);
	m_IsExit = FALSE;
	m_hThread = ::CreateThread(NULL,0,( LPTHREAD_START_ROUTINE)ThreadProc,(LPVOID)this,0,&m_dwThreadID);
	return TRUE;
}
/*
BOOL CThread::IsExitThread()
{
	return 	m_IsExit;
}
*/
DWORD CThread::ExitThread()
{
	DWORD code;
//	InterlockedExchange((long *)&m_IsExit,TRUE);
	::SetEvent(m_EventExit);
	if( WAIT_TIMEOUT == WaitForSingleObject(m_ExitOver, 1000) )
	{
		return WAIT_TIMEOUT;
	}
	GetExitCodeThread(m_hThread, &code);
	return code;
}

DWORD CThread::ThreadProc(LPVOID lpParameter)
{
	DWORD code;
	CThread *pThread = (CThread *)lpParameter;
	code = pThread->Run(pThread->m_lparam);	
	pThread->SetExitOver();
//	::ExitThread(0);	
	return 0;
}


BOOL CThread::IsExitThread()
{
	return m_IsExit;
}

VOID CThread::SetExitOver(VOID)
{
	m_IsExit = TRUE;
	::SetEvent(m_ExitOver);
}
