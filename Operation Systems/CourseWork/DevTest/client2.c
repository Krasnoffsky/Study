#include <stdio.h>
#include <windows.h>
#include <string.h>

int main() {
    HANDLE hPipe1;
    HANDLE hPipe2;
    HANDLE hPipe3;
    LPTSTR lpPipeName1 = TEXT("\\\\.\\pipe\\ServerPipe");
    LPTSTR lpPipeName2 = TEXT("\\\\.\\pipe\\ClientPipe1");
    LPTSTR lpPipeName3 = TEXT("\\\\.\\pipe\\ClientPipe2");

    char buff1[255] = " ";
    char buff2[255] = " ";
    DWORD iBytesToRead = 255;
    DWORD iBytesToWrite;

    hPipe1 = CreateFile(lpPipeName1, 
                       GENERIC_READ | 
                       GENERIC_WRITE,
                       0, 
                       NULL, 
                       OPEN_EXISTING, 
                       0,
                       NULL);
					   
	hPipe2 = CreateFile(lpPipeName2, 
                       GENERIC_READ | 
                       GENERIC_WRITE,
                       0, 
                       NULL, 
                       OPEN_EXISTING, 
                       0,
                       NULL); 

    hPipe3 = CreateNamedPipe(lpPipeName3,
                            PIPE_ACCESS_DUPLEX, 
                            PIPE_TYPE_MESSAGE |
                            PIPE_READMODE_MESSAGE |
                            PIPE_WAIT,
                            PIPE_UNLIMITED_INSTANCES,
                            4096, 
                            4096, 
                            NMPWAIT_USE_DEFAULT_WAIT,
                            NULL); 
    
    if (hPipe3 == INVALID_HANDLE_VALUE) {
        printf("CreatePipe failed: error code %d\n", (int)GetLastError());    
        return 0;
    }

    if((ConnectNamedPipe(hPipe3, NULL)) == 0) {
        printf("client 2 could not connect\n");
        return 0;
    } else printf("client connected\n");
    
    while (strcmp(buff1, "q")) {
        iBytesToWrite = 255;
        iBytesToRead = 255;
        printf("          ");
        ReadFile(hPipe1, buff1, iBytesToRead, &iBytesToRead, NULL);
        for(int i = 0; i < iBytesToRead; i++) printf("%c",buff1[i]);
        printf("          ");
        ReadFile(hPipe2, buff1, iBytesToRead, &iBytesToRead, NULL);
        for(int i = 0; i < iBytesToRead; i++) printf("%c",buff1[i]);

        char c = getchar();
        int i = 0;
        while (c != '\n') {
            buff2[i] = c;
            i++;
            c = getchar();
        }
        
        buff2[i] = '\n';
        buff2[i + 1] = '\0';
        WriteFile(hPipe3, buff2, strlen(buff2), &iBytesToWrite, NULL);
    }

    CloseHandle(hPipe1);
    CloseHandle(hPipe2);
    CloseHandle(hPipe3);
    
    return 0;
}
