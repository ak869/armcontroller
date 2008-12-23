// ComBus.cpp : Implementation of CComBus

#include "stdafx.h"
#include "ComBus.h"
#include "AnvizItems.h"

// CComBus

STDMETHODIMP CComBus::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IComBus
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CComBus::get_MachineItem(IAnvizItems** pVal)
	{
	// TODO: Add your implementation code here
#pragma warning(suppress: 6014)
	CComObject<CAnvizItems>* p = new CComObject<CAnvizItems>;
	IAnvizItems* pDisp;
	IBus *pbus;
	this->QueryInterface(IID_IBus,(void**)&pbus);
	ATLASSERT(pbus);
	p->Init(pbus);
	p->QueryInterface(IID_IAnvizItems, (void**)&pDisp);
	ATLASSERT(pDisp);
	*pVal =  pDisp;
	return S_OK;
	}


STDMETHODIMP CComBus::SendData(IBusPortData * newVal)
	{
	if( newVal == NULL )
		return E_POINTER;
	CQData *p = new CQData(newVal);
	CPortThread::SendData((CBusData *)p);
	return S_OK;
	}
