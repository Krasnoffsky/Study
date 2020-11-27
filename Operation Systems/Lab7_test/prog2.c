#include <windows.h>
#include <conio.h>
typedef int (*fun)(int);
int main(){
HINSTANCE hInst;
fun pf,pg;
int* pa;
while(!_kbhit()){
hInst=LoadLibrary("lib2.dll");
Sleep(5000);
FreeLibrary(hInst);
Sleep(5000);
}
return 0;
}