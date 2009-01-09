// AMJ03.h : Declaration of the CAMJ03

#pragma once
#include "resource.h"       // main symbols

#include "AnvizOcx_i.h"
#include "DoorGroups.h"
#include "BusPortData.h"
#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif
#include ".\Protocoltest\Controller.h"
#define		BUS_QUEUE		1
#define		BUS_STACK		2
#define		WINDOW_QUEUE	3
#define		WINDOW_STACK	4
#define		DEVICE_QUEUE	5
#define		DEVICE_STACK	6
class CBusPort:public CBusProtocol
{
private:
	IBus *m_bus;
	IDevice *m_parent;
	DWORD m_ErrCode;
public:
	CBusPort(IDevice *parent,IBus *bus)
	{
		bus->AddRef();
		m_bus = bus;
		m_parent = parent;
		m_ErrCode = 0;
	}

	virtual ~CBusPort()
	{
		m_bus->Release();
		m_parent->Release();
	}
	virtual DWORD GetErrCode()
	{
		return m_ErrCode;
	}
	virtual BOOL SendData(CProtocol *p, DWORD nTimeout, LPVOID lParam)
	{
	    #pragma warning(suppress: 6014)
		m_ErrCode = 0;
		HANDLE e;

		IBusPortData* pDisp;
		m_parent->QueryInterface(IID_IBusPortData, (void**)&pDisp);
		ATLASSERT(pDisp);
/*

		pSar = new CComSafeArray<unsigned char>(p->CopyBufferSize(),0);
		for( i = 0; i 
		pSar->SetAt( i, ,TRUE);
*/
		if( nTimeout != 0 )
		{
			
			var

			pDisp->SetData(BUS_QUEUE,  )
			e = (HANDLE) t->GetParam(EVENT_ID);
			m_bus->SendData(pDisp);
//			
			WaitForSingleObject( e, INFINITE );
			if( t->GetErrCode() != 0 )
			{
				m_ErrCode = t->GetErrCode();
				pDisp->Release();
				return FALSE;
			}
			if( p->GetBuffer((CBusData *)t) )
			{
				pDisp->Release();
				m_ErrCode = p->GetErrCode();
				
				return FALSE;
			}
			pDisp->Release();
		}
		return TRUE;
	}
	virtual BOOL SendData( CBusData * newVal )
	{

		return TRUE;
	}

};


// CAMJ03

class ATL_NO_VTABLE CAMJ03 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAMJ03, &CLSID_AMJ03>,
	public ISupportErrorInfo,
	public IDispatchImpl<IAMJ03, &IID_IAMJ03, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0> ,
	public CController,
	public IDispatchImpl<IDevice, &__uuidof(IDevice), &LIBID_AnvizOcxLib, /* wMajor = */ 1, /* wMinor = */ 0>,
	public IDispatchImpl<IBusPortData, &__uuidof(IBusPortData), &LIBID_AnvizOcxLib, /* wMajor = */ 1, /* wMinor = */ 0>
	{
	private:
		CBusPort *m_bus;
	public:
		//	virtual ULONG AddRef_in(void);
		//	virtual ULONG Release_In(void);
		CAMJ03()
			{
				m_bus = NULL;
			}
		virtual ~CAMJ03()
			{
			if( m_bus )
				UnlinkBus();
			}

		DECLARE_REGISTRY_RESOURCEID(IDR_AMJ03)


		BEGIN_COM_MAP(CAMJ03)
			COM_INTERFACE_ENTRY(IAMJ03)
			COM_INTERFACE_ENTRY2(IDispatch, IDevice)
			COM_INTERFACE_ENTRY(ISupportErrorInfo)
			COM_INTERFACE_ENTRY(IDevice)
			COM_INTERFACE_ENTRY(IDataObject)
			COM_INTERFACE_ENTRY(IBusPortData)
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



		STDMETHOD(get_DoorGroups)(IDoorGroups** pVal);
		STDMETHOD(get_DoorStates)(IDoorStates** pVal);
		STDMETHOD(get_Attrib)(LONG Node, LONG* pVal);
		STDMETHOD(put_Attrib)(LONG Node, LONG newVal);
		STDMETHOD(get_Status)(LONG Node, LONG* pVal);
		STDMETHOD(put_Status)(LONG Node, LONG newVal);
		STDMETHOD(get_Users)(IUsers ** pVal);
		STDMETHOD(GetRTCTime)(DATE * pValue, VARIANT_BOOL* pRetVal);
		STDMETHOD(SetRTCTime)(DATE Value, VARIANT_BOOL* pRetVal);
		STDMETHOD(get_MachineAddr)(LONG* pVal);
		STDMETHOD(put_MachineAddr)(LONG pVal);
		STDMETHOD(GetDevVersion)(LONG * value, VARIANT_BOOL* pRetVal);
		STDMETHOD(get_Logs)(IDeviceLogs** pVal);

		virtual ULONG InAddRef(void);
		virtual ULONG InRelease(void);

		// IDevice Methods
	public:
		STDMETHOD(LinkBus)(IBus * newValue);
		STDMETHOD(UnlinkBus)(void);

		// IBusPortData Methods
	public:
		STDMETHOD(GetData)(LONG Index, VARIANT* Value);
		STDMETHOD(SetData)(LONG Index, VARIANT Value);
	};

OBJECT_ENTRY_AUTO(__uuidof(AMJ03), CAMJ03)
