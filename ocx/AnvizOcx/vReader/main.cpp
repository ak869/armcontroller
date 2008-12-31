#include <windows.h>
#include <tchar.h>
#include "dlg.h"
#include "..\AnvizOcx\ProtocolTest\ComPort.h"

HANDLE p;
struct  tag_machine
{
	unsigned char node  : 3;
	unsigned char size	: 3;		/* 0 - 6 为长度，7为扩展*/
	unsigned char datapack	: 1;
	unsigned char dir		: 1;
    unsigned char data[4];
}machine[14];

DWORD WINAPI ComThread( LPVOID lpParameter )
	{
		CDlg *d;
		CComPort port;
		int nSize, i;
		UCHAR buf[256],chk,addr;
		d = (CDlg *)lpParameter;
		if( !port.OpenCom( _TEXT("COM1") ) )
			{
				ExitThread(1);
				return 0;
			}
		 port.SetTimeOut(80);
//		 PostMessage( d->m_hWnd,(WM_USER+1), 0, NULL);
		 d->Unlock();
		 while( WaitForSingleObject(d->EventExit,0) != WAIT_TIMEOUT )
		 {
			nSize = 256;
			port.ReadData(buf, (DWORD*)&nSize);
			if( nSize >= 8 )
			{
				if( buf[0] == 0xf1 )
				{
					chk = 0;
					for( i = 1; i < 8; i++)
					{
						chk ^= buf[i];	
					}
					if( chk )
						continue;
					addr = buf[6];
					if( addr < 16 && addr >=2 )
					{
						WaitForSingleObject(p,INFINITE);
						if( machine[addr].node != 0xff )
						{
							buf[1] = machine[addr].node;
							buf[2] = machine[addr].data[0];
							buf[3] = machine[addr].data[1];
							buf[4] = machine[addr].data[2];
							buf[5] = machine[addr].data[3];							
							machine[addr].node = 0xff;
						}
						SetEvent(p);
						chk = 0;
						for( i = 1; i < 7; i++ )
						{
							chk ^= buf[i];	
						}
						buf[i] = chk;
						port.WriteData( buf, 8 );						
					}				
				}
			}
		 }
		 port.CloseCom();
		 ExitThread(0);
		 return 0;	
	}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
	{
	   CDlg d;
	   HANDLE hThread;
	   DWORD dwThreadID;
	   p = CreateEvent(NULL,FALSE,TRUE,NULL);
	   hThread = CreateThread(NULL, 0, ComThread, &d, 0, &dwThreadID);
	   d.Do(hInstance,MAKEINTRESOURCE(IDD_DIALOG));
	   WaitForSingleObject(d.EventExit,INFINITE);
	   Sleep(1000);
	}