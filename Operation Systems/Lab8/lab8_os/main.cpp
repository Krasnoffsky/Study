#include <iostream>
#include <thread>

using namespace std;

int sum = 0;

void func1()
{
    for(int i = 0; i < 10000; i++) sum += 1;
}

int main()
{
    thread t1(func1);
    thread t2(func1);
    thread t3(func1);

    t1.join();
    t2.join();
    t3.join();

    cout << sum;
    return 0;
}
