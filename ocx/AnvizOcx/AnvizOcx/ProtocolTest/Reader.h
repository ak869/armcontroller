// Reader.h: interface for the CReader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_READER_H__859025B4_1F31_418C_A31C_16C020F75793__INCLUDED_)
#define AFX_READER_H__859025B4_1F31_418C_A31C_16C020F75793__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Controller.h"

class CReader : public CController  
{
public:
	BOOL UnLinkDoor(BYTE nDoor);
	BOOL LinkDoor(BYTE nDoor);
	BOOL SetStatus(BYTE node, BYTE value);
	BOOL GetStatus(BYTE node, BYTE *value);
	BOOL GetAttrib(BYTE node, BYTE *value);
	BOOL SetAttrib(BYTE node, BYTE value);
	CReader();
	virtual ~CReader();

};

#endif // !defined(AFX_READER_H__859025B4_1F31_418C_A31C_16C020F75793__INCLUDED_)
