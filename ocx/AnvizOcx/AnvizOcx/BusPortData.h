// BusPortData.h : Declaration of the CBusPortData

#pragma once
#include "resource.h"       // main symbols
#include ".\Protocoltest\mutilqueue.h"
#define IDX_EN	0x1
#define ND_EN	0x2
class CDevQData:public CMutilQData
{
public:
	void *m_data;
	int m_nSize
	int m_node;
	int m_type;
	int m_index;
public:
	CDevQData(int index, int node, int type, void *data, int nSize)
	{
		m_index = index;
		m_node = node;
		m_type = type;
		m_data = data;
		m_nSize = nSize;
	}
	~CDevQData()
	{
	
	}
	virtual BOOL EqualOut( CMutilQData* t)
	{
		BOOL ret = TRUE;
		p = (CDevQData *)t;

		if( m_type & IDX_EN )
			if( m_index != p-> m_index )
				ret = FALSE;
		if( m_type & ND_EN )
			if( m_node != p->m_node )
				ret = FALSE;
		return ret;
	}
	virtual CMutilQData *Out()
	{
		return NULL;
	}
	virtual void Clone(CMutilQData *t)
	{
		p = (CDevQData *)t;
		p->m_data = m_data;
		p->m_nSize = m_nSize;
	}
}

class CDeviceData
{
private:
	CMutilQueue * m_q;
public:
	CDeviceData()
	{
		m_q = new CMutilQueue();
	}
    ~CDeviceData()
	{
		delete m_q;
	} 
public:
	BOOL GetData(int index, int type, void **pVal, int *nSize);
	BOOL SetData(int index, int type, void *pVal, int nSize);

};
