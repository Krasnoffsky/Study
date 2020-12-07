#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	HANDLE hSemaphore;
	hSemaphore = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "SEM"); 
	if (hSemaphore == NULL)
	{
		cout << "Error SEM" << endl;
		return GetLastError(); 
	}
 		
 	for (int j = 0; j < 10; j++)
	{	
 		WaitForSingleObject(hSemaphore, INFINITE); 
		for (int i = 0; i < 10; i++)
		{
	 		cout << "1 ";
 			Sleep(5);
 		}
 		cout << endl;
 		ReleaseSemaphore(hSemaphore, 1, NULL);
 	}
 	
 	CloseHandle(hSemaphore);
 	
 	//system("PAUSE");
 	
	return 0;
} 
