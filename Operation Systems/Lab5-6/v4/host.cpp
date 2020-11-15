#include <windows.h>
#include "host_resource.h"
#include <stdio.h>
LRESULT CALLBACK
DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow) {
	MSG msg;
	DialogBox(hInstance,(LPCTSTR)IDD_HOSTTEST,NULL,
	          (DLGPROC)DlgProc);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK
DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		case WM_INITDIALOG:
			return TRUE;
		case WM_COPYDATA:
			SetDlgItemText(hDlg,IDC_EDIT1,(char*)(
			                  ((COPYDATASTRUCT*)lParam)->lpData));
		
			        break;
		case WM_COMMAND:
			switch (LOWORD(wParam) ) {
				case IDOK:
					PostQuitMessage(0);
					return TRUE;
				case IDCANCEL:
					PostQuitMessage(0);
					return TRUE;
					
				case IDC_BTN1:
					char send_it[100];
					GetDlgItemText(hDlg,IDC_EDIT2,send_it, 100);
					HWND hWnd;
					COPYDATASTRUCT data;
					hWnd=FindWindow(NULL,"Dialog");
					data.cbData=strlen(send_it);
					data.lpData=send_it;
					SendMessage (hWnd, WM_COPYDATA, (WPARAM)GetFocus(),
					            (LPARAM)&data);
					break;
			}
			break;
		default:
			return FALSE;
	}
}
