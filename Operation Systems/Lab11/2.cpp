#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	char lpszAppName[] = "C:\\Study\\Operation Systems\\Lab11\\1.exe";
	HANDLE hMutex;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	hMutex = CreateMutex(NULL, FALSE, "Mutex"); 
	
	if (hMutex == NULL)
	{
		cout << "Open mutex failed" << endl; 
		cout << "Press any key to exit" << endl;
		cin.get();
		return GetLastError();
    } 
    
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
 	if (!CreateProcess(lpszAppName, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi))
	{
		cout << "The new process is not created" << endl; 
		cout << "Press any key to exit" << endl; 
		cin.get();
		return GetLastError();
	}
 
	for (int j = 0; j < 10; j++)
	{
		WaitForSingleObject(hMutex, INFINITE); 
		for (int i = 0; i < 10; i++)
		{
	 		cout << "2 "; 
 			Sleep(5);
 		}
 		cout << endl;
 		ReleaseMutex(hMutex);
 	}
 	
 	CloseHandle(hMutex);
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	
	system("PAUSE");
	
	return 0;
} 
