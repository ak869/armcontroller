// User.cpp : Implementation of CUser

#include "stdafx.h"
#include "User.h"


// CUser

STDMETHODIMP CUser::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IUser
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CUser::AddGroup(LONG GroupIndex)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CUser::get_Groups(IDoorGroups ** pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CUser::RemoveGroup(LONG GroupIndex)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CUser::SetAttrib(LONG Index)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CUser::ClearAttrib(LONG Index)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}



STDMETHODIMP CUser::GetAttrib(LONG Index, LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CUser::get_CardID(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CUser::get_AreaID(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CUser::get_UserID(LONG* pVal)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CUser::Updata(void)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}

STDMETHODIMP CUser::Download(void)
	{
	// TODO: Add your implementation code here

	return S_OK;
	}
