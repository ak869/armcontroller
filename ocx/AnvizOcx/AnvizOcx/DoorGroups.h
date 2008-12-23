// DoorGroups.h : Declaration of the CDoorGroups

#pragma once
#include "resource.h"       // main symbols

#include "AnvizOcx_i.h"

#include ".\Protocoltest\Controller.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDoorGroups

class ATL_NO_VTABLE CDoorGroups :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDoorGroups, &CLSID_DoorGroups>,
	public IDispatchImpl<IDoorGroups, &IID_IDoorGroups, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	CComVariant* m_VarVect;
	CController* m_parent;
	LONG	m_nSize;
public:
	CDoorGroups()
	{
		m_nSize = 0;
		m_VarVect = NULL;
		m_parent = NULL;

	}
	virtual ~CDoorGroups();


DECLARE_REGISTRY_RESOURCEID(IDR_DOORGROUPS)


BEGIN_COM_MAP(CDoorGroups)
	COM_INTERFACE_ENTRY(IDoorGroups)
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
	STDMETHOD(get_Item)(LONG Index, IDoorGroup** pVal);
	STDMETHOD(get_Count)(LONG* pVal);
	void Init(CController * pParent);
	};

OBJECT_ENTRY_AUTO(__uuidof(DoorGroups), CDoorGroups)
