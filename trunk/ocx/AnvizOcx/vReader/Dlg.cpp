#include "Dlg.h"
extern HANDLE p;
extern struct  tag_machine machine[14];
extern DWORD StartTime;
CDlg::CDlg(void)
{
	m_hWnd= NULL;
	EventExit = CreateEvent(NULL,TRUE, FALSE,NULL);
	m_Lock = 0;
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
		DWORD	t;
		  switch(uMsg)
		  {
			  case WM_INITDIALOG:
				  ShowWindow(m_hWnd,SW_SHOW);
				  Unlock();
				  break;
			  case WM_TIMER:
				  t = GetTickCount() - StartTime;				  
				  for( i = 0; i < 4; i++ )
				  {				    
					if( t )
					{
						WaitForSingleObject(p,INFINITE);	
						SetDlgItemInt(m_hWnd, IDC_TIMEDISP1 + i, machine[i].Count * 1000 / t, FALSE);
						SetEvent(p);
					}
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
					  case IDC_WEIGAND2:
					  case IDC_WEIGAND3:
					  case IDC_WEIGAND4:
						  OnWeigandButton(wID - IDC_WEIGAND1);
						  break;
					  case IDC_BUTTON1:
					  case IDC_BUTTON2:
					  case IDC_BUTTON3:
					  case IDC_BUTTON4:
						  OnExitButton(wID - IDC_BUTTON1);
						  break;
					  case IDC_MEGNET1:
					  case IDC_MEGNET2:
					  case IDC_MEGNET3:
					  case IDC_MEGNET4:
						  OnMegnetButton(wID - IDC_MEGNET1);
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
		int i;
		WaitForSingleObject(p,INFINITE);
		m_Lock++;
		if( m_Lock == 2 )
		{//Init
			for( i = 0; i < 4; i++)
			{
				SetDlgItemInt(m_hWnd, IDC_USERID1 + i,0x67452301,FALSE);
			}
			SetTimer(m_hWnd, IDC_TIMER1, 5000, NULL);
		}
		SetEvent(p);
	}

void CDlg::OnWeigandButton(int id)
	{
		DWORD val;
		BOOL  bret;
		val = ::GetDlgItemInt(m_hWnd, IDC_USERID1 + id, &bret, FALSE);
		WaitForSingleObject(p,INFINITE);
		if( machine[id].size == 0 )
		{
			machine[id].size = 4;
			machine[id].dir = 1;
			machine[id].datapack = 0;
			machine[id].node = 4;
			machine[id].data[0] = val & 0xff;
			machine[id].data[1] = (val >> 8) & 0xff;
			machine[id].data[2] = (val >> 16) & 0xff;
			machine[id].data[3] = (val >> 24);	
		}
		SetEvent(p);
	}

void CDlg::OnExitButton(int id)
	{
		WaitForSingleObject(p,INFINITE);
		if( machine[id].size == 0 )
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
		if( machine[id].size == 0 )
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
