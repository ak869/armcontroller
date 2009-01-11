// BusPortData.cpp : Implementation of CBusPortData

#include "stdafx.h"
#include "BusPortData.h"


// CBusPortData
CDeviceData::GetData(int index, int type, void **pVal,int *nSize)
{
	CDevQData *p = new CDevQData(index, 0, type, NULL, 0);
	m_q->Out((CMutilQData *)p);

	*pVal = p->m_data;
	*nSize = p->m_nSize;
}

CDeviceData::SetData(int index,int type,void *pVal,int nSize)
{
	CDevQData *p = new CDevQData(index, 0, type, pVal, nSize);
	m_q->In((CMutilQData *)p);
}

// CBusPortData
