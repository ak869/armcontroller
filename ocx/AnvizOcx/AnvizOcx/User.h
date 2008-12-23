// User.h : Declaration of the CUser

#pragma once
#include "resource.h"       // main symbols

#include "AnvizOcx_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CUser

class ATL_NO_VTABLE CUser :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CUser, &CLSID_User>,
	public ISupportErrorInfo,
	public IDispatchImpl<IUser, &IID_IUser, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CUser()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_USER)


BEGIN_COM_MAP(CUser)
	COM_INTERFACE_ENTRY(IUser)
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

	STDMETHOD(AddGroup)(LONG GroupIndex);
	STDMETHOD(get_Groups)(IDoorGroups ** pVal);
	STDMETHOD(RemoveGroup)(LONG GroupIndex);
	STDMETHOD(SetAttrib)(LONG Index);
	STDMETHOD(ClearAttrib)(LONG Index);
	STDMETHOD(GetAttrib)(LONG Index, LONG* pVal);
	STDMETHOD(get_CardID)(LONG* pVal);
	STDMETHOD(get_AreaID)(LONG* pVal);
	STDMETHOD(get_UserID)(LONG* pVal);
	STDMETHOD(Updata)(void);
	STDMETHOD(Download)(void);
	};

OBJECT_ENTRY_AUTO(__uuidof(User), CUser)
