#include "Dlg.h"
extern HANDLE p;
extern struct  tag_machine
{
	unsigned char node  : 3;
	unsigned char size	: 3;		/* 0 - 6 为长度，7为扩展*/
	unsigned char datapack	: 1;
	unsigned char dir		: 1;
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
					  case IDC_WEIGAND1:
						  OnWeigandButton(0);
						  break;
					  case IDC_BUTTON1:
						  OnExitButton(0);
						  break;
					  case IDC_MEGNET1:
						  OnMegnetButton(0);
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

void CDlg::OnWeigandButton(int id)
	{
		DWORD val;
		BOOL  bret;
		val = ::GetDlgItemInt(m_hWnd, IDC_USERID1 + id, &bret, FALSE);
		WaitForSingleObject(p,INFINITE);
//		if( machine[addr].node != 0xff )
		{
			machine[id].size = 4;
			machine[id].dir = 1;
			machine[id].datapack = 0;
			machine[id].node = 4;
			machine[id].data[0] = val&0xff;
			machine[id].data[1] = (val >> 8);
			machine[id].data[2] = (val >> 16);
			machine[id].data[3] = (val >> 24);	
		}
		SetEvent(p);
	}

void CDlg::OnExitButton(int id)
	{
		WaitForSingleObject(p,INFINITE);
		{
 			machine[id].size = 1;
			machine[id].dir = 1;
			machine[id].datapack = 0;
			machine[id].node = 1;
			machine[id].data[0] = 0;
		}
		SetEvent(p);
	}

void CDlg::OnMegnetButton(int id)
	{
		WaitForSingleObject(p,INFINITE);
		{
 			machine[id].size = 1;
			machine[id].dir = 1;
			machine[id].datapack = 0;
			machine[id].node = 0;
			machine[id].data[0] = 0;
		}
		SetEvent(p);
	}

void CDlg::OnOpenDoor(int id)
	{
		 CheckDlgButton(m_hWnd, IDC_DOOR1+id, BST_CHECKED);
	}


void CDlg::OnCloseDoor(int id)
	{
		CheckDlgButton(m_hWnd, IDC_DOOR1+id, BST_UNCHECKED);
	}
