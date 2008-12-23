// DoorGroup.h : Declaration of the CDoorGroup

#pragma once
#include "resource.h"       // main symbols

#include "AnvizOcx_i.h"
#include ".\Protocoltest\Controller.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDoorGroup

class ATL_NO_VTABLE CDoorGroup :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDoorGroup, &CLSID_DoorGroup>,
	public IDispatchImpl<IDoorGroup, &IID_IDoorGroup, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
protected:
	struct tag_group * m_group;
	friend class CTimeLists;
private:
	CController *m_parent;
	LONG	m_id;
public:
	CDoorGroup()
	{
		m_group = new struct tag_group;
		::ZeroMemory(m_group, sizeof(*m_group));
		m_group->power = 100;
		m_group->t[0].hour_start = 0;
		m_group->t[0].hour_end = 23;
		m_group->t[0].minute_start = 0;
		m_group->t[0].minute_end = 59;
		m_group->t[0].weeks = 0x3E;
		m_group->t[0].other = 0;
		m_parent = NULL;
		m_id = 0;
	}
	virtual ~CDoorGroup();

DECLARE_REGISTRY_RESOURCEID(IDR_DOORGROUP)


BEGIN_COM_MAP(CDoorGroup)
	COM_INTERFACE_ENTRY(IDoorGroup)
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

	STDMETHOD(get_Power)(LONG* pVal);
	STDMETHOD(put_Power)(LONG newVal);
	STDMETHOD(Updata)(void);
	STDMETHOD(Download)(void);
	STDMETHOD(get_TimeLists)(ITimeLists** pVal);
	STDMETHOD(get_ID)(LONG* pVal);
	void Init(CController * pParent, DWORD id);
	};

OBJECT_ENTRY_AUTO(__uuidof(DoorGroup), CDoorGroup)
