// TimeList.h : Declaration of the CTimeList

#pragma once
#include "resource.h"       // main symbols

#include "AnvizOcx_i.h"
#include ".\Protocoltest\Controller.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CTimeList

class ATL_NO_VTABLE CTimeList :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTimeList, &CLSID_TimeList>,
	public IDispatchImpl<ITimeList, &IID_ITimeList, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	struct tag_timelist* m_pVal;
	LONG m_id;
	LPDISPATCH m_parent;
public:
	CTimeList()
	{
		m_pVal = NULL;
		m_id = 0;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TIMELIST)


BEGIN_COM_MAP(CTimeList)
	COM_INTERFACE_ENTRY(ITimeList)
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

	STDMETHOD(get_Hour)(enum Anviz_TimeType Attrib, LONG* pVal);
	STDMETHOD(put_Hour)(enum Anviz_TimeType Attrib, LONG newVal);
	STDMETHOD(get_Minute)(enum Anviz_TimeType Attrib, LONG* pVal);
	STDMETHOD(put_Minute)(enum Anviz_TimeType Attrib, LONG newVal);
	STDMETHOD(get_Other)(LONG* pVal);
	STDMETHOD(put_Other)(LONG newVal);

	void Init(LPDISPATCH parent,struct tag_timelist* pVal, long id);

	virtual ~CTimeList(void)
		{
			if( m_parent != NULL )
				m_parent->Release();
		}
	STDMETHOD(SetDay)(enum Anviz_WeekValue WeekofDay);
	STDMETHOD(IsDay)(enum Anviz_WeekValue WeekofDay , VARIANT_BOOL* pRetVal);
	STDMETHOD(get_ID)(LONG* pVal);
	};

OBJECT_ENTRY_AUTO(__uuidof(TimeList), CTimeList)
