#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <thread>
#include <mutex>

#define CLIENT_NUMBER 3

using namespace std;

HANDLE* hPipe = new HANDLE[CLIENT_NUMBER];
LPSTR* lpPipeName = new LPSTR[CLIENT_NUMBER]; 

char server_output[255 + 10] = " ";
char **client_input = new char*[CLIENT_NUMBER];
DWORD iBytesToRead = 255;

mutex tMutex;

void ThreadProc_Client(int client)
{   
    while(true){
    	//catch message from client
    	memset(client_input[client], 0, 255);
    	ReadFile(hPipe[0], client_input[client], sizeof(client_input[client]), NULL, NULL);
   		printf("C%i mess read\n", client + 1);

   		tMutex.lock();  //locking critical section
   		
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
   			WriteFile(hPipe[i], server_output, strlen(server_output), NULL, NULL);
   		}
   		printf("C%d mess sent\n", client + 1);
    	tMutex.unlock(); //unlocking critical section
	}
    
    ExitThread(0);
}

int main(void)
{
	thread* Threads = new thread[CLIENT_NUMBER];
	
	lpPipeName[0] = TEXT("\\\\.\\pipe\\MyPipe0");
	lpPipeName[1] = TEXT("\\\\.\\pipe\\MyPipe1");
	lpPipeName[2] = TEXT("\\\\.\\pipe\\MyPipe2");
	
	for (int i = 0; i < CLIENT_NUMBER; i++)
		client_input[i] = new char[255];
		
	
	
	for(int i = 0; i < CLIENT_NUMBER; i++){
		//Creating pipes
		 hPipe[i] = CreateNamedPipe(lpPipeName[i],
                            PIPE_ACCESS_DUPLEX,
                            PIPE_TYPE_MESSAGE |
                            PIPE_READMODE_MESSAGE |
                            PIPE_WAIT,
                            PIPE_UNLIMITED_INSTANCES,
                            4096,
                            4096,
                            NMPWAIT_USE_DEFAULT_WAIT,
                            NULL);
                            
    	if(hPipe[i] == INVALID_HANDLE_VALUE){
    		printf("Pipe hasn't been created\n");
        	return GetLastError();
		} else
        	printf("Pipe created\n");
        	
        //Connecting clients	
        if((ConnectNamedPipe(hPipe[i], NULL)) == 0) {
        	printf("Client %d could not connect\n", i + 1);
        	return 0;
    	} else
			printf("Client %d connected\n", i + 1);
    }
    
    for (int i = 0; i < CLIENT_NUMBER; i++){
		Threads[i] = thread(ThreadProc_Client, i);
		printf("Thread %d created\n", i);
	}
	for (int i = 0; i < CLIENT_NUMBER; i++){
		Threads[i].join();
		printf("Thread %d started\n", i);
	}
    	
    	
	
	for (int i = 0; i < CLIENT_NUMBER; i++)
		CloseHandle(hPipe[i]);
	
	return 0;
}
