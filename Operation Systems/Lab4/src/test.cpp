#include "lib.h"
#include <stdio.h>
#include <process.h>
#include <iostream>
#include <string.h>
using namespace std;

void printfDir(char *dir){
	for(int i = 0; i < 255 && dir[i] > 0; ++i){
		if(dir[i] == '/'){
			dir[i] = 92;
		} 
		cout << dir[i];
	}
}

int main(){
	cout << (int)'\0';
	return 0;
 }
