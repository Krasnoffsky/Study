#include <windows.h>
#include "client2_lib.h"
#include <stdio.h>
#include <string.h>

HANDLE hPipe;
LPSTR lpPipeName = TEXT("\\\\.\\pipe\\MyPipe1");

char input_buff[255 + 10];
char output_buff[255] = " ";
char message1[255 + 10];
char message2[255 + 10];
char message3[255 + 10];
char message4[255 + 10];
char message5[255 + 10];
char message6[255 + 10];
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
				 
    		SetDlgItemText(hDlg,IDC_EDIT_OUTPUT1, " ");
    		SetDlgItemText(hDlg,IDC_EDIT_OUTPUT2, " ");
    		SetDlgItemText(hDlg,IDC_EDIT_OUTPUT3, " ");
    		SetDlgItemText(hDlg,IDC_EDIT_OUTPUT4, " ");
    		SetDlgItemText(hDlg,IDC_EDIT_OUTPUT5, " ");
    		SetDlgItemText(hDlg,IDC_EDIT_OUTPUT6, " ");
			return TRUE;
			
		case WM_COMMAND:
			switch (LOWORD(wParam) ) {
				case IDCANCEL:
					PostQuitMessage(0);
					return TRUE;
					
				case IDC_BTN1:	//Send
					//send message by client2
					for (int i = 0; i < 255; i++){
						output_buff[i] = ' ';
					}
					GetDlgItemText(hDlg,IDC_EDIT_INPUT,output_buff, 255);
					WriteFile(hPipe, output_buff, strlen(output_buff), NULL, NULL);
					SetDlgItemText(hDlg,IDC_EDIT_INPUT, " ");
					
					break;
					
				case IDC_BTN2:	//Update
					for (int i = 0; i < 265; i++){
						input_buff[i] = ' ';
						message1[i] = ' ';
						message2[i] = ' ';
						message3[i] = ' ';
						message4[i] = ' ';
						message5[i] = ' ';
						message6[i] = ' '; 
					}
					ReadFile(hPipe, input_buff, sizeof(input_buff), NULL, NULL);
					for (int i = 0; i < 255; i++)
						printf("%c",input_buff[i]);
					GetDlgItemText(hDlg,IDC_EDIT_OUTPUT6,message6, 265);
					if (strcmp(message6, " ") != 0){
						GetDlgItemText(hDlg,IDC_EDIT_OUTPUT5,message5, 265);
						SetDlgItemText(hDlg,IDC_EDIT_OUTPUT5,message6);
						if (strcmp(message5, " ") != 0){
							GetDlgItemText(hDlg,IDC_EDIT_OUTPUT4,message4, 265);
							SetDlgItemText(hDlg,IDC_EDIT_OUTPUT4,message5);
							if (strcmp(message4, " ") != 0){
								GetDlgItemText(hDlg,IDC_EDIT_OUTPUT3,message3, 265);
								SetDlgItemText(hDlg,IDC_EDIT_OUTPUT3,message4);
								if (strcmp(message3, " ") != 0){
									GetDlgItemText(hDlg,IDC_EDIT_OUTPUT2,message2, 265);
									SetDlgItemText(hDlg,IDC_EDIT_OUTPUT2,message3);
									SetDlgItemText(hDlg,IDC_EDIT_OUTPUT1,message2);
									
								} else
									SetDlgItemText(hDlg,IDC_EDIT_OUTPUT2,message3);
							} else
								SetDlgItemText(hDlg,IDC_EDIT_OUTPUT3,message4);
						} else
							SetDlgItemText(hDlg,IDC_EDIT_OUTPUT4,message5);
						
					} else 
						SetDlgItemText(hDlg,IDC_EDIT_OUTPUT5,message6);	
					SetDlgItemText(hDlg,IDC_EDIT_OUTPUT6,input_buff);
					
					break;
			}
			break;
		default:
			return FALSE;
	}
	
}
