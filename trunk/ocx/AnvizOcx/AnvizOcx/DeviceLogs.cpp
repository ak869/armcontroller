// DeviceLogs.cpp : Implementation of CDeviceLogs

#include "stdafx.h"
#include "DeviceLogs.h"


// CDeviceLogs


STDMETHODIMP CDeviceLogs::get__NewEnum(IUnknown** pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDeviceLogs::get_Item(LONG Index, IDeviceLog** pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDeviceLogs::Download(LONG ID, VARIANT_BOOL* pRetVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CDeviceLogs::get_Count(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}
