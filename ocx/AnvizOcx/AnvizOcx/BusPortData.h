// BusPortData.h : Declaration of the CBusPortData

#pragma once
#include "resource.h"       // main symbols

#include "AnvizOcx_i.h"
#include ".\Protocoltest\PortThread.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CBusPortData

class ATL_NO_VTABLE CBusPortData :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CBusPortData, &CLSID_BusPortData>,
	public CBusData,
	public IDispatchImpl<IBusPortData, &IID_IBusPortData, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	BYTE *m_Buffer;
	int m_nSize;
	DWORD m_TimeOut,m_ErrCode;
	LPVOID m_lParam;
	
public:
	CBusPortData()
	{
		m_Buffer = NULL;
		m_nSize = 0;
	}
	virtual ~CBusPortData()
	{
		if( m_Buffer )
			delete[] m_Buffer;
		m_Buffer = NULL;
		m_nSize = 0;
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
		return FALSE;
	}
	virtual VOID *GetParam(long id)
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
	virtual VOID SetParam(long id, VOID *lParam)
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
//				RecvOver();
				break;
		}		
	}
DECLARE_REGISTRY_RESOURCEID(IDR_BUSPORTDATA)


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


	VOID Init(CProtocol* p, DWORD nTimeOut, LPVOID lParam)
	{

		if( !realloc( p->CopyBufferSize() ) )
		{
			m_ErrCode = ERR_MEMORYPOOR;
			return;
		}
		if(  !p->CopyBuffer(m_Buffer, m_nSize) )
		{
			m_ErrCode = ERR_MEMORYPOOR;
			delete[] m_Buffer;
			m_Buffer = NULL;
			m_nSize = 0;
			return;
		}
		if( nTimeOut == 0 )
			nTimeOut = 1000;
		else
			m_TimeOut = nTimeOut;
		m_lParam = lParam;
/*
		m_ctime = GetTickCount();
		m_Event = NULL;
		m_hwnd = NULL;
		m_msg = 0;
		m_type = 0;
*/		
		return;
	}

	BOOL realloc(DWORD nSize)
	{
		if( m_Buffer != NULL )
			delete[] m_Buffer;
		m_Buffer = new BYTE [nSize];
		if( m_Buffer )
		{
			m_nSize = nSize;
			return TRUE;
		}
		nSize = 0;
		return FALSE;
	}
	STDMETHOD(get_Buffer)(LONG* pVal);
	STDMETHOD(get_Size)(LONG* pVal);
	STDMETHOD(SetBuffer)(LONG * buf, LONG nSize);
	STDMETHOD(get_Param)(LONG id, LONG * pVal);
	STDMETHOD(put_Param)(LONG id, LONG  newVal);
};

OBJECT_ENTRY_AUTO(__uuidof(BusPortData), CBusPortData)
