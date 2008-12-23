// DoorGroups.cpp : Implementation of CDoorGroups

#include "stdafx.h"

#include "DoorGroups.h"
#include "DoorGroup.h"


// CDoorGroups
CDoorGroups::~CDoorGroups()
	{
		if( m_VarVect != NULL)
		{
			delete [] m_VarVect;
			m_VarVect = NULL;
		}
		if( m_parent != NULL )
		{
			m_parent->InRelease();
//			((CComObject<CController> *)m_parent)->Release();
			m_parent = NULL;
		}
		m_nSize = 0;
	}

STDMETHODIMP CDoorGroups::get__NewEnum(IUnknown** pVal)
	{
	// TODO: Add your implementation code here
		if (pVal == NULL)
			return E_POINTER;
		*pVal = NULL;
		typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > enumvar;
	#pragma warning(suppress: 6014)
		enumvar* p = new enumvar;
		ATLASSERT(p);
		HRESULT hRes = p->Init(&m_VarVect[0], &m_VarVect[m_nSize], NULL, AtlFlagCopy);
		if (SUCCEEDED(hRes))
			hRes = p->QueryInterface(IID_IEnumVARIANT, (void**)pVal);
		return hRes;
	}

STDMETHODIMP CDoorGroups::get_Item(LONG Index, IDoorGroup** pVal)
	{
	// TODO: Add your implementation code here
		if (pVal == NULL)
			return E_POINTER;
		if( Index > m_nSize || Index < 1 )
		{
			return E_INVALIDARG;
		}
		*pVal = NULL;
		Index--;
		m_VarVect[Index].pdispVal->QueryInterface(IID_IDoorGroup, (void**)pVal);
		ATLASSERT(*pVal);
		return S_OK;
	}

STDMETHODIMP CDoorGroups::get_Count(LONG* pVal)
	{
	// TODO: Add your implementation code here
		if (pVal == NULL)
			return E_POINTER;
	*pVal = m_nSize;
	return S_OK;
	}

void CDoorGroups::Init(CController * pParent)
	{
		int n = 0;
		n = pParent->GetMaxGroupNum();	
		m_nSize = n;
		
		if (m_VarVect != NULL)
		{
			delete [] m_VarVect;
		}
		if( m_parent != NULL )
				m_parent->InRelease();

		m_parent =	pParent;
		m_parent->InAddRef();
		m_VarVect = new CComVariant[n];
		for (int i=0; i<n; i++)
		{
			// create an object
			// set arbitrary values
			HRESULT hRes;
			CComObject<CDoorGroup>* pGroup;
			
			hRes = CComObject<CDoorGroup>::CreateInstance(&pGroup);
			ATLASSERT(SUCCEEDED(hRes));


			pGroup->Init(m_parent,i);

			LPDISPATCH lpDisp = NULL;
			pGroup->QueryInterface(IID_IDispatch, (void**)&lpDisp);
			ATLASSERT(lpDisp);

			// create a variant and add it to the collection
			CComVariant& var = m_VarVect[i];
			var.vt = VT_DISPATCH;
			var.pdispVal = lpDisp;

		}
	}
