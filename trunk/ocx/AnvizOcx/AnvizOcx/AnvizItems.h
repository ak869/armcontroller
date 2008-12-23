// AnvizItems.h : Declaration of the CAnvizItems

#pragma once
#include "resource.h"       // main symbols

#include "AnvizOcx_i.h"

#pragma warning(push)
#pragma warning(disable:4702)
#include <map>
#pragma warning(pop)

#include "Reuse\VCUE_Collection.h"
#include "Reuse\VCUE_Copy.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

namespace MapColl
{
	// We always need to provide the following information
	typedef std::map< CAdapt< CComBSTR >, CComVariant >				ContainerType;
	typedef VARIANT													ExposedType;
	typedef IEnumVARIANT											EnumeratorInterface;
	typedef IAnvizItems											CollectionInterface;

	// Typically the copy policy can be calculated from the typedefs defined above:
	// typedef VCUE::GenericCopy<ExposedType, ContainerType::value_type>		CopyType;

	// However, we may want to use a different class, as in this case:
	typedef VCUE::MapCopy<ContainerType, ExposedType>				CopyType;
	// (The advantage of MapCopy is that we don't need to provide implementations 
	//  of GenericCopy for all the different pairs of key and value types)

	// Now we have all the information we need to fill in the template arguments on the implementation classes
	typedef CComEnumOnSTL< EnumeratorInterface, &__uuidof(EnumeratorInterface), ExposedType,
							CopyType, ContainerType > EnumeratorType;

	typedef VCUE::ICollectionOnSTLCopyImpl< CollectionInterface, ContainerType, ExposedType,
							CopyType, EnumeratorType > CollectionType;
};

using namespace MapColl;

// CAnvizItems

class ATL_NO_VTABLE CAnvizItems :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAnvizItems, &CLSID_AnvizItems>,
	public IDispatchImpl<MapColl::CollectionType, &IID_IAnvizItems, &LIBID_AnvizOcxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	IBus *m_parent;
public:
	CAnvizItems()
	{
		 m_parent = NULL;
	}
	virtual ~CAnvizItems()
	{
		if( m_parent )
			m_parent->Release();
	}
	void Init(IBus *pParent)
	{
		m_parent = pParent;	
	}
DECLARE_REGISTRY_RESOURCEID(IDR_ANVIZITEMS)


