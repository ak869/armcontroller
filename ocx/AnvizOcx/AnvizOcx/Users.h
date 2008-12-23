// Users.h : Declaration of the CUsers

#pragma once
#include "resource.h"       // main symbols

#include "AnvizOcx_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CUsers

class ATL_NO_VTABLE CUsers :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CUsers, &CLSID_Users>,
	public IDispatchImpl<IUsers, &IID_IUsers, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CUsers()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_USERS)


BEGIN_COM_MAP(CUsers)
	COM_INTERFACE_ENTRY(IUsers)
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

	STDMETHOD(get_Item)(VARIANT Index,IUser** pVal);
	STDMETHOD(get__NewEnum)(IUnknown** pVal);
	STDMETHOD(Add)(LONG Area, LONG ID, LONG LongID, IUser** pVal);
	STDMETHOD(Remove)(LONG Area, LONG ID, LONG LongID);
	STDMETHOD(Updata)(void);
	STDMETHOD(Download)(void);
	STDMETHOD(get_Count)(LONG* pVal);
	};

OBJECT_ENTRY_AUTO(__uuidof(Users), CUsers)
