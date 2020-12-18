#include <stdio.h>
#include <windows.h>
#include <string.h>

int main() {
    HANDLE hPipe1;

    LPTSTR lpPipeName1 = TEXT("\\\\.\\pipe\\MyPipe1");

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
    
    while (strcmp(buff1, "q")) {
        iBytesToWrite = 255;
        iBytesToRead = 255;
        printf("          ");
        ReadFile(hPipe1, buff1, iBytesToRead, &iBytesToRead, NULL);
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
        WriteFile(hPipe1, buff2, strlen(buff2), &iBytesToWrite, NULL);
    }

    CloseHandle(hPipe1);
    
    return 0;
}
