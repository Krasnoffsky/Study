#include <windows.h>
#include <stdio.h>

int main(){
	HANDLE hFileMap;
	LPVOID lpMapView;
	char buff[80];

	hFileMap = OpenFileMapping(FILE_MAP_READ, TRUE, "Lab12");
	lpMapView = MapViewOfFile(hFileMap, FILE_MAP_READ, 0, 0, CHAR_MAX);
	while(1)
	{
		Sleep(1);
		CopyMemory(buff, lpMapView, 80);
		if (strcmp(buff, "OUT") == 0)
			break;

		if (buff != NULL)
			printf("%s\n", buff);
	}
	UnmapViewOfFile(lpMapView);
	CloseHandle(hFileMap);
	system("PAUSE");
	return 0;
}
