// Anviz.cpp : Implementation of CAnviz
#include "stdafx.h"
#include "Anviz.h"
#include "AnvizItems.h"

// CAnviz

STDMETHODIMP CAnviz::get_BusItems(IAnvizItems** pVal)
	{
	// TODO: Add your implementation code here
#pragma warning(suppress: 6014)
	CComObject<CAnvizItems>* p = new CComObject<CAnvizItems>;
	IAnvizItems* pDisp;
	p->QueryInterface(IID_IAnvizItems, (void**)&pDisp);
	ATLASSERT(pDisp);
	*pVal =  pDisp;
	return S_OK;
}
