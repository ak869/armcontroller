// User.cpp: implementation of the CUser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "User.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUser::CUser(DWORD nID,BYTE nGroup)
{

}

CUser::~CUser()
{

}

BOOL CUser::SetAttrib(BYTE node, BYTE value)
{
	return TRUE;
}

BOOL CUser::GetAttrib(BYTE node, BYTE *value)
{
	return TRUE;
}

BOOL CUser::GetGroup(BYTE *value, BYTE nSize)
{
	return TRUE;
}
