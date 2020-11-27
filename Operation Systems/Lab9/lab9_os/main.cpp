#include <iostream>
#include <thread>

using namespace std;

bool readyFlags[2] = {false, false};

int turn = 0;

int criticalSection = 0;

void InterCriticalRegion(int threadId)
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
    InterCriticalRegion(0);
    for (int i = 0; i < 100; i++)
        criticalSection += 1;
    cout << "Thread 1: " << criticalSection << endl;
    ExitCriticalRegion(0);
    // there can be some non critical things
}

void func2(void)
{
    InterCriticalRegion(1);
    for (int i = 0; i < 100; i++)
        criticalSection += 2;
    cout << "Thread 2: " << criticalSection << endl;
    ExitCriticalRegion(1);
    // there can be some non critical things
}

int main(void)
{
    thread t1(func1);
    thread t2(func2);

    t1.join();
    t2.join();

    cout << "At least it's: " << criticalSection << endl;

    return 0;
}

