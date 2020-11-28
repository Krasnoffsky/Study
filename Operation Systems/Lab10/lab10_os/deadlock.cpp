#include <windows.h>
#include <process.h>
#include <stdio.h>

HANDLE hMutex1, hMutex2;
double sh1=0.0;
int sh2=0;
void Thread(void* pParams);

   int main(void) {
    hMutex1=CreateMutex(NULL,FALSE,NULL);
    hMutex2=CreateMutex(NULL,FALSE,NULL);

    _beginthread( Thread, 0, NULL );

    while( 1){
        WaitForSingleObject(hMutex1, INFINITE);//захват
        printf("%g\n",sh1);
        WaitForSingleObject(hMutex2, INFINITE);//захват
        printf("%d\n",sh2);
        ReleaseMutex(hMutex2);//освобождение
        ReleaseMutex(hMutex1);//освобождение
    }
    return 0;
}

void Thread( void* pParams ){
    while (1){
        WaitForSingleObject(hMutex2, INFINITE);//захват мьютекса
        sh2++;
        WaitForSingleObject(hMutex1, INFINITE);//захват мьютекса
        sh1+=0.1;
        ReleaseMutex(hMutex1); //освобождение мьютекса
        ReleaseMutex(hMutex2); //освобождение мьютекса
    }
 }
