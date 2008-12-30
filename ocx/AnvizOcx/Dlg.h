#pragma once
#include <windows.h>
#include "resource.h"
class CDlg
	{
	private:
		bool m_Lock;
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
	};
