#include <windows.h>
#include <stdio.h>
#include "psapi.h"

void PrintModules( DWORD processID )
{
    HMODULE hMods[1024];
    HANDLE hProcess;
    DWORD cbNeeded;
    unsigned int i;


    printf( "\nProcess ID: %u\n", processID );


    hProcess = OpenProcess(  PROCESS_QUERY_INFORMATION |
                                    PROCESS_VM_READ,
                                    FALSE, processID );
    if (NULL == hProcess)
        return;

    if( EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
    {
        for ( i = 0; i < (cbNeeded / sizeof(HMODULE)); i++ )
        {
            char szModName[MAX_PATH];
            GetModuleBaseName(hProcess, hMods[i],
            (LPSTR)szModName, sizeof(szModName));
            printf("%u\t%s", hMods[i],szModName);


            if ( GetModuleFileNameEx( hProcess, hMods[i], szModName,
                                      sizeof(szModName)))
            {


                printf("\t%s (0x%08X)\n", szModName, hMods[i] );
            }
        }
    }

    CloseHandle( hProcess );
}

void main( )
{

    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;

    if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) )
        return;



    cProcesses = cbNeeded / sizeof(DWORD);


        PrintModules( aProcesses[cProcesses-2] );
}
