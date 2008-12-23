// BusPortData.cpp : Implementation of CBusPortData

#include "stdafx.h"
#include "BusPortData.h"


// CBusPortData

STDMETHODIMP CBusPortData::get_Buffer(LONG* pVal)
	{
		if( pVal == NULL )
			return E_POINTER;
		*pVal = (LONG)m_Buffer;
		return S_OK;
	}
STDMETHODIMP CBusPortData::get_Size(LONG* pVal)
	{
		if( pVal == NULL )
			return E_POINTER;
		*pVal = m_nSize;
		return S_OK;
	}

STDMETHODIMP CBusPortData::SetBuffer(LONG * buf, LONG nSize)
	{
		if( buf == NULL )
			return E_POINTER;
		if( m_nSize < nSize )
		{
			if( m_Buffer != NULL )
				delete m_Buffer;
			m_Buffer = new BYTE[nSize];
		}
		CopyMemory(m_Buffer, (BYTE *)buf, nSize);
		m_nSize = nSize;
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