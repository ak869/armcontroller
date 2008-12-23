// DeviceLogs.h : Declaration of the CDeviceLogs

#pragma once
#include "resource.h"       // main symbols

#include "AnvizOcx_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDeviceLogs

class ATL_NO_VTABLE CDeviceLogs :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDeviceLogs, &CLSID_DeviceLogs>,
	public IDispatchImpl<IDeviceLogs, &IID_IDeviceLogs, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDeviceLogs()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DEVICELOGS)


BEGIN_COM_MAP(CDeviceLogs)
	COM_INTERFACE_ENTRY(IDeviceLogs)
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

	STDMETHOD(get__NewEnum)(IUnknown** pVal);
	STDMETHOD(get_Item)(LONG Index, IDeviceLog** pVal);
	STDMETHOD(Download)(LONG ID, VARIANT_BOOL* pRetVal);
	STDMETHOD(get_Count)(LONG* pVal);
	};

OBJECT_ENTRY_AUTO(__uuidof(DeviceLogs), CDeviceLogs)
