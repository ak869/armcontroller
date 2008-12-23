// Queque.h: interface for the CQueque class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUEQUE_H__9E23F86E_42E1_4098_B5D3_50B3F3801574__INCLUDED_)
#define AFX_QUEQUE_H__9E23F86E_42E1_4098_B5D3_50B3F3801574__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define ERR_FULL	1
#define ERR_EMPTY	2


template <class QData>
class CQueue  
{
private:
	QData *m_queue;
	int m_in,m_out;
	int m_Size;
	int m_ErrCode;
	CRITICAL_SECTION m_section;
public:
	DWORD GetErrCode(VOID)
	{
		return m_ErrCode;
	}
	HANDLE m_EvNoEmpty;
	VOID Clear(void)
	{
		m_ErrCode = 0;
		EnterCriticalSection(&m_section);
		while( m_in != m_out )
		{
			m_queue[m_out] = NULL;
			m_out++;
			m_out %= m_Size;
		}
		LeaveCriticalSection(&m_section);	
	}
	BOOL IsFull(void)
	{
		BOOL ret;
		m_ErrCode = 0;
		ret = FALSE;

		EnterCriticalSection(&m_section);
		if( (m_in + 1) % m_Size == m_out )
			ret = TRUE;
		LeaveCriticalSection(&m_section);

		return ret;		
	}
	BOOL IsEmpty(void)
	{
		BOOL ret;
		m_ErrCode = 0;

		ret = FALSE;
		EnterCriticalSection(&m_section);
		if( m_in == m_out )
			ret = TRUE;
		LeaveCriticalSection(&m_section);
		return ret;	
	}
	BOOL OutQueue(QData *lparam)
	{
		m_ErrCode = 0;
		if( IsEmpty() )
		{
			m_ErrCode = ERR_EMPTY;
			return FALSE;
		}
		EnterCriticalSection(&m_section);
		*lparam = m_queue[m_out];
		m_out++;
		m_out %= m_Size;
		LeaveCriticalSection(&m_section);
		if( IsEmpty() )
			ResetEvent(m_EvNoEmpty);
		return TRUE;	
	}
	BOOL InQueue(QData lparam)
	{
		m_ErrCode = 0;
		if( IsFull() )
		{
			m_ErrCode = ERR_FULL;
			return FALSE;
		}
		EnterCriticalSection(&m_section);
		SetEvent(m_EvNoEmpty);
		m_queue[m_in] = lparam;
		m_in++;
		m_in %= m_Size;
		LeaveCriticalSection(&m_section);
		return TRUE;	
	}
	CQueue(int nSize)
	{
		m_queue =  new QData[nSize + 1];
		InitializeCriticalSection(&m_section);
		m_EvNoEmpty =  CreateEvent(NULL, TRUE, FALSE, NULL);
		m_in = 0;
		m_out = 0;
		m_Size = nSize;
		m_ErrCode = 0;	
	}
	virtual ~CQueue()
	{
		Clear();
		delete [] m_queue;
		CloseHandle(m_EvNoEmpty);
		DeleteCriticalSection(&m_section);	
	}


};

#endif // !defined(AFX_QUEQUE_H__9E23F86E_42E1_4098_B5D3_50B3F3801574__INCLUDED_)
