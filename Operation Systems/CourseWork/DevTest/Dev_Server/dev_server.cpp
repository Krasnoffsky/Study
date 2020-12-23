#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <process.h> 

#define CLIENT_NUMBER 3

using namespace std;

HANDLE* hPipeInput = new HANDLE[CLIENT_NUMBER];
HANDLE* hPipeOutput = new HANDLE[CLIENT_NUMBER];
LPSTR* lpPipeNameInput = new LPSTR[CLIENT_NUMBER];
LPSTR* lpPipeNameOutput = new LPSTR[CLIENT_NUMBER]; 

CONST HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);

char server_output[255 + 10] = " ";
char **client_input = new char*[CLIENT_NUMBER];
DWORD iBytesToRead = 255;



DWORD WINAPI ThreadProc(CONST LPVOID lpParam)
{	
	
    int client = int(lpParam);

    printf("Thread %i started\n", client);
	while(true){
    	//catch message from client
    	memset(client_input[client], 0, 255);
    	printf("Thread %d waiting for message\n", client);
    	ReadFile(hPipeInput[client], client_input[client], sizeof(client_input[client]), NULL, NULL);
   		printf("C%i mess read\n", client + 1);

   		WaitForSingleObject(hMutex, INFINITE);  //locking critical section
   		
   		//send messages to all clients
   		for (int i = 0; i < CLIENT_NUMBER; i++){
   			memset(server_output, 0, 265);
   			if (i == client)
   				strcpy(server_output, "You: ");
			else {
				strcpy(server_output, "Client");
				strcat(server_output, reinterpret_cast<char*>(i));
				strcat(server_output, " : ");
			}
							 
			strcat(server_output, client_input[client]);
   			WriteFile(hPipeOutput[i], server_output, strlen(server_output), NULL, NULL);
   		}
   		printf("C%d mess sent\n", client + 1);
    	ReleaseMutex(hMutex); //unlocking critical section
	}
    
    ExitThread(0);
}

int main(void)
{
	HANDLE hThreads[CLIENT_NUMBER];
	
	lpPipeNameInput[0] = TEXT("\\\\.\\pipe\\MyPipeIn0");
	lpPipeNameInput[1] = TEXT("\\\\.\\pipe\\MyPipeIn1");
	lpPipeNameInput[2] = TEXT("\\\\.\\pipe\\MyPipeIn2");
	
	lpPipeNameOutput[0] = TEXT("\\\\.\\pipe\\MyPipeOut0");
	lpPipeNameOutput[1] = TEXT("\\\\.\\pipe\\MyPipeOut1");
	lpPipeNameOutput[2] = TEXT("\\\\.\\pipe\\MyPipeOut2");
	
	
	for (int i = 0; i < CLIENT_NUMBER; i++)
		client_input[i] = new char[255];
		
	
	
	for(int i = 0; i < CLIENT_NUMBER; i++){
		//INPUT
		 hPipeInput[i] = CreateNamedPipe(lpPipeNameOutput[i],
                            PIPE_ACCESS_DUPLEX,
                            PIPE_TYPE_MESSAGE |
                            PIPE_READMODE_MESSAGE |
                            PIPE_WAIT,
                            PIPE_UNLIMITED_INSTANCES,
                            4096,
                            4096,
                            NMPWAIT_USE_DEFAULT_WAIT,
                            NULL);
                            
    	if(hPipeInput[i] == INVALID_HANDLE_VALUE){
    		printf("Input pipe hasn't been created\n");
        	return GetLastError();
		} else
        	printf("Input pipe created\n");
        	
        //Connecting clients	
        if((ConnectNamedPipe(hPipeInput[i], NULL)) == 0) {
        	printf("Client %d could not connect for input\n", i + 1);
        	return 0;
    	} else
			printf("Client %d connected for input\n", i + 1);
			
		//OUTPUT
			
		hPipeOutput[i] = CreateNamedPipe(lpPipeNameOutput[i],
                            PIPE_ACCESS_DUPLEX,
                            PIPE_TYPE_MESSAGE |
                            PIPE_READMODE_MESSAGE |
                            PIPE_WAIT,
                            PIPE_UNLIMITED_INSTANCES,
                            4096,
                            4096,
                            NMPWAIT_USE_DEFAULT_WAIT,
                            NULL);
                            
    	if(hPipeOutput[i] == INVALID_HANDLE_VALUE){
    		printf("Output pipe hasn't been created\n");
        	return GetLastError();
		} else
        	printf("Output pipe created\n");
        	
        //Connecting clients	
        if((ConnectNamedPipe(hPipeOutput[i], NULL)) == 0) {
        	printf("Client %d could not connect for Output\n", i + 1);
        	return 0;
    	} else
			printf("Client %d connected for Output\n", i + 1);
    }
    
    for(DWORD i = 0; i < CLIENT_NUMBER; i++){
    	hThreads[i] = CreateThread(NULL, 0, &ThreadProc, (LPVOID)i, 0, NULL);
		printf("Thread %d created\n", i + 1);
	}
        

    WaitForMultipleObjects(CLIENT_NUMBER, hThreads, TRUE, INFINITE);
    		
	CloseHandle(hPipeInput);
	CloseHandle(hPipeOutput);
	
	system("PAUSE");
	
	return 0;
}
