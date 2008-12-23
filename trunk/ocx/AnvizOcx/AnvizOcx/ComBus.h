// ComBus.h : Declaration of the CComBus

#pragma once
#include "resource.h"       // main symbols

#include "BusPortData.h"
#include ".\Protocoltest\PortThread.h"
#include "AnvizOcx_i.h"
#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

class CQData:
	public CQParam,
	public CBusData
{
private:
	IBusPortData *m_data;
public:
	CQData(IBusPortData * data)
	{
		m_data = data;
	}
	virtual ~CQData()
	{
		if( m_data != NULL )
			m_data->Release();
		m_data = NULL;
	}
	virtual BYTE *GetBuffer()
	{
		LONG p;
		m_data->get_Buffer(&p);
		return (BYTE *)p;	
	}
	virtual DWORD GetBufferSize()
	{
		LONG nSize;
		m_data->get_Size(&nSize);
		return nSize;
	}
	virtual BOOL SetBuffer(BYTE *Buffer, int nSize)
	{
		m_data->SetBuffer((LONG *)Buffer, (LONG)nSize);
		return TRUE;
	}
	virtual VOID *GetParam(long id)
	{
		LONG t;
		m_data->get_Param(id,&t);
		return (void*)t;
	}
	virtual VOID SetParam(long id, VOID *lParam)
	{
		m_data->put_Param(id,(LONG)lParam);
		return;
	}
	virtual ULONG Release()
	{
		delete this;
		return 0;
	}

};

// CComBus

class ATL_NO_VTABLE CComBus :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CComBus, &CLSID_ComBus>,
	public ISupportErrorInfo,
	public CPortThread,
	public IDispatchImpl<IComBus, &IID_IComBus, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispatchImpl<IBus, &__uuidof(IBus), &LIBID_AnvizOcxLib, /* wMajor = */ 1, /* wMinor = */ 0>
	{
	public:
		CComBus()
			{
			}

		DECLARE_REGISTRY_RESOURCEID(IDR_COMBUS)


		BEGIN_COM_MAP(CComBus)
			COM_INTERFACE_ENTRY(IComBus)
			COM_INTERFACE_ENTRY2(IDispatch, IBus)
			COM_INTERFACE_ENTRY(ISupportErrorInfo)
			COM_INTERFACE_ENTRY(IBus)
		END_COM_MAP()

		// ISupportsErrorInfo
		STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


		DECLARE_PROTECT_FINAL_CONSTRUCT()

		HRESULT FinalConstruct()
			{
			return S_OK;
			}

		void FinalRelease()
			{
			}

	public:

		STDMETHOD(get_MachineItem)(IAnvizItems** pVal);
//		STDMETHOD(SendData)(VARIANT nVal);

		// IBus Methods
	public:
		STDMETHOD(SendData)(IBusPortData * newVal);
	};

OBJECT_ENTRY_AUTO(__uuidof(ComBus), CComBus)
