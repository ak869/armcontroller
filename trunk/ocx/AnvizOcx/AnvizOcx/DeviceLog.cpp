// DeviceLog.cpp : Implementation of CDeviceLog

#include "stdafx.h"
#include "DeviceLog.h"


// CDeviceLog

STDMETHODIMP CDeviceLog::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IDeviceLog
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CDeviceLog::get_LogID(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDeviceLog::get_AreaID(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDeviceLog::get_CardID(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDeviceLog::get_UserID(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDeviceLog::get_DateTime(DATE* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDeviceLog::get_Node(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDeviceLog::get_EventID(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}
