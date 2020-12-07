#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	char lpszAppName[] = "C:\\Study\\Operation Systems\\Lab11\\1_sem.exe";
	HANDLE hSemaphore;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	hSemaphore = CreateSemaphore(NULL, 1, 20, "SEM");
 	if (hSemaphore == NULL)
 	{
 		cout << "Error SEM" << endl;
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
		WaitForSingleObject(hSemaphore, INFINITE);
		for (int i = 0; i < 10; i++)
		{
	 		cout << "2 "; 
 			Sleep(5);
 		}
 		cout << endl;
 		ReleaseSemaphore(hSemaphore, 1, NULL);
 	}
 	
 	CloseHandle(hSemaphore);
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	
	system("PAUSE");
	
	return 0;
} 
