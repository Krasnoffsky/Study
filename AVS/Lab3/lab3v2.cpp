#include <cmath>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <windows.h>

#define NANOSEC_TO_SEC 1000000000 

using namespace std;

timespec* timeStart = new timespec;
timespec* timeEnd = new timespec;
double* timeWrite;
double* timeRead;

double secondTimeStart = 0;
double* timeCountWrite;
double* timeCountRead;

int cash[4] = {
	131042,
	1048576,
	3145728,
	80 * 1024 * 1024
};

string memory_type;
int number_of_tests, customBlockSize;
int size_of_buffer = 4;
double absErrorWrite;
double realErrorWrite;
double absErrorRead;
double realErrorRead;

struct info {
	string memType;
	double blockSize;
	string elementType;
	int buffSize;
	int launchNum;
	string timer;
	double writeTime;
	double averageWriteTime;
	double writeBandwidth;
	double writeAbsError;
	double writeRealError;
	double readTime;
	double averageReadTime;
	double readBandwidth;
	double readAbsError;
	double readRealError;
};

void BenchTimer(string type, string task, int number_try) //timer counting in nanosecs
{
	if (task == "START"){
        clock_gettime(CLOCK_REALTIME, timeStart);
    }
	else if(task == "STOP"){
    	clock_gettime(CLOCK_REALTIME, timeEnd);
    	double current = (double)((timeEnd->tv_nsec - timeStart->tv_nsec) + NANOSEC_TO_SEC * (timeEnd->tv_sec - timeStart->tv_sec)) / NANOSEC_TO_SEC;
    	if (type == "READ"){
    		timeRead[number_try] = current;
		}
		else if (type == "WRITE"){
			timeWrite[number_try] = current;
		}
    }
}


void bTimer(string type, string task, int number_try)
{
    if (task == "START"){
        secondTimeStart = clock();
    } else if(task == "STOP"){
    	if (type == "WRITE"){
    		timeCountWrite[number_try] = ((double)(clock() - secondTimeStart)) / CLOCKS_PER_SEC;
		} else if (type == "READ"){
			timeCountRead[number_try] = ((double)(clock() - secondTimeStart)) / CLOCKS_PER_SEC;
		}       
    }
}

void RAMTestWrite(int size, int number_try) // test fo RAM in writing
{
	int* staticMas = new int[size];
	int* dynamicMas = new int[size];

	for (int i = 0; i < size; i++){
		staticMas[i] = rand()%100; 
	}
	BenchTimer("WRITE", "START", number_try); //start timer
	bTimer("WRITE", "START", number_try);
	for (int i = 0; i < size; i++){
		dynamicMas[i] = staticMas[i];
	}
	BenchTimer("WRITE", "STOP", number_try);//stop timer
	bTimer("WRITE", "STOP", number_try);
	
	delete dynamicMas;
	delete staticMas;	
}

void RAMTestRead(int size, int number_try) // test for RAM in reading
{
	int* staticMas = new int[size];
	int* dynamicMas = new int[size];
	for (int i = 0; i < size; i++){
		staticMas[i] = rand()%100; 
	}
	BenchTimer("READ", "START", number_try); //start timer
	bTimer("READ", "START", number_try);
	for (int i = 0; i < size; i++){
		staticMas[i] = dynamicMas[i];
	}
	BenchTimer("READ", "STOP", number_try); //stop timer
	bTimer("READ", "STOP", number_try);
	
	delete dynamicMas;
	delete staticMas;
}

void ROMTestWrite(int size, int number_try) //test for SSD or HDD in writing 
{
	long long int* mas = new long long int[size];
	for (int i = 0; i < size; i++){
		mas[i] = rand()%100;
	}
	BenchTimer("WRITE", "START", number_try);  //start timer
	bTimer("WRITE", "START", number_try);
	ofstream fileROM("testROM.bin", ios::out);
	for (int i = 0; i < size; i++){
		fileROM << mas[i];                     //writing in file
	}
	fileROM.close();
	BenchTimer("WRITE", "STOP", number_try);   //stop timer
	bTimer("WRITE", "STOP", number_try); 
	delete mas;
}

