#include <windows.h>
#include <stdio.h>
#include <string.h>

#define CLIENT_NUMBER 3

int main(void)
{
	HANDLE* hPipe = new HANDLE[CLIENT_NUMBER];
	LPSTR* lpPipeName = new LPSTR[CLIENT_NUMBER]; 

//	char server_output[255 * 2];
	char client1_input[255];
	char client2_input[255];
	char client3_input[255];
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
        	printf("Client %d could not connect\n", i);
        	return 0;
    	} else
			printf("Client %d connected\n", i);
    }
    
    while(true)
    {
    	//catch message from client1
    	ReadFile(hPipe[0], client1_input, sizeof(client1_input), NULL, NULL);
    	printf("test1\n");
		
    	//send message from client1 to all clients
    	for (int i = 0; i < CLIENT_NUMBER; i++)
    		WriteFile(hPipe[i], client1_input, strlen(client1_input), NULL, NULL);
    	
    	printf("test2\n");
    	
    	//catch message from client2
    	ReadFile(hPipe[1], client2_input, sizeof(client2_input), NULL, NULL);
    	printf("test3\n");
			
    	//send message from client2 to all clients
    	for (int i = 0; i < CLIENT_NUMBER; i++)
    		WriteFile(hPipe[i], client2_input, strlen(client2_input), NULL, NULL);
    	printf("test4\n");
    	//catch message from client3
    	ReadFile(hPipe[2], client3_input, sizeof(client3_input), NULL, NULL);
    	printf("%c\n", *client3_input);

    	printf("test5\n");	
    	//send message from client3 to all clients
    	for (int i = 0; i < CLIENT_NUMBER; i++)
    		WriteFile(hPipe[i], client3_input, strlen(client3_input), NULL, NULL);
    		printf("test6\n");

	}
	
	for (int i = 0; i < CLIENT_NUMBER; i++)
		CloseHandle(hPipe[i]);
		
	return 0;
}
