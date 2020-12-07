#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	HANDLE hMutex;
	hMutex = OpenMutex(SYNCHRONIZE, FALSE, "Mutex"); 
	if (hMutex == NULL)
	{
		cout << "Open mutex failed" << endl;
		cout << "Press any key to exit" << endl;
		cin.get();
		return GetLastError();
    } 
 	for (int j = 0; j < 10; j++)
	{	
 		WaitForSingleObject(hMutex, INFINITE); 
		for (int i = 0; i < 10; i++)
		{
	 		cout << "1 ";
 			Sleep(5);
 		}
 		cout << endl;
 		ReleaseMutex(hMutex);
 	}
 	
 	CloseHandle(hMutex);
 	
 	system("PAUSE");
 	
	return 0;
} 