void ROMTestRead(int size, int number_try) //test for SSD or HDD in reading
{
	long long int* mas = new long long int[size];
	
	BenchTimer("READ", "START", number_try); //start timer
	bTimer("READ", "START", number_try);
	ifstream fileROM("testROM.bin", ios::in);
	for (int i = 0; i < size; i++){
		fileROM >> mas[i];					 //read from file
	}
	fileROM.close();
	BenchTimer("READ", "STOP", number_try);  //stop timer
	bTimer("READ", "STOP", number_try);
	
	delete mas;
}

void FlashTestWrite(int size, int number_try) //test for flash in writing
{
	int* mas = new int[size];
	for (int i = 0; i < size; i++){
		mas[i] = rand()%100;
	}
	
	BenchTimer("WRITE", "START", number_try);
	bTimer("WRITE", "START", number_try);
	ofstream fileROM("D:\testROM.bin", ios::out);
	for (int i = 0; i < size; i++){
		fileROM << mas[i];
	}
	fileROM.close();
	BenchTimer("WRITE", "STOP", number_try);
	bTimer("WRITE", "STOP", number_try);
	
	delete mas;
}

void FlashTestRead(int size, int number_try) // test for flash in reading
{
	int* mas = new int[size];
	
	BenchTimer("READ", "START", number_try);
	bTimer("READ", "START", number_try);
	ifstream fileROM("D:\testROM.bin", ios::in);
	for (int i = 0; i < size; i++){
		fileROM >> mas[i];
	}
	fileROM.close();
	BenchTimer("READ", "STOP", number_try);
	bTimer("READ", "STOP", number_try);
	
	delete mas;
}

double AverageTimeCounter(string type, int size)
{	
	double average = 0;
	if (type == "WRITE"){
		for (int i = 0; i < size; i++){
			average += timeWrite[i];
		}
		average /= size;
	}
	else if (type == "READ"){
		for (int i = 0; i < size; i++){
			average += timeRead[i];
		}
		average /= size;
	}
	
	return abs(average);
}

void Accuracy(int number_try)
{
	absErrorWrite = abs(timeWrite[number_try] - timeCountWrite[number_try]);
	absErrorRead = abs(timeRead[number_try] - timeCountRead[number_try]);
	realErrorWrite = absErrorWrite / timeCountWrite[number_try] * 100;
	realErrorRead = absErrorRead / timeCountRead[number_try] * 100;

}

void KeyReader(int N, char *key[])
{
	
	string input_block_size, temp;

    for(int i = 1; i < N; i++)
    {
        if((string)key[i] == "-m")
        {
            memory_type = key[i + 1];
            if( memory_type != "RAM" and
                memory_type != "HDD" and
                memory_type != "SSD" and
                memory_type != "flash")
            {
                cout << "\nError(input MEMORY_TYPE)";
                break;
            }
        }

        else if((string)key[i] == "-b")
        {
            input_block_size = key[i + 1];
            if( input_block_size[input_block_size.size() - 2] != 'K' and
                input_block_size[input_block_size.size() - 2] != 'M')
                customBlockSize = atoi(input_block_size.c_str());
            else
            {
                for (int j = 0; j < input_block_size.size() - 2; j++)
                    temp[j] = input_block_size[j];

                if(input_block_size[input_block_size.size() - 2] == 'K')
                    customBlockSize = atoi(temp.c_str()) * 1024;

                else
                    customBlockSize = atoi(temp.c_str()) * 1024 * 1024;
            }
        }
        else if((string)key[i] == "-l") number_of_tests = atoi(key[i + 1]);
        else ;
    }
}

