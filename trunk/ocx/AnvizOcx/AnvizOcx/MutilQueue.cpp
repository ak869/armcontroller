#include "StdAfx.h"
#include "MutilQueue.h"

CMutilQueue::CMutilQueue(void)
{
	m_header = NULL;
	m_NData = 0;
	m_end = NULL;
}

CMutilQueue::~CMutilQueue(void)
{
	Clear();
}
void CMutilQueue::In(CMutilQData *Val)
{
	if( m_NData == 0 )
	{
		m_header = Val;
		m_end = Val;
		Val->m_next = NULL;
		Val->m_prev = NULL;
	}else
	{
		m_end->m_next = Val;
		Val->m_prev = m_end;
		Val->m_next = NULL;
		m_end = Val;
	}
	m_NData++;
}
void CMutilQueue::Out(CMutilQData *pVal)
{
	if( m_NData != 0 )
	{
		CMutilQData *t;
		t = m_header;
		while( t )
		{
			if( pVal->EqualOut(t) )
			{//
				pVal->Clone(t);

				if( t->m_prev )
					t->m_prev->m_next = t->m_next;
				else
					m_header = t->m_next;
				delete t;
				m_NData--;
				break;
			}
			t = t->m_next;
		}
		if( (t = pVal->Out()) != NULL )
		{
			pVal->Clone(t);
			if( t->m_prev )
				t->m_prev->m_next = t->m_next;
			else
				m_header = t->m_next;
			delete t;
			m_NData--;
		}
	
	}
}
void CMutilQueue::Clear()
{
	if( m_NData )
	{
		CMutilQData *t;
		t = m_header;
		while( t )
		{			
			m_header = t->next;	
			delete t;
			m_NData--;
		}
		m_header = NULL;
	}
}

