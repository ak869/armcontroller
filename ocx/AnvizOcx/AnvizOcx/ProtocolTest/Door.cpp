// Door.cpp: implementation of the CDoor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Door.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDoor::CDoor()
{

}

CDoor::~CDoor()
{

}

BOOL CDoor::SetGroupInfo(BYTE nGroup, struct tag_group *value)
{
	return TRUE;
}

BOOL CDoor::GetGroupInfo(BYTE nGroup, struct tag_group *value)
{
	return TRUE;
}

BOOL CDoor::SetStatusInfo(BYTE nStatus, struct tag_doorstatus *value)
{
	return TRUE;
}

BOOL CDoor::GetStatusInfo(BYTE nStatus, struct tag_doorstatus *value)
{
	return TRUE;
}

BOOL CDoor::SetAttrib(BYTE node, BYTE value)
{
	return TRUE;
}

BOOL CDoor::GetAtrrib(BYTE node, BYTE *value)
{
	return TRUE;
}

BOOL CDoor::SetStatus(BYTE node, BYTE value)
{
	return TRUE;
}

BOOL CDoor::GetStatus(BYTE node, BYTE *value)
{
	return TRUE;
}
