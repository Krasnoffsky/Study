#include <cmath>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <windows.h>

#define NANOSEC_TO_SEC 1000000000 
#define CASH_LINE 64  	 		//I found this shit in internet, this isn't the real size for my AMD A6 9225 
#define L1_CASH 163840   		//size of L1 in bytes
#define L2_CASH 1048576  		//size of L2 in bytes 
#define L3_CASH 3145728 		//size of L3 in bytes

using namespace std;

timespec* timeStart = new timespec;
timespec* timeEnd = new timespec;
long int* timeWrite;
long int* timeRead;

double secondTimeStart = 0;
double* timeCountWrite;
double* timeCountRead;

string memory_type;
int number_of_tests, customBlockSize;
double absErrorWrite;
double realErrorWrite;
double absErrorRead;
double realErrorRead;

struct info {
	string memType;
	int blockSize;
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
    	cout << "CUR = " << (double)((timeEnd->tv_nsec - timeStart->tv_nsec) + NANOSEC_TO_SEC * (timeEnd->tv_sec - timeStart->tv_sec)) / NANOSEC_TO_SEC << endl;
    	long int current = (timeEnd->tv_nsec - timeStart->tv_nsec) + NANOSEC_TO_SEC * (timeEnd->tv_sec - timeStart->tv_sec);
    	if (type == "READ"){
    		timeRead[number_try] = current;
		}
		else if (type == "WRITE"){
			timeWrite[number_try] = current;
			cout << "WRITE CUR = " << (double)timeWrite[number_try] / NANOSEC_TO_SEC << endl;
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
	int staticMas[size];
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
}

void RAMTestRead(int size, int number_try) // test for RAM in reading
{
	int staticMas[size];
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
}

void ROMTestWrite(int size, int number_try) //test for SSD or HDD in writing 
{
	int* mas = new int[size];
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
	int* mas = new int[size];
	
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
			average += (double)timeWrite[i] / NANOSEC_TO_SEC;
		}
		average /= size;
	}
	else if (type == "READ"){
		for (int i = 0; i < size; i++){
			average += (double)timeRead[i] / NANOSEC_TO_SEC;
		}
		average /= size;
	}
	
	return abs(average);
}

void Accuracy(int number_try)
{
	absErrorWrite = abs((double)timeWrite[number_try] / NANOSEC_TO_SEC - timeCountWrite[number_try]);
	absErrorRead = abs((double)timeRead[number_try] / NANOSEC_TO_SEC- timeCountRead[number_try]);
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
                    customBlockSize = atoi(temp.c_str()) * 1024 * 2;
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
	output->blockSize = block / (1024 * 1024);
	output->buffSize = 4;
	output->launchNum = num;
	output->writeTime = abs((double)timeWrite[num - 1] / NANOSEC_TO_SEC);
	output->readTime = abs((double)timeRead[num - 1] / NANOSEC_TO_SEC);
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
				<< output->blockSize <<" Mb" << ";"
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
	KeyReader(argc, argv);
	memory_type = "HDD";
	
	if (memory_type == "HDD" || memory_type == "SSD"){
		number_of_tests = 20;
		int ROMBlockSize = 0;
		int blockStep = 4 * 1024 * 1024; //4 Mb
		timeWrite = new long int[number_of_tests];
		timeRead = new long int [number_of_tests];
		timeCountWrite = new double[number_of_tests];
		timeCountRead = new double[number_of_tests];

		for (int i = 0; i < number_of_tests; i++){
			
			ROMBlockSize += blockStep;
			ROMTestWrite(ROMBlockSize / 4, i);
			ROMTestRead(ROMBlockSize / 4, i);
			Accuracy(i);
			cout << i + 1 <<") Write = " << (double)timeWrite[i] / NANOSEC_TO_SEC << " Read = " << (double)timeRead[i] / NANOSEC_TO_SEC << endl;
			FileWriter(ROMBlockSize, i + 1);
		}
		delete timeWrite;
		delete timeRead;
		delete timeCountWrite;
		delete timeCountRead;
	}
	else if (memory_type == "flash"){
		number_of_tests = 20;
		int flashBlockSize = 0;
		int blockStep = 4 * 1024 * 1024; //4 Mb
		timeWrite = new long int[number_of_tests];
		timeRead = new long int [number_of_tests];
		timeCountWrite = new double[number_of_tests];
		timeCountRead = new double[number_of_tests];

		for (int i = 0; i < number_of_tests; i++){
			
			flashBlockSize += blockStep;
			FlashTestWrite(flashBlockSize / 4, i);
			FlashTestRead(flashBlockSize / 4, i);
			Accuracy(i);
			FileWriter(flashBlockSize, i + 1);
			
		}
		delete timeWrite;
		delete timeRead;
		delete timeCountWrite;
		delete timeCountRead;
	}

	return 0;
}
