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

STDMETHODIMP CComBus::get_DeviceItems(IAnvizItems** pVal)
	{
	// TODO: Add your implementation code here
		#pragma warning(suppress: 6014)
		if( m_dvs == NULL )
		{
			m_dvs = new CComObject<CAnvizItems>;
			IBus *pbus;
			this->QueryInterface(IID_IBus,(void**)&pbus);
			ATLASSERT(pbus);
			m_dvs->Init(pbus);
		}
		IAnvizItems* pDisp;
		m_dvs->QueryInterface(IID_IAnvizItems, (void**)&pDisp);
		ATLASSERT(pDisp);
		*pVal =  pDisp;
		return S_OK;
	}


STDMETHODIMP CComBus::SendData(IBusPortData * newVal)
	{
	if( newVal == NULL )
		return E_POINTER;
	CQData *p = new CQData(newVal);
	WriteData(p);
	return S_OK;
	}

STDMETHODIMP CComBus::get_Port(BSTR* pVal)
{
	// TODO: Add your implementation code here
	if( pVal == NULL )
		return E_POINTER;
	*pVal = m_port->Copy();
	return S_OK;
}

STDMETHODIMP CComBus::put_Port(BSTR newVal)
{
	// TODO: Add your implementation code here
	m_port->Empty();
	m_port->AppendBSTR(newVal);
	return S_OK;
}

STDMETHODIMP CComBus::get_BaudRate(LONG* pVal)
{
	// TODO: Add your implementation code here
	if( pVal == NULL )
		return E_POINTER;
	*pVal = m_baudrate;
	return S_OK;
}

STDMETHODIMP CComBus::put_BaudRate(LONG newVal)
{
	// TODO: Add your implementation code here
	m_baudrate = newVal;
	return S_OK;
}

STDMETHODIMP CComBus::Start(void)
{
	// TODO: Add your implementation code here
	m_ErrCode = 0;
	if( !OpenPort( (LPTSTR)(m_port->m_str), m_baudrate ) )
	{
		m_ErrCode = GetErrCode();
		return E_FAIL;
	}
	if( !CreateThread() )
	{
		m_ErrCode = GetErrCode();
		return E_FAIL;
	}
	::Sleep(1000);
	return S_OK;
}

STDMETHODIMP CComBus::Stop(void)
{
	// TODO: Add your implementation code here
	ExitThread();
	ClosePort();
	return S_OK;
}
