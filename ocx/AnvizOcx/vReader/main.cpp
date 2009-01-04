#include <windows.h>
#include <tchar.h>
#include "dlg.h"
#include "..\AnvizOcx\ProtocolTest\ComPort.h"

HANDLE p;
struct  tag_machine machine[14];
DWORD StartTime;

DWORD WINAPI ComThread( LPVOID lpParameter )
	{
		CDlg *d;
		CComPort port;
		int nSize, i;
		UCHAR buf[256],chk,addr, *b;
		struct  tag_machine *t;
		d = (CDlg *)lpParameter;
		if( !port.OpenCom( _TEXT("COM1") ) )
			{
				ExitThread(1);
				return 0;
			}
		 port.SetTimeOut(80);
		 d->Unlock();
		 StartTime = GetTickCount();
		 while( WaitForSingleObject(d->EventExit,0) == WAIT_TIMEOUT )
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
						addr -= 2;
						t = (struct  tag_machine *)(buf + 1);
						if( t->size != 0 )
						{
							switch( t->node )
							{
							case DOOR_NODE:
								if( t->data[0] == 1 )
								{
									d->OnOpenDoor(addr);
								}else
									d->OnCloseDoor(addr);
								break;
							}											
						}
						buf[1] = 0;
						buf[2] = 0;
						buf[3] = 0;
						buf[4] = 0;
						buf[5] = 0;
						WaitForSingleObject(p,INFINITE);
						machine[addr].Count++;
						if( machine[addr].size != 0 )
						{
							b = (BYTE *)(machine + addr);
							machine[addr].datapack = 0;							
							buf[1] = b[0];
							buf[2] = b[1];
							buf[3] = b[2];
							buf[4] = b[3];
							buf[5] = b[4];
							machine[addr].SendTime = GetTickCount();
							machine[addr].size = 0;
						}
						SetEvent(p);
						buf[1] |= 0x80;

						chk = 0;
						for( i = 1; i < 7; i++ )
						{
							chk ^= buf[i];	
						}
						buf[i] = chk;
						port.WriteData( buf, 8 );
						chk = 0;
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
	   int i;
	   HANDLE hThread;
	   DWORD dwThreadID;
		for( i = 0; i < 14; i++ )
		{
			machine[i].size = 0;
			machine[i].Count = 0;
		}

	   p = CreateEvent(NULL,FALSE,TRUE,NULL);
	   hThread = CreateThread(NULL, 0, ComThread, &d, 0, &dwThreadID);
	   d.Do(hInstance,MAKEINTRESOURCE(IDD_DIALOG));
	   WaitForSingleObject(d.EventExit,INFINITE);
	   Sleep(1000);
	}