//#include "lib.h"
#include <stdio.h>
#include <process.h>
#include <string.h>
#include <iostream>
#include <sys\stat.h>
using namespace std;

int main(int argc, char* argv[]){
	struct stat buf, fub;
	char newbuf[255] = {0};
	int sizeD,sizeA,sizeB;
	for(int i = 0; i < 255; ++i){
		if(argv[2][i] < 32){
			sizeD = i;
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
		if(i < sizeD){
			newbuf[i] = argv[2][i];
		}
		else if(j < sizeA){
			newbuf[i] = argv[1][j++];
		}
		else{
			sizeB = i;
			break;
		}
	}
	
	stat(newbuf, &buf);
	if(!strcmp(argv[1], "..")){
		if(sizeD < 5){
			exit(0);
		}
		sizeB -= 4;
		while(newbuf[sizeB] != 92){
			newbuf[sizeB--] = 0;
		}
		FILE *f = fopen("dir.txt", "wb");
		sizeA = sizeof(newbuf);
		fwrite(&sizeA, sizeof(int), 1, f);
		fwrite(newbuf, sizeof(newbuf), 1, f);
		fclose(f);
	}
	else{
			stat(argv[1], &fub);
			if(fub.st_ctime && strcmp(argv[1], "..")){
				char str[255] = {0};
				strcpy(str, argv[1]);
				FILE *f = fopen("dir.txt", "wb");
				if(str[sizeA - 1] != 92){
					str[sizeA] = 92;
				}
				sizeA = sizeof(str);
				fwrite(&sizeA, sizeof(int), 1, f);
				fwrite(str, sizeof(str), 1, f);
				fclose(f);
			}
			else{
				if(buf.st_ctime){
					FILE *f = fopen("dir.txt", "wb");
					newbuf[sizeB] = 92;
					sizeA = sizeof(newbuf);
					fwrite(&sizeA, sizeof(int), 1, f);
					fwrite(newbuf, sizeof(newbuf), 1, f);
					fclose(f);
				}
				else	cout << "No such file directory\n";
			}
		}
	exit(0);
 }
