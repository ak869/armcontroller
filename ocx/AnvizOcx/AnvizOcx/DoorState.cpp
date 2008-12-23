// DoorState.cpp : Implementation of CDoorState

#include "stdafx.h"
#include "DoorState.h"


// CDoorState

STDMETHODIMP CDoorState::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IDoorState
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CDoorState::get_TimeList(ITimeList** pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDoorState::get_State(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDoorState::put_State(LONG newVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDoorState::Updata(void)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDoorState::Download(void)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDoorState::get_ID(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}
