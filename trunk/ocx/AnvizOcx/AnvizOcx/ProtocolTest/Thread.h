// Thread.h: interface for the CThread class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREAD_H__03098206_EDD6_4B25_AFC0_3A065A0B61C2__INCLUDED_)
#define AFX_THREAD_H__03098206_EDD6_4B25_AFC0_3A065A0B61C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CThread  
{
protected:
		HANDLE		m_EventExit;
private:
	BOOL		m_IsExit;

	HANDLE		m_ExitOver;
	HANDLE		m_hThread;
	DWORD		m_dwThreadID;
public:
	VOID SetExitOver(VOID);
	BOOL IsExitThread(void);
	static DWORD WINAPI ThreadProc( LPVOID lpParameter);
	DWORD ExitThread(void);

	virtual BOOL CreateThread(LPVOID param);
	CThread();
	virtual ~CThread();
	virtual DWORD Run(LPVOID) = 0;
	LPVOID		m_lparam;



};

#endif // !defined(AFX_THREAD_H__03098206_EDD6_4B25_AFC0_3A065A0B61C2__INCLUDED_)
