#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <pthread.h>

using namespace std;

double timeStart;
double timeCounter;

void BenchTimer(string task)
{
    if (task == "START"){
        timeStart = clock();
    } else if(task == "STOP"){
        timeCounter = ((double)(clock() - timeStart)) / CLOCKS_PER_SEC;
    }

}

void FillMatrix(double** aMatrix, double** bMatrix, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            aMatrix[i][j] = rand()%100;
            bMatrix[i][j] = rand()%100;
        }
    }
}

void PrintMatrix(double** matrix, int size)
{
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

double MultipicMatrix(double** aMatrix, double** bMatrix, int size, int x_pos, int y_pos)
{
    double res = 0;
    int i = 0, j = 0;
    while (i < size){
        res += aMatrix[x_pos][i] * bMatrix[j][y_pos];
        i++;
        j++;
    }
    return res;
}

void DGEMM_BLAS(double** aMatrix, double** bMatrix, double** resMatrix, int size, int thread_start_x, int thread_start_y, int thread_stop)
{
    int n = 0;
    for (int i = thread_start_x; i < size; i++){
        for (int j = thread_start_y; j < size; j++){
            n++;
            if (n >= thread_stop)
                break;
            resMatrix[i][j] = MultipicMatrix(aMatrix, bMatrix, size, i, j);
        }
    }
}

int main(void)
{
    int num_of_threads, matrix_size;
    int thread_len_prev = 0;

    cout << "Input Size of Matrix: ";
    cin >> matrix_size;
    cout << "Input Number of Threads: ";
    cin >> num_of_threads;

    int* thread_len = new int [num_of_threads];
    double** aMatrix = new double* [matrix_size];
    double** bMatrix = new double* [matrix_size];
    double** resMatrix = new double* [matrix_size];
    for (int i = 0; i < matrix_size; i++){
        aMatrix[i] = new double[matrix_size];
        bMatrix[i] = new double[matrix_size];
        resMatrix[i] = new double[matrix_size];
    }

    FillMatrix(aMatrix, bMatrix, matrix_size);

    pthread_t* threads = new pthread_t[num_of_threads];

    for (int i = 0; i < num_of_threads; i++){
        thread_len[i] = thread_len_prev + (int)(matrix_size * matrix_size / num_of_threads);
        thread_len_prev += (int)(matrix_size * matrix_size / num_of_threads);
    }
    int k = 0;
    if (thread_len_prev < matrix_size * matrix_size){
        do {
            for (int i = k; i < num_of_threads; i++)
                thread_len[i]++;
            thread_len_prev++;
            k++;
        } while (thread_len_prev < matrix_size);
    }

    for (int i = 0; i < num_of_threads; i++)
        cout << thread_len[i] << endl;
    cout << "Sum = " << thread_len_prev;

    delete aMatrix;
    delete bMatrix;
    delete resMatrix;

    return 0;
}

