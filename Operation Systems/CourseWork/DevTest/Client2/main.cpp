#include <windows.h>
#include "client2_lib.h"
#include <stdio.h>
#include <string.h>

HANDLE hPipeOutput;
HANDLE hPipeInput;

LPSTR lpPipeNameOutput = TEXT("\\\\.\\pipe\\MyPipeOut1");
LPSTR lpPipeNameInput = TEXT("\\\\.\\pipe\\MyPipeOut1");

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
    		hPipeOutput = CreateFile(lpPipeNameOutput, 
                	  GENERIC_READ | 
                      GENERIC_WRITE,
                      0, 
                      NULL, 
                      OPEN_EXISTING, 
                      0,
                      NULL);
    		if(hPipeOutput == INVALID_HANDLE_VALUE){
    			printf("Client couldn't connected for output\n");
        		return GetLastError();}
        	else
        		printf("Client connected for output\n");
        		
        	Sleep(100);
        		
        	hPipeInput = CreateFile(lpPipeNameInput, 
                	  GENERIC_READ | 
                      GENERIC_WRITE,
                      0, 
                      NULL, 
                      OPEN_EXISTING, 
                      0,
                      NULL);
    		if(hPipeInput == INVALID_HANDLE_VALUE){
    			printf("Client couldn't connected for Input\n");
        		return GetLastError();}
        	else
        		printf("Client connected for Input\n");
				 
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
					memset(output_buff, 0, 255);
					GetDlgItemText(hDlg,IDC_EDIT_INPUT,output_buff, 255);
					WriteFile(hPipeOutput, output_buff, strlen(output_buff), NULL, NULL);
					SetDlgItemText(hDlg,IDC_EDIT_INPUT, " ");
					
					break;
					
				case IDC_BTN2:	//Update
					memset(input_buff, 0, 265);
					memset(message1, 0, 265);
					memset(message2, 0, 265); 
					memset(message3, 0, 265); 
					memset(message4, 0, 265); 
					memset(message5, 0, 265); 
					memset(message6, 0, 265);  
					
					ReadFile(hPipeInput, input_buff, sizeof(input_buff), NULL, NULL);
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
