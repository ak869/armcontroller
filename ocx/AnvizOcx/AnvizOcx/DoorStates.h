// DoorStates.h : Declaration of the CDoorStates

#pragma once
#include "resource.h"       // main symbols

#include "AnvizOcx_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDoorStates

class ATL_NO_VTABLE CDoorStates :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDoorStates, &CLSID_DoorStates>,
	public IDispatchImpl<IDoorStates, &IID_IDoorStates, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDoorStates()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DOORSTATES)


BEGIN_COM_MAP(CDoorStates)
	COM_INTERFACE_ENTRY(IDoorStates)
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

	STDMETHOD(get_Item)(IDoorState** pVal);
	STDMETHOD(get__NewEnum)(IUnknown** pVal);
	STDMETHOD(get_Count)(LONG* pVal);
	};

OBJECT_ENTRY_AUTO(__uuidof(DoorStates), CDoorStates)