void FileWriter(int block, int num)
{	
	info* output = new info;
	output->memType = memory_type;
	output->elementType = "int";
	output->blockSize = block ;
	output->buffSize = size_of_buffer;
	output->launchNum = num;
	output->writeTime = timeWrite[num - 1];
	output->readTime = timeRead[num - 1];
	output->readAbsError = absErrorRead;
	output->writeAbsError = absErrorWrite;
	output->readRealError = realErrorRead;
	output->writeRealError = realErrorWrite;
	output->averageWriteTime = AverageTimeCounter("WRITE", num);
	output->averageReadTime = AverageTimeCounter("READ", num);
	output->writeBandwidth = (double)block / output->averageWriteTime;
	output->readBandwidth = (double)block / output->averageReadTime;
	output->timer = "clock_gettime()";
	
	ofstream file("text.csv", ios::app);
    if(!file.is_open())
    {
        cout << endl << "Can't open/find file template_vmf_end.txt" << endl;
    }
    else
    {
        file    << output->memType << ";"
				<< output->blockSize << ";"
				<< output->elementType << ";"
				<< output->buffSize << ";"
				<< output->launchNum << ";"
				<< output->timer << ";"
				<< output->writeTime << ";"
				<< output->averageWriteTime << ";"
				<< output->writeBandwidth << ";"
				<< output->writeAbsError << ";"
				<< output->writeRealError << ";"
				<< output->readTime << ";"
				<< output->averageReadTime << ";"
				<< output->readBandwidth << ";"
				<< output->readAbsError << ";"
				<< output->readRealError <<  endl;
    }
    file.close();
    
    free(output);
}

int main (int argc, char *argv[])
{	
	memory_type = "RAM";
	KeyReader(argc, argv);
	
	if (memory_type == "HDD" || memory_type == "SSD"){
		number_of_tests = 20;
		int ROMBlockSize = 0;
		int blockStep = 4 * 1024 * 1024; //4 Mb
		timeWrite = new double[number_of_tests];
		timeRead = new double[number_of_tests];
		timeCountWrite = new double[number_of_tests];
		timeCountRead = new double[number_of_tests];

		for (int i = 0; i < number_of_tests; i++){
			
			ROMBlockSize += blockStep;
			ROMTestWrite(ROMBlockSize / size_of_buffer, i);
			ROMTestRead(ROMBlockSize / size_of_buffer, i);
			Accuracy(i);
			cout << i + 1 <<") Write = " << timeWrite[i] << " Read = " << timeRead[i] << endl;
			FileWriter(ROMBlockSize, i + 1);
		}
		delete[] timeWrite;
		delete[] timeRead;
		delete[] timeCountWrite;
		delete[] timeCountRead;
	}
	else if (memory_type == "flash"){
		number_of_tests = 20;
		int flashBlockSize = 0;
		int blockStep = 4 * 1024 * 1024; //4 Mb
		timeWrite = new double[number_of_tests];
		timeRead = new double[number_of_tests];
		timeCountWrite = new double[number_of_tests];
		timeCountRead = new double[number_of_tests];

		for (int i = 0; i < number_of_tests; i++){
			
			flashBlockSize += blockStep;
			FlashTestWrite(flashBlockSize / size_of_buffer, i);
			FlashTestRead(flashBlockSize / size_of_buffer, i);
			Accuracy(i);
			cout << i + 1 <<") Write = " << timeWrite[i] << " Read = " << timeRead[i] << endl;
			FileWriter(flashBlockSize, i + 1);
			
		}
		delete[] timeWrite;
		delete[] timeRead;
		delete[] timeCountWrite;
		delete[] timeCountRead;
	}
	else if (memory_type == "RAM"){
		number_of_tests = 4;
//		cash[3] = customBlockSize;
		timeWrite = new double[number_of_tests];
		timeRead = new double[number_of_tests];
		timeCountWrite = new double[number_of_tests];
		timeCountRead = new double[number_of_tests];

		for (int i = 0; i < number_of_tests; i++){
			RAMTestWrite(cash[i] / size_of_buffer, i);
			RAMTestRead(cash[i] / size_of_buffer, i);
			Accuracy(i);
			cout << i + 1 <<") Write = " << timeWrite[i] << " Read = " << timeRead[i] << endl;
			FileWriter(cash[i], i + 1);
		}
		delete[] timeWrite;
		delete[] timeRead;
		delete[] timeCountWrite;
		delete[] timeCountRead;
	}

	return 0;
}
