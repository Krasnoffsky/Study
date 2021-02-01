#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <pthread.h>
#include <omp.h>

using namespace std;

double timeStart;
double timeCounter;

double** aMatrix;
double** bMatrix;
double** resMatrix;

void BenchTimer(string task)
{
    if (task == "START"){
        timeStart = clock();
    } else if(task == "STOP"){
        timeCounter = ((double)(clock() - timeStart)) / CLOCKS_PER_SEC;
    }

}

void FillMatrix(int size)
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

double MultipicMatrix(int size, int x_pos, int y_pos)
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

void* DGEMM_BLAS_pt(void* args)
{
    int start = atoi(((char**)args)[0]);
    int end = atoi(((char**)args)[1]);
    int size = atoi(((char**)args)[2]);
    for (int i = start; i < end; i++){
        for (int j = 0; j < size; j++){
            resMatrix[i][j] = MultipicMatrix(size, i, j);
        }
    }

    pthread_exit(0);
}

void DGEMM_BLAS_omp(int start, int end, int size) {
    for(int i = start; i < end; i++) {
        for(int j = 0; j < size; j++){
            resMatrix[i][j] = MultipicMatrix(size, i, j);
        }
    }
}

int main(int argc, char** argv)
{
    if (argc < 2){
        cout << "ERROR: Incorrrect number of elements"<< endl;
        cout << "Elements: Matrix Size, Number of Threads"<<endl;
//        return 0;
    }
    int num_of_threads, matrix_size;

    matrix_size = atoi(argv[1]);
    num_of_threads = atoi(argv[2]);
    if (num_of_threads > matrix_size)
        num_of_threads = matrix_size;

    aMatrix = new double* [matrix_size];
    bMatrix = new double* [matrix_size];
    resMatrix = new double* [matrix_size];
    for (int i = 0; i < matrix_size; i++){
        aMatrix[i] = new double[matrix_size];
        bMatrix[i] = new double[matrix_size];
        resMatrix[i] = new double[matrix_size];
    }

    char** args = new char* [3];
    for (int i = 0; i < 3; i++)
        args[i] = new char[10];

    int step =(int)(matrix_size / num_of_threads);
    int start_i = 0;
    int stop_i = step;


    FillMatrix(matrix_size);

    pthread_t* threads = new pthread_t[num_of_threads];
    snprintf(args[2], 10, "%d", matrix_size);

    BenchTimer("START");

    for (int i = 0; i < num_of_threads - 1; i++){
        snprintf(args[0], 10, "%d", start_i);
        snprintf(args[1], 10, "%d", stop_i);
        pthread_create(&threads[i], NULL, DGEMM_BLAS_pt, args);
        start_i = stop_i;
        stop_i += step;
    }

    snprintf(args[0], 10, "%d", start_i);
    snprintf(args[1], 10, "%d", matrix_size);
    pthread_create(&threads[num_of_threads - 1], NULL, DGEMM_BLAS_pt, args);

    for (int i = 0; i < num_of_threads; i++){
        pthread_join(threads[i], NULL);
    }

    BenchTimer("STOP");
    cout << "POSIX Threads Time: " << timeCounter;

    BenchTimer("Start");

    #pragma omp parallel
        {
            #pragma omp for
            for(int i = 0; i < num_of_threads; i++) {
                if (i == num_of_threads - 1) DGEMM_BLAS_omp(step * (num_of_threads - 1), matrix_size, matrix_size);
                else DGEMM_BLAS_omp(i * step, (i + 1) * step, matrix_size);
            }
        }

    BenchTimer("STOP");

    cout << "OpenMP Time: " << timeCounter;

    delete aMatrix;
    delete bMatrix;
    delete resMatrix;

    return 0;
}

