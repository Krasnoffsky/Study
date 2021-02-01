#include <windows.h>
#include "resource.h"
#include <stdio.h>
LRESULT CALLBACK
DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow) {
	MSG msg;
	DialogBox(hInstance,(LPCTSTR)IDD_DLGTEST,NULL,
	          (DLGPROC)DlgProc);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK
DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	char strText[100], strText2[100], result[100];
	int res;
	switch (message) {
		case WM_INITDIALOG:
			return TRUE;
		case WM_COPYDATA:
			SetDlgItemText(hDlg,IDC_EDIT4,(char*)(
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
					GetDlgItemText(hDlg,IDC_EDIT1,strText, 100);
					GetDlgItemText(hDlg,IDC_EDIT2,strText2, 100);
					res = atoi(strText) + atoi(strText2);
					sprintf(result, "%d", res);
					SetDlgItemText(hDlg,IDC_EDIT3,result);
					HWND hWnd;
					COPYDATASTRUCT data;
					hWnd=FindWindow(NULL,"Host");
					data.cbData=strlen(result);
					data.lpData=result;
					SendMessage (hWnd, WM_COPYDATA, (WPARAM)GetFocus(),
					            (LPARAM)&data);
					break;
			}
			break;
		default:
			return FALSE;
	}
}
