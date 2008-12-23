// BusPortData.h : Declaration of the CBusPortData

#pragma once
#include "resource.h"       // main symbols
#include ".\Protocoltest\PortThread.h"
#include "AnvizOcx_i.h"


#define EVENT_TYPE	1
#define MESSAGE_TYPE	2

// CBusPortData

class ATL_NO_VTABLE CBusPortData :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CBusPortData, &CLSID_BusPortData>,
	public CBusData,
	public IDispatchImpl<IBusPortData, &IID_IBusPortData, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	IDevice *m_parent;
	BYTE *m_Buffer;
	LONG m_nSize;
	DWORD m_ErrCode;
	DWORD m_TimeOut;
	LPVOID m_lParam;
	HANDLE	m_Event;
	HWND	m_hwnd;
	LONG	m_type;
public:
	CBusPortData()
	{
		m_parent = NULL;
		m_Buffer = NULL;
		m_nSize = 0;
		m_ErrCode = 0;
		m_Event = NULL;
		m_hwnd = NULL;
		m_TimeOut = 1000;
	}
	virtual ~CBusPortData()
	{
		if( m_parent )
			m_parent->Release();
		if( m_Buffer )
			delete[] m_Buffer;
		m_Buffer = NULL;
		m_nSize = 0;
	}
	virtual DWORD GetErrCode(void)
	{
		return m_ErrCode;
	}
	virtual BYTE *GetBuffer(void)
	{
		return m_Buffer;
	}
	virtual DWORD GetBufferSize(void) 
	{
		return m_nSize;
	}
	virtual BOOL SetBuffer(BYTE *Buf, int nSize)
	{
		if( !realloc(nSize) )
			return FALSE;
		::CopyMemory(m_Buffer, Buf, nSize);
		return TRUE;
	}
	BOOL realloc(LONG nSize)
	{
		if( m_nSize < nSize )
		{
			if( m_Buffer )
			{
				delete m_Buffer;
			}
			m_Buffer = new BYTE [nSize];
		}
		if( m_Buffer )
		{
			m_nSize = nSize;
			return TRUE;
		}
		m_nSize = 0;
		return FALSE;
	}
	virtual VOID *GetParam(long id)
	{
	  switch(id)
	  {
		  case PARENT_ID:
			  return (VOID *)m_parent;
		  case TIMEOUT_ID:
			  return (VOID *)m_TimeOut;
		  case LPARAM_ID:
			  return m_lParam;
		  case EVENT_ID:
			  m_Event = ::CreateEvent(NULL, FALSE, FALSE, NULL);
			  m_type = EVENT_TYPE;
			  return (VOID *)m_Event;
		  default:
			  return NULL;
	  }		
	}
	VOID RecvOver(void)
	{
		switch(m_type)
		{
		case MESSAGE_TYPE:
			IBusPortData *pbd;
			this->QueryInterface(IID_IBusPortData, (void**)&pbd);
			//ASS
			::PostMessage(m_hwnd, WM_MYMSG, 0, (LPARAM)pbd);
			break;
		case EVENT_TYPE:
			::SetEvent(m_Event);
			break;
		default:
			break;
		}
	}
	virtual VOID SetParam(long id, VOID *lParam)
	{
		switch(id)
		{
			case HWND_ID:
				m_hwnd = (HWND)lParam;
				m_type = MESSAGE_TYPE;
				break;
			case TIMEOUT_ID:
				m_TimeOut = (DWORD)lParam;
				break;
			case LPARAM_ID:
				m_lParam = lParam;
				break;
			case ERRCODE_ID:
				m_ErrCode = (DWORD)lParam;
				break;
			case SETEVENT_ID:
				RecvOver();
				break;
		}		
	}

	void Init( IDevice * pParent, CProtocol *p, DWORD nTimeout, LPVOID lParam)
	{
		if( !realloc( p->CopyBufferSize() ) )
		{
			return;
		}
		p->CopyBuffer( m_Buffer, m_nSize);
		m_TimeOut = nTimeout;
		m_lParam = lParam;

		m_parent = pParent;
		m_parent->AddRef();
	}

DECLARE_REGISTRY_RESOURCEID(IDR_BUSPORTDATA1)


BEGIN_COM_MAP(CBusPortData)
	COM_INTERFACE_ENTRY(IBusPortData)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(get_Buffer)(LONG* pVal);
	STDMETHOD(get_Size)(LONG* pVal);
	STDMETHOD(SetBuffer)(LONG Buf, LONG nSize);
	STDMETHOD(get_Param)(LONG id, LONG* pVal);
	STDMETHOD(put_Param)(LONG id, LONG newVal);
};

OBJECT_ENTRY_AUTO(__uuidof(BusPortData), CBusPortData)
