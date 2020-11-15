#include <stdio.h>
#include <process.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	for(int i = 0; ( i < 255 && argv[1][i] > 0); i++){
		if(argv[1][i] != '"'){
			std::cout << argv[1][i];
		}
	}
	cout << '\n';
	exit(0);
 }
