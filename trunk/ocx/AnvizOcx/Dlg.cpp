#include "Dlg.h"
extern HANDLE p;
extern struct  tag_machine
{
	unsigned char node;
    unsigned char data[4];
}machine[14];
CDlg::CDlg(void)
{
	m_hWnd= NULL;
	EventExit = CreateEvent(NULL,TRUE, FALSE,NULL);
	m_Lock = 1;
}

CDlg::~CDlg(void)
{
	CloseHandle(EventExit);
}
BOOL CDlg::DlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	CDlg *pDlg;
	if( WM_INITDIALOG == uMsg )
	{		
		SetWindowLong(hwndDlg, DWL_USER, (LONG)lParam);
		pDlg = (CDlg *)lParam;
		pDlg->m_hWnd = hwndDlg;
		return pDlg->DialogParam(uMsg, wParam, lParam);

	}
	else
 
	{
		pDlg = ( CDlg * )GetWindowLong(hwndDlg,DWL_USER);
		if( NULL != pDlg )
		{
			return pDlg->DialogParam(uMsg, wParam, lParam);
		}
		else
			return 0;

	}

}

BOOL CDlg::Create(HINSTANCE hInstance,
    LPCTSTR lpTemplateName)
	{
		if( m_hWnd )
			return FALSE;
		m_hWnd = CreateDialogParam( hInstance, lpTemplateName, 
						NULL,  CDlg::DlgProc, (LPARAM )this);
		
		if( m_hWnd != NULL )
		{
//			SetWindowLong(m_hWnd, DWL_USER, (LONG)this);
			
			return TRUE;
		}
		return FALSE;
	}
BOOL CDlg::Do(HINSTANCE hInstance,
    LPCTSTR lpTemplateName)
	{
		if( m_hWnd )
			return FALSE;
		DialogBoxParam( hInstance, lpTemplateName, 
						NULL,  CDlg::DlgProc, (LPARAM )this);
		
		return TRUE;
	}
DWORD CDlg::DialogParam(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		int i;
		DWORD	wNotifyCode,wID;
		HWND	hwndCtl;		 
		  switch(uMsg)
		  {
			  case WM_INITDIALOG:
				  ShowWindow(m_hWnd,SW_SHOW);
				  if( m_Lock == 0)
				  {
					  
				  }
				  else
				  {
					  
				  }
				  break;
			  case (WM_USER + 1):
				  break;
			  case WM_COMMAND:
 					wNotifyCode = HIWORD(wParam); 
					wID = LOWORD(wParam); 
					hwndCtl = (HWND) lParam;
				  switch(wID)
				  {
					  case IDOK:
						  SetEvent(EventExit);
						  EndDialog(m_hWnd, 0);
						  break;
				  }
				  break;
			  case WM_CLOSE:
				  SetEvent(EventExit);
				  EndDialog(m_hWnd, 0);
				  break;
//			  default:
//				  return DefDlgProc(m_hWnd,uMsg,wParam,lParam);
				  			  
		  }
	  return 0;
	}
void CDlg::Unlock(void)
	{
		
		m_Lock = 0;
	}
