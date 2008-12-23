#pragma once

template<class T>
class CProxy_IAnvizEvents :
	public IConnectionPointImpl<T, &__uuidof(_IAnvizEvents)>
{
public:
	HRESULT Fire_BusMessage( BSTR BusIndex,  BSTR MachineIndex,  ULONG uMessageID)
	{
		HRESULT hr = S_OK;
		T * pThis = static_cast<T *>(this);
		int cConnections = m_vec.GetSize();

		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			pThis->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			pThis->Unlock();

			IDispatch * pConnection = static_cast<IDispatch *>(punkConnection.p);

			if (pConnection)
			{
				CComVariant avarParams[3];
				avarParams[2] = BusIndex;
				avarParams[2].vt = VT_BSTR;
				avarParams[1] = MachineIndex;
				avarParams[1].vt = VT_BSTR;
				avarParams[0] = uMessageID;
				avarParams[0].vt = VT_UI4;
				DISPPARAMS params = { avarParams, NULL, 3, 0 };
				hr = pConnection->Invoke(1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, NULL, NULL, NULL);
			}
		}
		return hr;
	}
};

