// Reader.cpp: implementation of the CReader class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Reader.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CReader::CReader()
{

}

CReader::~CReader()
{

}

BOOL CReader::SetAttrib(BYTE node, BYTE value)
{
	return TRUE;
}

BOOL CReader::GetAttrib(BYTE node, BYTE *value)
{
	return TRUE;
}

BOOL CReader::GetStatus(BYTE node, BYTE *value)
{
	return TRUE;
}

BOOL CReader::SetStatus(BYTE node, BYTE value)
{
	return TRUE;
}

BOOL CReader::LinkDoor(BYTE nDoor)
{
	return TRUE;
}

BOOL CReader::UnLinkDoor(BYTE nDoor)
{
	return TRUE;
}
