// DeviceLog.h : Declaration of the CDeviceLog

#pragma once
#include "resource.h"       // main symbols

#include "AnvizOcx_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDeviceLog

class ATL_NO_VTABLE CDeviceLog :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDeviceLog, &CLSID_DeviceLog>,
	public ISupportErrorInfo,
	public IDispatchImpl<IDeviceLog, &IID_IDeviceLog, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDeviceLog()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DEVICELOG)


BEGIN_COM_MAP(CDeviceLog)
	COM_INTERFACE_ENTRY(IDeviceLog)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
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

	STDMETHOD(get_LogID)(LONG* pVal);
	STDMETHOD(get_AreaID)(LONG* pVal);
	STDMETHOD(get_CardID)(LONG* pVal);
	STDMETHOD(get_UserID)(LONG* pVal);
	STDMETHOD(get_DateTime)(DATE* pVal);
	STDMETHOD(get_Node)(LONG* pVal);
	STDMETHOD(get_EventID)(LONG* pVal);
	};

OBJECT_ENTRY_AUTO(__uuidof(DeviceLog), CDeviceLog)
