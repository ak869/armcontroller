// AMJ03.cpp : Implementation of CAMJ03

#include "stdafx.h"
#include "AMJ03.h"


// CAMJ03

STDMETHODIMP CAMJ03::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IAMJ03
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CAMJ03::get_DoorGroups(IDoorGroups** pVal)
	{
	// TODO: Add your implementation code here
	    #pragma warning(suppress: 6014)
		CComObject<CDoorGroups>* p = new CComObject<CDoorGroups>;
		p->Init((CController *)this);
		IDoorGroups* pDisp;
		p->QueryInterface(IID_IDoorGroups, (void**)&pDisp);
		ATLASSERT(pDisp);
		*pVal = pDisp;
		return S_OK;
	}

STDMETHODIMP CAMJ03::get_Attrib(LONG Node, LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CAMJ03::put_Attrib(LONG Node, LONG newVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CAMJ03::get_Status(LONG Node, LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CAMJ03::put_Status(LONG Node, LONG newVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CAMJ03::get_DoorStates(IDoorStates** pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CAMJ03::get_Users(IUsers ** pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CAMJ03::GetRTCTime(DATE * pValue, VARIANT_BOOL* pRetVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}



STDMETHODIMP CAMJ03::SetRTCTime(DATE Value, VARIANT_BOOL* pRetVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CAMJ03::GetDevVersion(LONG * value, VARIANT_BOOL* pRetVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CAMJ03::get_MachineAddr(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}
STDMETHODIMP CAMJ03::put_MachineAddr(LONG pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}
STDMETHODIMP CAMJ03::get_Logs(IDeviceLogs** pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}
/*
ULONG CAMJ03::AddRef_in(void)
	{
	return 0;//AddRef();
	}

ULONG CAMJ03::Release_In(void)
	{
	
	return 0;//Release();
	}
	*/
ULONG CAMJ03::InAddRef(void)
	{
		return AddRef();
	}

ULONG CAMJ03::InRelease(void)
	{
		return Release();
	}

STDMETHODIMP CAMJ03::LinkBus(IBus * newValue)
	{
	// TODO: Add your implementation code here
//		newValue->Send
		if( m_bus )
			UnlinkBus();

		IDevice *pdv;
		this->QueryInterface(IID_IDevice,(void**)&pdv);
		ATLASSERT(pdv);
		m_bus = new CBusPort( pdv, newValue);
		CController::LinkBusPort( (CBusProtocol *)m_bus );
		return S_OK;
	}

STDMETHODIMP CAMJ03::UnlinkBus(void)
	{
	// TODO: Add your implementation code here

		CController::UlinkBusPort();
		delete m_bus;
		return S_OK;
	}
