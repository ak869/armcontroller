// TimeList.cpp : Implementation of CTimeList

#include "stdafx.h"
#include "TimeList.h"


// CTimeList


STDMETHODIMP CTimeList::get_Hour(enum Anviz_TimeType Attrib, LONG* pVal)
	{
	// TODO: Add your implementation code here
		if( m_pVal == NULL)
		{
			return E_INVALIDARG;	
		}
		switch(Attrib)
		{
			case t_Start:
				*pVal = (LONG)m_pVal->hour_start;
				break;
			case t_End:
				*pVal = (LONG)m_pVal->hour_end;
				break;
			default:
				return E_INVALIDARG;
			
		}
		return S_OK;
	}

STDMETHODIMP CTimeList::put_Hour(enum Anviz_TimeType Attrib, LONG newVal)
	{
	// TODO: Add your implementation code here
		if( m_pVal == NULL || newVal > 23 )
		{
			return E_INVALIDARG;	
		}
		switch(Attrib)
		{
			case t_Start:
				m_pVal->hour_start = newVal;
				break;
			case t_End:
				m_pVal->hour_end = newVal;
				break;
			default:
				return E_INVALIDARG;
			
		}
	return S_OK;
	}

STDMETHODIMP CTimeList::get_Minute(enum Anviz_TimeType Attrib, LONG* pVal)
	{
	// TODO: Add your implementation code here
		if( m_pVal == NULL)
		{
			return E_INVALIDARG;	
		}
		switch(Attrib)
		{
			case t_Start:
				*pVal = (LONG)m_pVal->minute_start;
				break;
			case t_End:
				*pVal = (LONG)m_pVal->minute_end;
				break;
			default:
				return E_INVALIDARG;
			
		}
		return S_OK;
	}

STDMETHODIMP CTimeList::put_Minute(enum Anviz_TimeType Attrib, LONG newVal)
	{
	// TODO: Add your implementation code here
		if( m_pVal == NULL || newVal > 59 )
		{
			return E_INVALIDARG;	
		}
		switch(Attrib)
		{
			case t_Start:
				m_pVal->minute_start = newVal;
				break;
			case t_End:
				m_pVal->minute_end = newVal;
				break;
			default:
				return E_INVALIDARG;
			
		}
		return S_OK;
	}

STDMETHODIMP CTimeList::get_Other(LONG* pVal)
	{
	// TODO: Add your implementation code here
 		if( m_pVal == NULL )
		{
			return E_INVALIDARG;	
		}
		*pVal =(LONG)m_pVal->other;


		return S_OK;
	}

STDMETHODIMP CTimeList::put_Other(LONG newVal)
	{
	// TODO: Add your implementation code here
 		if( m_pVal == NULL || newVal > 8 )
		{
			return E_INVALIDARG;	
		}
		m_pVal->other = newVal;
		return S_OK;
	}


void CTimeList::Init(LPDISPATCH parent,struct tag_timelist* pVal, long id)
	{
		m_parent = parent;
		m_parent->AddRef();
		m_pVal = pVal;
		m_id = id;
	}

STDMETHODIMP CTimeList::SetDay(enum Anviz_WeekValue WeekofDay)
	{
	// TODO: Add your implementation code here
  		if( m_pVal == NULL )
		{
			return E_INVALIDARG;	
		}
		m_pVal->weeks |=  ( 0x1 << WeekofDay ) ;
		return S_OK;
	}

STDMETHODIMP CTimeList::IsDay(enum Anviz_WeekValue WeekofDay , VARIANT_BOOL* pRetVal)
	{
	// TODO: Add your implementation code here
  		if( m_pVal == NULL )
		{
			return E_INVALIDARG;	
		}
		*pRetVal = VARIANT_FALSE;
		if( m_pVal->weeks & ( 0x1 << WeekofDay ) )
		{
			*pRetVal = VARIANT_TRUE;
		}
		return S_OK;
	}

STDMETHODIMP CTimeList::get_ID(LONG* pVal)
	{
	// TODO: Add your implementation code here
  		if( m_pVal == NULL )
		{
			return E_INVALIDARG;	
		}
		* pVal = m_id + 1;
		return S_OK;
	}
