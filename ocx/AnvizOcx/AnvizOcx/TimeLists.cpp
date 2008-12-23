// TimeLists.cpp : Implementation of CTimeLists

#include "stdafx.h"
#include "TimeLists.h"


// CTimeLists


STDMETHODIMP CTimeLists::get_Item(LONG Index, ITimeList** pVal)
	{
	// TODO: Add your implementation code here
	if (pVal == NULL)
		return E_POINTER;
	if( Index < 1 || Index > m_nSize )
	{
		
		return E_INVALIDARG;
	}
	*pVal = NULL;
	Index--;
	m_VarVect[Index].pdispVal->QueryInterface(IID_ITimeList, (void**)pVal);
	ATLASSERT(*pVal);
	return S_OK;
	}

STDMETHODIMP CTimeLists::get__NewEnum(IUnknown** pVal)
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

STDMETHODIMP CTimeLists::get_Count(LONG* pVal)
	{
	// TODO: Add your implementation code here
		if (pVal == NULL)
			return E_POINTER;
		*pVal = m_nSize;
		return S_OK;
	}

void CTimeLists::Init( LPDISPATCH pParent, struct tag_timelist *pVal, LONG nSize )
	{
		int n;
		n = nSize / sizeof( *pVal );
		m_nSize = n;
		m_parent = pParent;	
	  
		if( m_VarVect )
			delete [] m_VarVect;

		m_VarVect = new	 CComVariant[n];
		for( int i = 0; i < n; i++ )
		{
		// set arbitrary values
			HRESULT hRes;
			CComObject<CTimeList>* pTList;
			
			hRes = CComObject<CTimeList>::CreateInstance(&pTList);
			ATLASSERT(SUCCEEDED(hRes));


			pTList->Init(pParent, pVal + i, i);

			LPDISPATCH lpDisp = NULL;
			pTList->QueryInterface(IID_IDispatch, (void**)&lpDisp);
			ATLASSERT(lpDisp);

			// create a variant and add it to the collection
			CComVariant& var = m_VarVect[i];
			var.vt = VT_DISPATCH;
			var.pdispVal = lpDisp;				
 			
		}
		m_parent->Release();
	}
