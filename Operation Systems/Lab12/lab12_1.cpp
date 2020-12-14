#include <windows.h>
#include <imagehlp.h>
#include <stdio.h>
#include <process.h>
#pragma comment(lib, "Dbghelp.lib")

HANDLE hFileMapOut;
LPVOID MapViewOut;

void Export(IMAGE_NT_HEADERS *pNtHdr, LPVOID pSrcFile)
{
	char buff[CHAR_MAX] = {'\0'};
	IMAGE_EXPORT_DIRECTORY* ExpTable;
	char *pName, *sName, **pNames;
	DWORD nNames;
	DWORD RVAExpDir, VAExpAddress;
	int i;

	RVAExpDir = pNtHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	VAExpAddress = (DWORD)ImageRvaToVa(pNtHdr, pSrcFile, RVAExpDir, NULL);
	ExpTable = (IMAGE_EXPORT_DIRECTORY*)VAExpAddress;

	sName = (char*)ImageRvaToVa(pNtHdr, pSrcFile, ExpTable->Name, NULL);
	strcat(buff, "Name of PEF:  ");
	strcat(buff, sName);
	printf("Name of PEF:  %s\n", sName);
	CopyMemory(MapViewOut, buff, CHAR_MAX);
	Sleep(20);
	
	pNames = (char**)ImageRvaToVa(pNtHdr, pSrcFile, ExpTable->AddressOfNames, NULL);
	nNames = ExpTable->NumberOfNames;
	printf("Exported data: \n");
	CopyMemory(MapViewOut, "Exported data: ", CHAR_MAX);
	Sleep(20);
	for(i = 0; i < nNames; i++)
	{
		pName = (char*)ImageRvaToVa(pNtHdr, pSrcFile,(DWORD)*pNames, NULL);
		printf("%s\n",pName);
		CopyMemory(MapViewOut, pName, CHAR_MAX);
		Sleep(20);
		//system("PAUSE");
		*pNames++;
	}
}

void Import(IMAGE_NT_HEADERS *pNtHdr, LPVOID pSrcFile)
{
	char *pName, *sName, **pNames;
	DWORD nNames;
	DWORD RVAExpDir, VAExpAddress;
	IMAGE_IMPORT_DESCRIPTOR* ImportTable;
	
	RVAExpDir = pNtHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
	VAExpAddress = (DWORD)ImageRvaToVa(pNtHdr, pSrcFile, RVAExpDir, NULL);
	ImportTable = (IMAGE_IMPORT_DESCRIPTOR*)VAExpAddress;

	printf("Imported data: \n");
	CopyMemory(MapViewOut,"Imported data: ",CHAR_MAX);
	Sleep(20);
	
	while(ImportTable->Name != NULL)
	{
		pNames = (char**)ImageRvaToVa(pNtHdr, pSrcFile, ImportTable->FirstThunk, NULL);
		sName = (char*)ImageRvaToVa(pNtHdr, pSrcFile, ImportTable->Name, NULL); 
		SecureZeroMemory(MapViewOut, CHAR_MAX);
		char buff[CHAR_MAX] = {'\0'};
		printf("Name of PEF:  %s\n", sName);
		strcpy(buff, "Name of PEF:   ");
		strcat(buff, sName);
		CopyMemory(MapViewOut, buff, CHAR_MAX);
		Sleep(20);
		
		//system("Pause");

		while(pName != 0)
		{
			pName = (char*)ImageRvaToVa(pNtHdr, pSrcFile, (DWORD)*pNames+2, NULL);
			if(pName != 0)
			{
				char buff2[CHAR_MAX] = {'\0'};
				strcpy(buff2,"	");
				strcat(buff2,pName);
				printf("     %s\n",pName);
				CopyMemory(MapViewOut,buff2,CHAR_MAX);
				Sleep(1);
  		 	}
			*pNames++;
		}
		*pName++;
		ImportTable++;
	}
}

int main(){
	char buff[10];
	HANDLE hFileMap, hFile;
	LPVOID pSrcFile;
	IMAGE_DOS_HEADER *pDosHeader;
	IMAGE_NT_HEADERS *pNtHdr;
	IMAGE_SECTION_HEADER *pFirstSectionHeader, *pSectionHeader;
	
	hFileMapOut = CreateFileMapping((HANDLE)0xFFFFFFFF, NULL, PAGE_READWRITE, 0, CHAR_MAX, "Lab12");
	MapViewOut = MapViewOfFile(hFileMapOut, FILE_MAP_WRITE, 0, 0, CHAR_MAX);

	hFile = CreateFile ("c:\\Windows\\System32\\kernel32.dll", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL); 
	if (hFile == INVALID_HANDLE_VALUE)
		printf("Could not open file.");
		
	hFileMap = CreateFileMapping (hFile, NULL, PAGE_READONLY, 0, 0, NULL); 
	if(hFileMap == NULL)
		printf("Could not create mapping file.");
		
	pSrcFile = (PBYTE) MapViewOfFile(hFileMap, FILE_MAP_READ, 0, 0, 0); 
	if(pSrcFile == NULL)
		printf("Could not map file.");


 	pDosHeader = (IMAGE_DOS_HEADER *)pSrcFile; 
	pNtHdr = (IMAGE_NT_HEADERS *)((DWORD)pDosHeader + pDosHeader->e_lfanew); 

	
	system("Start  C:\\Study\\Operation Systems\\Lab12\\lab12_2.exe");
	Sleep(20);
	Export(pNtHdr, pSrcFile);
	//system("PAUSE");
	Import(pNtHdr, pSrcFile);
	CopyMemory(MapViewOut, "OUT", CHAR_MAX);
	system("PAUSE");

	UnmapViewOfFile(MapViewOut);
	UnmapViewOfFile(hFileMap);
 	CloseHandle(hFileMapOut);
	CloseHandle(hFileMap);
	
	return 0;
}
