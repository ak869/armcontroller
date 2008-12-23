// ProtocolTest.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "PortThread.h"
#include "Controller.h"

/*
F1 45 FF AA 00 00 01 11 
F1 46 FF 00 00 00 01 B8
 */


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	BYTE *t;
	char disp[128];
	CBusPortThread pt;
	CController ct;
	BYTE group[6];
	BYTE buf[528];
	int i;
	struct tag_doorstatus ds;
	pt.OpenPort();

	pt.CreateThread();
	Sleep(1000);
	
	ct.SetMachineAddr(1);
	ct.LinkBusPort(&pt);
//	
	if( ct.Test() )
	{
/*		ds.crc = 0;
		ds.param = 0;
		ds.t.hour_start = 0;
		ds.t.hour_end = 23;
		ds.t.minute_start = 0;
		ds.t.minute_end = 59;
		ds.t.weeks = 7;
		ds.t.other = 0;
		t = (BYTE *)&ds;
		chk = 0;
		for( int i = 0; i < DOOR_STATE_SIZE; i++)
			chk ^= t[i];
		ds.crc = chk;
		//F142080008000143F100B8FB010000CC8E00
		ct.SetLongData( DOOR_STATE_PAGE, 0, (BYTE *)&ds,DOOR_STATE_SIZE);
		//F101080008000100
		ct.GetLongData( DOOR_STATE_PAGE, 0, (BYTE *)&ds,DOOR_STATE_SIZE);
*/
/*
		for( i = 0; i < 6;i++)
			group[i] = 0;
		if( ct.User_Add(0x00000001, group, 6, 0) )
			OutputDebugString("User_Add:Success\n");
		else
		{
			wsprintf(disp,"User_Add:Fail 0x%04lx",ct.GetErrCode());
			OutputDebugString("User_Add:Fail\n");
		}
*/
		if( ct.GetLongData( USER_ID_PAGE + 30, 0, (BYTE *)buf,200))
			OutputDebugString("GetLongData:Success\n");
		else
		{
			wsprintf(disp,"GetLongData:Fail 0x%04lx",ct.GetErrCode());
			OutputDebugString(disp);
		}
	}
	pt.ExitThread();
	
	pt.ClosePort();
	return 0;
}



