// Door.h: interface for the CDoor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOOR_H__39EB6FCF_486C_473B_B74F_68D7C9ED6F6E__INCLUDED_)
#define AFX_DOOR_H__39EB6FCF_486C_473B_B74F_68D7C9ED6F6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Controller.h"




class CDoor : public CController  
{
public:
	BOOL GetStatus(BYTE node, BYTE *value);
	BOOL SetStatus(BYTE node, BYTE value);
	BOOL GetAtrrib(BYTE node, BYTE *value);
	BOOL SetAttrib(BYTE node, BYTE value);
	BOOL GetStatusInfo(BYTE nStatus, struct tag_doorstatus *value);
	BOOL SetStatusInfo(BYTE nStatus, struct tag_doorstatus *value);
	BOOL SetGroupInfo(BYTE nGroup, struct tag_group *value);
	BOOL GetGroupInfo(BYTE nGroup, struct tag_group *value);
	CDoor();
	virtual ~CDoor();

};

#endif // !defined(AFX_DOOR_H__39EB6FCF_486C_473B_B74F_68D7C9ED6F6E__INCLUDED_)
