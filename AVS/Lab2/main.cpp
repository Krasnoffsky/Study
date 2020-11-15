#include <cmath>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <iostream>
#include <windows.h>
#include <fstream>

#define PROCESSOR_TYPE "AMD A6-9225"
using namespace std;

const double eps = 0.000001;
double timeStart = 0;
double* timeCount;
double AbsErr;
double RelErr;
double dispersion = 0, deviation = 0;

struct Info {
    string PModel;
    string Task;
    string OpType;
    string Opt;
    int LNum;
    int InsCount;
    double AvTime;
    double AbsError;
    double RelError;
    double TaskPerf;
};



void bTimer(char task[], int number_try)
{
    if (strcmp(task, "START") == 0){
        timeStart = clock();
    } else if(strcmp(task, "STOP") == 0){
        timeCount[number_try] = ((double)(clock() - timeStart)) / CLOCKS_PER_SEC;
    }
}

void bAccuracy(int number_of_tests)
{
    double temp = 0;
    double average = 0;
    for (int  i = 0; i < number_of_tests; i++){
        average += timeCount[i];
    }
    average /= number_of_tests;
    for (int i = 0; i < number_of_tests; i++){
        AbsErr += (timeCount[i] - average);
    }
    AbsErr /= number_of_tests;
    RelErr = AbsErr / average;

    dispersion = 0;
    deviation = 0;

    for (int i = 0; i < number_of_tests; i++){
        dispersion += sqrt(timeCount[i] - average);
    }
    dispersion /= number_of_tests;
    deviation = sqrt(dispersion);

}

template < typename testT >
float testSort(int &number_try)
{//Сортировка
    bool swaped;

    int n = 300;

    testT **massiv = new testT* [n];
    for (int i = 0; i < n; i++) massiv[i] = new testT [n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            massiv[i][j] = rand();

    bTimer("START", number_try);
    for(int str = 0; str < n; str++)
    {//сортируем строки
        for(int i = 1, swap, temp_n = n; temp_n > 1; temp_n--)
        {
            swaped = false;
            for(int j = i; j < temp_n; j++)
            {
                if(massiv[str][j - 1] > massiv[str][j])
                {
                    swaped = true;

                    swap = massiv[str][j];
                    massiv[str][j] = massiv[str][j - 1];
                    massiv[str][j - 1] = swap;
                }
            }
            if(swaped == false) break;
        }
    }

    for(int slbc = 0; slbc < n; slbc++)
    {//сортируем столбцы
        for(int i = 1, swap, temp_n = n; temp_n > 1; temp_n--)
        {
            swaped = false;
            for(int j = i; j < temp_n; j++)
            {
                if(massiv[j - 1][slbc] > massiv[j][slbc])
                {
                    swaped = true;

                    swap = massiv[j][slbc];
                    massiv[j][slbc] = massiv[j - 1][slbc];
                    massiv[j - 1][slbc] = swap;
                }
            }
            if(swaped == false) break;
        }
    }

    bTimer("STOP", number_try);
    return (double)(*timeCount) / CLOCKS_PER_SECS;
}

int main()
{

    SYSTEM_INFO siSysInfo;
    GetSystemInfo(&siSysInfo);

    int number_of_tests;
    string type;
    srand(time(0));

    cout << endl << "Enter the number of tests: ";
    cin >> number_of_tests;

    cout << endl << "Enter type data: ";
    cin >> type;
    timeCount = new double[number_of_tests];

    float avTimeTest = 0;
    if(type == "int") for(int i = 0; i < number_of_tests; i++) avTimeTest += testSort<int>(i);
    else if(type == "float") for(int i = 0; i < number_of_tests; i++) avTimeTest += testSort<float>(i);
    else if(type == "double")for(int i = 0; i < number_of_tests; i++) avTimeTest += testSort<double>(i);
    else
    {
        cout << endl << "Can't found type name";
        return 1;
    }
    
    avTimeTest /= number_of_tests * 300 * 300;
	double opers = number_of_tests * 300 * 300;
    double taskPerfomance = opers / avTimeTest;

    bAccuracy(number_of_tests);
    Info *info = new Info;
    info->PModel = PROCESSOR_TYPE;
    info->Task = "Sort";
    info->OpType = type;
    info->Opt = "O1";
    info->LNum = number_of_tests;
    info->InsCount = opers;
    info->AvTime = avTimeTest;
    info->AbsError = AbsErr;
    info->RelError = RelErr;
    info->TaskPerf = taskPerfomance;

    ofstream file("text.csv", ios::app);
    if(!file.is_open())
    {
        cout << endl << "Can't open/find file template_vmf_end.txt" << endl;
        return 1;
    }
    else
    {
        file    << info->PModel << ";"
                << info->Task << ";"
                << info->OpType << ";"
                << info->Opt << ";"
                << info->LNum << ";"
                << info->InsCount << ";"
                << info->AvTime << ";"
                << info->AbsError << ";"
                << info->RelError << ";"
                << info->TaskPerf << endl;
    }
    file.close();
    cout << endl << "Complete, AT = " << avTimeTest;
}

