// BusPortData.h : Declaration of the CBusPortData

#pragma once
#include "resource.h"       // main symbols
#include ".\Protocoltest\PortThread.h"
#include "AnvizOcx_i.h"


#define EVENT_TYPE	1
#define MESSAGE_TYPE	2

// CBusPortData

class CDeviceData
{
private:

public:
	CDeviceData()
	{
	
	}
    ~CDeviceData()
	{
		
	}
	void Init( IDevice * pParent, CProtocol *p, DWORD nTimeout, LPVOID lParam)
	{
	}
 
public:

};

OBJECT_ENTRY_AUTO(__uuidof(BusPortData), CBusPortData)
