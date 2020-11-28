#include <iostream>
#include <process.h>
#include <thread>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <chrono>

#define ITERATIONS_NUMBER 100
#define THREADS_NUMBER 2

using namespace std;

bool readyFlags[2] = {false, false};

int turn = 0;

int criticalSection = 0;

void EnterCriticalRegion(int threadId)
{
    readyFlags[threadId] = true;
    turn = 1 - threadId;
    while (turn == 1 - threadId && readyFlags[1 - threadId]);
}

void ExitCriticalRegion(int threadId)
{
    readyFlags[threadId] = false;
}

void func1(void)
{
    for (int i = 0; i < ITERATIONS_NUMBER; i++){
        EnterCriticalRegion(0);
        criticalSection += 5;
        ExitCriticalRegion(0);
        Sleep(10);
    }

}

void func2(void)
{
    for (int i = 0; i < ITERATIONS_NUMBER; i++){
        EnterCriticalRegion(1);
        criticalSection += 5;
        ExitCriticalRegion(1);
        Sleep(10);
    }

}


DWORD dwCounter = 0;
DWORD WINAPI ThreadProc(CONST LPVOID lpParam)
{
    CONST HANDLE hMutex = (CONST HANDLE)lpParam;
    for(DWORD i = 0; i < ITERATIONS_NUMBER; i++)
    {
        WaitForSingleObject(hMutex, INFINITE);
        dwCounter += 5;
        ReleaseMutex(hMutex);
        Sleep(10);
    }
    ExitThread(0);
}

int Peterson(void)
{
    thread t1(func1);
    thread t2(func2);

    auto start = chrono::system_clock::now();

    t1.join();
    t2.join();

    chrono::duration<double> duration = chrono::system_clock::now() - start;

    cout << "Peterson Result = " << criticalSection << endl;
    cout << "Peterson Time = " << criticalSection << endl;

    return 0;
}

int WinAPI_Threads()
{
    DWORD dwTemp;
    HANDLE hThreads[THREADS_NUMBER];
    CONST HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);

    auto start = chrono::system_clock::now();

    for(DWORD i = 0; i < THREADS_NUMBER; i++)
        hThreads[i] = CreateThread(NULL, 0, &ThreadProc, hMutex, 0, NULL);

    WaitForMultipleObjects(THREADS_NUMBER, hThreads, TRUE, INFINITE);

    chrono::duration<double> duration = chrono::system_clock::now() - start;

    cout << "Win API Result = " << dwCounter << endl;
    cout << "Win API Time = " << dwCounter << endl;
    return 0;
}

int main(void)
{
    Peterson();
    cout << endl;
    WinAPI_Threads();

    return 0;
}

