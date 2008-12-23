// User.h: interface for the CUser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USER_H__77E14D8C_DBFA_4B48_90DC_A499F4F88614__INCLUDED_)
#define AFX_USER_H__77E14D8C_DBFA_4B48_90DC_A499F4F88614__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Controller.h"

class CUser : public CController  
{
public:
	BOOL GetGroup(BYTE *value,BYTE nSize);
	BOOL GetAttrib(BYTE node, BYTE *value);
	BOOL SetAttrib(BYTE node, BYTE value);
	CUser(DWORD nID,BYTE nGroup);
	virtual ~CUser();

};

#endif // !defined(AFX_USER_H__77E14D8C_DBFA_4B48_90DC_A499F4F88614__INCLUDED_)
