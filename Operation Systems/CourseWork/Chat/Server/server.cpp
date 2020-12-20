#include <windows.h>
#include <stdio.h>
#include <string.h>

#define CLIENT_NUMBER 3

int main(void)
{
	HANDLE* hPipe = new HANDLE[CLIENT_NUMBER];
	LPSTR* lpPipeName = new LPSTR[CLIENT_NUMBER]; 

	char server_output[255 + 10] = " ";
	char client1_input[255] = " ";
	char client2_input[255] = " ";
	char client3_input[255] = " ";
	DWORD iBytesToRead = 255;
	
	lpPipeName[0] = TEXT("\\\\.\\pipe\\MyPipe0");
	lpPipeName[1] = TEXT("\\\\.\\pipe\\MyPipe1");
	lpPipeName[2] = TEXT("\\\\.\\pipe\\MyPipe2");
	
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
    
    while(true)
    {
    	//catch message from client1
    	memset(client1_input, 0, 255);
    	ReadFile(hPipe[0], client1_input, sizeof(client1_input), NULL, NULL);
    	printf("C1 mess read\n");
		
    	//send message from client1 to all clients
    	for (int i = 0; i < CLIENT_NUMBER; i++){
    		memset(server_output, 0, 265);
    		if (i == 0)
    			strcpy(server_output, "You: ");
			else
				strcpy(server_output, "Client 1: ");
				 
			strcat(server_output, client1_input);
    		WriteFile(hPipe[i], server_output, strlen(server_output), NULL, NULL);
    	}
    	printf("C1 mess sent\n");
    	
    	//catch message from client2
    	memset(client1_input, 0, 255);
    	ReadFile(hPipe[1], client2_input, sizeof(client2_input), NULL, NULL);
    	printf("C2 mess read\n");
			
    	//send message from client2 to all clients
    	for (int i = 0; i < CLIENT_NUMBER; i++){
    		memset(server_output, 0, 265);
    		if (i == 1)
    			strcpy(server_output, "You: ");
			else
				strcpy(server_output, "Client 2: ");
			strcat(server_output, client2_input);
			WriteFile(hPipe[i], server_output, strlen(server_output), NULL, NULL);
		}
    	printf("C2 mess sent\n");
    	
    	//catch message from client3
    	memset(client3_input, 0, 255);
    	ReadFile(hPipe[2], client3_input, sizeof(client3_input), NULL, NULL);
    	printf("C3 mess read\n");
			
    	//send message from client3 to all clients
    	for (int i = 0; i < CLIENT_NUMBER; i++){
    		memset(server_output, 0, 265);
    		if (i == 2)
    			strcpy(server_output, "You: ");
			else
				strcpy(server_output, "Client 3: ");
			strcat(server_output, client3_input);
			WriteFile(hPipe[i], server_output, strlen(server_output), NULL, NULL);
		}
    	printf("C3 mess sent\n");

	}
	
	for (int i = 0; i < CLIENT_NUMBER; i++)
		CloseHandle(hPipe[i]);
		
	return 0;
}
