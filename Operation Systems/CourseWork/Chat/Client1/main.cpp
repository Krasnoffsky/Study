#include <windows.h>
#include "client1_lib.h"
#include <stdio.h>
#include <string.h>

HANDLE hPipe;
LPSTR lpPipeName = TEXT("\\\\.\\pipe\\MyPipe0");

char input_buff[255];
char output_buff[255] = " ";
DWORD iBytesToWrite = 255;
DWORD iBytesToRead;

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
    		hPipe = CreateFile(lpPipeName, 
                	  GENERIC_READ | 
                      GENERIC_WRITE,
                      0, 
                      NULL, 
                      OPEN_EXISTING, 
                      0,
                      NULL);
    		if(hPipe == INVALID_HANDLE_VALUE){
    			printf("Client couldn't connected\n");
        		return GetLastError();}
        	else
        		printf("Client connected\n"); 
    		
			return TRUE;
			
		case WM_COMMAND:
			switch (LOWORD(wParam) ) {
				case IDCANCEL:
					PostQuitMessage(0);
					return TRUE;
					
				case IDC_BTN1:
					//send message by client1
					GetDlgItemText(hDlg,IDC_EDIT_INPUT,output_buff, 255);
					WriteFile(hPipe, output_buff, strlen(output_buff), NULL, NULL);
					
					//write message from client1
					ReadFile(hPipe, input_buff, sizeof(input_buff), NULL, NULL);
					SetDlgItemText(hDlg,IDC_EDIT_OUTPUT1,input_buff);
					
					//write message from client2
					ReadFile(hPipe, input_buff, sizeof(input_buff), NULL, NULL);
					SetDlgItemText(hDlg,IDC_EDIT_OUTPUT2,input_buff);
					
					
					//write message by client3
					ReadFile(hPipe, input_buff, sizeof(input_buff), NULL, NULL);
					SetDlgItemText(hDlg,IDC_EDIT_OUTPUT3,input_buff);
					
					break;
			}
			break;
		default:
			return FALSE;
	}
	
}
