#include <stdio.h>
#include <process.h>
#include <string.h>
#include <iostream>
#include <sys\stat.h>
using namespace std;

int main(int argc, char* argv[]){
	int sizeA, sizeB, sizeC;
	char newbuf[255] = {0};
	for(int i = 0; i < 255; ++i){
		if(argv[2][i] < 32){
			sizeB = i;
			break;
		}
	}
	for(int i = 0; i < 255; ++i){
		if(argv[1][i] < 32){
			sizeA = i;
			break;
		}
	}
	for(int i = 0, j = 0; i < 255; i++){
		if(i < sizeA){
			newbuf[i] = argv[1][i];
		}
		else if(j < sizeB){
			newbuf[i] = argv[2][j++];
		}
		else{
			sizeC = i;
			break;
		}
	}
	if(!remove(newbuf)){
		cout << "Successfully deleted\n";
	}
	else{
		cout << "Delete error\n";
	}
	exit(0);
 }