BEGIN_COM_MAP(CAnvizItems)
	COM_INTERFACE_ENTRY(IAnvizItems)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(get_Item)(VARIANT Index, VARIANT* pVal)
	{
		if (pVal == NULL)
			return E_POINTER;

		HRESULT hr = S_OK;
		CComVariant var;

		if (Index.vt != VT_BSTR)
		{
			// If the index isn't a string, but can be converted to a long value, we use ATL's implementation
			hr = var.ChangeType(VT_I4, &Index);
			if (SUCCEEDED(hr))
				return CollectionType::get_Item(var.lVal, pVal);
		}

		// Otherwise, we assume index is a key into the map
		hr = var.ChangeType(VT_BSTR, &Index);

		// If we can't convert to a string, just return
		if (FAILED(hr))
			return hr;

		ContainerType::iterator it = m_coll.find(CComBSTR(var.bstrVal));

		// If item not found, just return
		if (it == m_coll.end())
			return E_FAIL;
			
		// If item was found, copy the variant to the out param
		return (CComVariant(it->second).Detach(pVal));
	}
	STDMETHOD(Add)(VARIANT Key, VARIANT Value)
	{
		// Get a BSTR from the VARIANT
		CComBSTR str;
		HRESULT hr = VCUE::GenericCopy<BSTR, VARIANT>::copy(&str, &Key);

		// If we can't convert to a string, just return
		if (FAILED(hr))
			return hr;

		// Check whether item already exists
		if (m_coll.find(str) != m_coll.end())
			return E_FAIL;	// item with this key already exists

		// Add the item to the map
		IDevice *lpDev;
		switch( Value.vt )
		{
			case VT_DISPATCH:
				{
					if( Value.pdispVal == NULL )
						return E_FAIL;
					LPDISPATCH lpdis = Value.pdispVal;

					lpdis->QueryInterface(__uuidof(IDevice), (void**)&lpDev);
					if( lpDev == NULL )
						return E_FAIL;
					lpDev->LinkBus(m_parent);
//					lpDev->Release();
				}
				break;
			case VT_UNKNOWN:
				{
 					if( Value.punkVal == NULL )
						return E_FAIL;
					IUnknown *lpunk = Value.punkVal;
					lpunk->QueryInterface(__uuidof(IDevice), (void**)&lpDev);
					if( lpDev == NULL )
						return E_FAIL;
					lpDev->LinkBus(m_parent);
//					lpDev->Release();
				}
				break;
			case (VT_BYREF|VT_UNKNOWN):
				{
 					if( Value.ppunkVal == NULL )
						return E_FAIL;
					IUnknown *lpunk = *(Value.ppunkVal);
					if(lpunk == NULL )
						return E_FAIL;
					lpunk->QueryInterface(__uuidof(IDevice), (void**)&lpDev);
					if( lpDev == NULL )
						return E_FAIL;
					lpDev->LinkBus(m_parent);
					lpunk->Release();
				}
				break;
			case (VT_BYREF|VT_DISPATCH):
				{
					if( Value.ppdispVal == NULL )
						return E_FAIL;
					LPDISPATCH lpdis = *(Value.ppdispVal);
					if(lpdis == NULL )
						return E_FAIL;

					lpdis->QueryInterface(__uuidof(IDevice), (void**)&lpDev);
					if( lpDev == NULL )
						return E_FAIL;
					//m_parent
					lpDev->LinkBus(m_parent);
					lpdis->Release();
				}
				break;
			default:
				return E_FAIL;
		}
		m_coll[str].vt =  VT_DISPATCH;
		m_coll[str].pdispVal = lpDev;
		return S_OK;
	}
	STDMETHOD(Remove)(VARIANT Index)
	{
		HRESULT hr = S_OK;
		CComVariant var;

		if (Index.vt != VT_BSTR)
		{
			// If the index isn't a string, but can be converted to a long value, we use the long implementation of Remove
			hr = var.ChangeType(VT_I4, &Index);
			if (SUCCEEDED(hr))
				return Remove(var.lVal);
		}

		// Otherwise, we assume index is a key into the map
		hr = var.ChangeType(VT_BSTR, &Index);

		// If we can't convert to a string, just return
		if (FAILED(hr))
			return hr;
		CComBSTR  str(var.bstrVal);
//		HRESULT hr = VCUE::GenericCopy<BSTR, VARIANT>::copy(&str, &Key);
		ContainerType::iterator it = m_coll.find(str);

		// If item not found, just return
		if (it == m_coll.end())
			return E_FAIL;
		
		IDevice *lpDev;
		lpDev = ( IDevice * )m_coll[str].pdispVal;
		lpDev->UnlinkBus();
		lpDev->Release();
		// If item was found, remove it from the map
		m_coll.erase(it);
		
		// (Could just use erase on the key, but it's not clear what erase does if the item isn't present.
		//  Our method is safer and allows us to inform the client of failure.)
		return S_OK;
	}
	STDMETHOD(Remove)(size_t Index)
	{
		// NOTE: This code can be used with most STL containers

		// Check that the 1-based index is in bounds
		if (Index <= 0 || Index > m_coll.size())
			return E_INVALIDARG;
		VARIANT Val;
		CollectionType::get_Item(Index, &Val);
		IDevice *lpDev;
		lpDev = ( IDevice * )Val.pdispVal;
		lpDev->UnlinkBus();
		lpDev->Release();
		// Get the iterator and erase the item
		ContainerType::iterator it = m_coll.begin();
		std::advance(it, Index - 1);
		m_coll.erase(it);
		return S_OK;
	}
	STDMETHOD(Clear)()
	{
		// NOTE: This code can be used with most STL containers
		m_coll.clear();
		return S_OK;
	}
};

OBJECT_ENTRY_AUTO(__uuidof(AnvizItems), CAnvizItems)
