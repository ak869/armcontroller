#pragma once
#include <windows.h>
#include "resource.h"

#define MEGNET_NODE			0
#define EXIT_NODE			1
#define OTHER_NODE			2
#define ALARM_NODE			3
#define READERDATA_NODE		4
#define DOOR_NODE			5
#define	CTRL_NODE			6
struct  tag_machine
{
	unsigned char node  : 3;
	unsigned char size	: 3;		/* 0:为空消息， 1- 6:为长度， 7:为扩展 */
	unsigned char datapack	: 1;
	unsigned char dir		: 1;
    unsigned char data[4];
	unsigned int  Count;
	unsigned int  SendTime;
};
class CDlg
	{
	private:
		unsigned int m_Lock;
	public:
		HWND m_hWnd;
		HANDLE EventExit;

		static BOOL CALLBACK DlgProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
		BOOL Create(HINSTANCE hInstance,LPCTSTR lpTemplateName);
		DWORD DialogParam(UINT uMsg, WPARAM wParam, LPARAM lParam);
		BOOL Do(HINSTANCE hInstance, LPCTSTR lpTemplateName);
		CDlg(void);
		~CDlg(void);
		void Unlock(void);
		void OnWeigandButton(int id);
		void OnExitButton(int id);
		void OnMegnetButton(int id);
		void OnOpenDoor(int id);
		void OnCloseDoor(int id);
	};
