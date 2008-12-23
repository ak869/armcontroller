// DoorGroup.cpp : Implementation of CDoorGroup

#include "stdafx.h"
#include "DoorGroup.h"
#include "TimeLists.h"

// CDoorGroup
CDoorGroup::~CDoorGroup()
	{
		delete m_group;
		if( m_parent != NULL )
		{
			m_parent->InRelease();
		}
		m_parent = NULL;
	}


STDMETHODIMP CDoorGroup::get_Power(LONG* pVal)
	{
	// TODO: Add your implementation code here
		if( m_parent == NULL )
		{
			return E_INVALIDARG;
		}		
		if (pVal == NULL)
			return E_POINTER;
		*pVal = m_group->power;
		return S_OK;
	}

STDMETHODIMP CDoorGroup::put_Power(LONG newVal)
	{
	// TODO: Add your implementation code here
		if( m_parent == NULL )
		{
			return E_INVALIDARG;
		}
		if( newVal <= 100 )
		{
			m_group->power = (unsigned char)newVal;	
		}
		return S_OK;
	}


STDMETHODIMP CDoorGroup::Updata(void)
	{
	// TODO: Add your implementation code here
		if( m_parent == NULL )
		{
			return E_INVALIDARG;
		}

		if( !m_parent->SetLongData( GROUP_PAGE + (m_id / 14), (m_id % 14),
			 (BYTE *)m_group, GROUP_SIZE - 1 ) )
		{			
			return S_FALSE;	
		}
		return S_OK;
	}

STDMETHODIMP CDoorGroup::Download(void)
	{
	// TODO: Add your implementation code here
 		if( m_parent == NULL )
		{
			return E_INVALIDARG;
		}
		if( !m_parent->GetLongData( GROUP_PAGE + (m_id / 14), (m_id % 14),
			 (BYTE *)m_group, GROUP_SIZE ) )
		{
			
			return S_FALSE;	
		}
		return S_OK;
	}



STDMETHODIMP CDoorGroup::get_TimeLists(ITimeLists** pVal)
	{
	// TODO: Add your implementation code here
 		if (pVal == NULL)
			return E_POINTER;
		*pVal = NULL;
	    #pragma warning(suppress: 6014)
		CComObject<CTimeLists>* p = new CComObject<CTimeLists>;
		
		LPDISPATCH	pParent;
		this->QueryInterface(IID_IDispatch, (void**)&pParent);
		ATLASSERT(pParent);

		p->Init(pParent, m_group->t, sizeof( m_group->t ));

		p->QueryInterface(IID_ITimeLists, (void**)pVal);
		ATLASSERT(pVal);

		return S_OK;
	}

STDMETHODIMP CDoorGroup::get_ID(LONG* pVal)
	{
	// TODO: Add your implementation code here
		if (pVal == NULL)
			return E_POINTER;
		* pVal = m_id + 1;
		return S_OK;
	}

void CDoorGroup::Init( CController *pParent, DWORD id)
	{
		if( m_parent != NULL )
		{
			m_parent->InRelease();
		}
		m_parent =	pParent;
		m_parent->InAddRef();

		m_id = (LONG)(id);
	}
