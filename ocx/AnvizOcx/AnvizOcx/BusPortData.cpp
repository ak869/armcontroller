// BusPortData.cpp : Implementation of CBusPortData

#include "stdafx.h"
#include "BusPortData.h"


// CBusPortData

// CBusPortData

STDMETHODIMP CBusPortData::get_Buffer(LONG* pVal)
	{
		if( pVal == NULL )
			return E_POINTER;
		*pVal = (LONG)GetBuffer();
		return S_OK;
	}
STDMETHODIMP CBusPortData::get_Size(LONG* pVal)
	{
		if( pVal == NULL )
			return E_POINTER;
		*pVal = GetBufferSize();
		return S_OK;
	}

STDMETHODIMP CBusPortData::SetBuffer(LONG Buf, LONG nSize)
	{
		if( Buf == NULL )
			return E_POINTER;
		if( !SetBuffer((BYTE *)Buf, (int)nSize) )
			return E_FAIL;		
		return S_OK;
	}
STDMETHODIMP CBusPortData::get_Param(LONG id, LONG * pVal)
	{
		if( pVal == NULL )
			return E_POINTER;		
		*pVal = (LONG)GetParam(id);
		return S_OK;
	
	}
STDMETHODIMP CBusPortData::put_Param(LONG id, LONG  newVal)
	{
		  SetParam(id,(void *)newVal);
		  return S_OK;
	}