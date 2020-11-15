#include <cmath>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <windows.h>

using namespace std;

double timeStart = 0;
double* timeCountRead;
double* timeCountWrite;

void bTimer(char type[], char task[], int number_try)
{
    if (strcmp(task, "START") == 0){
        timeStart = clock();
    } else if(strcmp(task, "STOP") == 0){
        if (strcmp(type, "READ"))
            timeCountRead[number_try] = ((double)(clock() - timeStart)) / CLOCKS_PER_SEC;
        else if (strcmp(type, "WRITE"))
            timeCountWrite[number_try] = ((double)(clock() - timeStart)) / CLOCKS_PER_SEC;
    }
}

void RAMTestWrite(int size)
{
    char staticMas[size];
    char* dynamicMas = new char[size];

    for (int i = 0; i < size; i++){
        staticMas[i] = 'a';
    }

    bTimer("WRITE", "START", 1);
    for (int i = 0; i < size; i++){
        dynamicMas[i] = staticMas[i];
    }
    bTimer("WRITE", "STOP", 1);

    delete dynamicMas;
}

void RAMTestRead(int size)
{
    char staticMas[size];
    char* dynamicMas = new char[size];

    for (int i = 0; i < size; i++){
        staticMas[i] = 'a';
    }

    bTimer("READ", "START", 1);
    for (int i = 0; i < size; i++){
        staticMas[i] = dynamicMas[i];
    }
    bTimer("READ", "STOP", 1);

    delete dynamicMas;
}

void ROMTestWrite(int size)
{
    char* mas = new char[size];
    for (int i = 0; i < size; i++){
        mas[i] = 'a';
    }

    bTimer("WRITE", "START", 1);
    ofstream fileROM("testROM.bin", ios::out);
    for (int i = 0; i < size; i++){
        fileROM << mas[i];
    }
    fileROM.close();
    bTimer("WRITE", "STOP", 1);

    delete mas;
}

void ROMTestRead(int size)
{
    char* mas = new char[size];

    bTimer("READ", "START", 1);
    ifstream fileROM("testROM.bin", ios::in);
    for (int i = 0; i < size; i++){
        fileROM >> mas[i];
    }
    fileROM.close();
    bTimer("READ", "STOP", 1);

    delete mas;
}

void FlashTestWrite(int size)
{
    char* mas = new char[size];
    for (int i = 0; i < size; i++){
        mas[i] = 'a';
    }

    bTimer("WRITE", "START", 1);
    ofstream fileROM("D:\testROM.bin", ios::out);
    for (int i = 0; i < size; i++){
        fileROM << mas[i];
    }
    fileROM.close();
    bTimer("WRITE", "STOP", 1);

    delete mas;
}

void FlashTestRead(int size)
{
    char* mas = new char[size];

    bTimer("READ", "START", 1);
    ifstream fileROM("D:\testROM.bin", ios::in);
    for (int i = 0; i < size; i++){
        fileROM >> mas[i];
    }
    fileROM.close();
    bTimer("READ", "STOP", 1);

    delete mas;
}

int main (int argc, char *argv[]) //now only for tests
{
    string memory_type, input_block_size, temp;
    int number_of_test, blockSize;

    for(int i = 1; i < 7; i++)
    {
        if((string)argv[i] == "-m")
        {
            memory_type = argv[i + 1];
            if( memory_type == "RAM" and
                memory_type == "HDD" and
                memory_type == "SSD" and
                memory_type == "flash" )
            {
                cout << "\nError(input MEMORY_TYPE)";
                return 1;
            }
        }

        else if((string)argv[i] == "-b")
        {
            input_block_size = argv[i + 1];
            if( input_block_size[input_block_size.size() - 2] != 'K' and
                input_block_size[input_block_size.size() - 2] != 'M')
                blockSize = atoi(input_block_size.c_str());
            else
            {
                for (int j = 0; j < input_block_size.size() - 2; j++)
                    temp[j] = input_block_size[j];

                if(input_block_size[input_block_size.size() - 2] == 'K')
                    blockSize = atoi(temp.c_str()) * 1024;

                else
                    blockSize = atoi(temp.c_str()) * 1024 * 2;
            }
        }
        else if((string)argv[i] == "-l") number_of_test = atoi(argv[i + 1]);
        else ;
    }

    cout << endl << memory_type;
    cout << endl << blockSize;
    cout << endl << number_of_test;

    /*
    const int size = 1000000;
    timeCountRead = new double[size];
    timeCountWrite = new double[size];
    RAMTestWrite(size);
    RAMTestRead(size);
    cout << setprecision(15) << "RAM:" << endl << "\t Write = " << timeCountWrite[1] << endl << "\t Read = " << timeCountRead[1] << endl;
    ROMTestWrite(size);
    ROMTestRead(size);
    cout << setprecision(15) << "ROM:" << endl << "\t Write = " << timeCountWrite[1] << endl << "\t Read = " << timeCountRead[1] << endl;
    FlashTestWrite(size);
    FlashTestRead(size);
    cout << setprecision(15) << "Flash:" << endl << "\t Write = " << timeCountWrite[1] << endl << "\t Read = " << timeCountRead[1] << endl;
    */
}
