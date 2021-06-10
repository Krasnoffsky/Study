#include <iostream>
#include <string>
#include "simplefrac.h"

using namespace std;

int N, M;

void DeleteLine(SimpleFrac **mtrx, int line)
{
    SimpleFrac temp;
    if (line == N - 1){
        N--;
    }
    else {
        for (int i = line + 1; i < N; i++){
            temp = *mtrx[i];
            mtrx[i] = mtrx[i - 1];
            *mtrx[i - 1] = temp;
        }
        M--;
    }
}

bool CheckZero(SimpleFrac **mtrx)
{
    bool flag_zero;

    for (int i = 0; i < N; i++){

        flag_zero = true;

        for (int j = 0; j < M; j++){
            if (mtrx[i][j].a != 0)
                flag_zero = false;

        }

        if (!flag_zero)
            continue;

        else if (flag_zero && mtrx[i][M].a != 0)
            return false;

        else if (flag_zero && mtrx[i][M].a == 0){

            DeleteLine(mtrx, i);
            cout << "d_1" << endl;
        }

        else {
            cout << "CRITICAL ERROR: INVALID SITUATION" << endl;
            return false;
        }
    }
    return true;
}

void PrintMatrix(SimpleFrac **mtrx)
{
    cout << "Your matrix:" << endl;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M + 1; j++){
                cout << mtrx[i][j].a << "/" << mtrx[i][j].b << "  ";
        }
        cout << endl;
    }
}

int EMatrix(SimpleFrac **resMtrx)
{
    int k_m = 0;
    int k_n = 0;
    int k = 0;

    SimpleFrac temp_1, temp_2, temp_div;

    SimpleFrac *temp_swap;
    temp_swap = new SimpleFrac;

    for (k_m = 0; k_m < N; k_m++){

        cout << "Phase 0: prepare" << endl;

        CheckZero(resMtrx);
        k_n = 0;
        k = 0;
        while (resMtrx[k_m + k_n][k_m + k].a == 0){
            k_n++;
            if (k_m + k_n == N) {
                k++;
                if (k_n + k == M) {
                    k = 0;
                    break;
                }
                else
                k_n = 0;
            }
        }

        if (k_n != 0 && k_m + k_n < N) {
            temp_swap = resMtrx[k_m];
            resMtrx[k_m] = resMtrx[k_m + k_n];
            resMtrx[k_m + k_n] = temp_swap;
        }


        cout << "Col " << k_m + 1 << endl;

        cout << endl << "Phase 1: div" << endl;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M + 1; j++){
                if (resMtrx[i][j].a == 0){
                    resMtrx[i][j].b = 1;
                }
            }
        }

        temp_div = resMtrx[k_m][k_m + k];
        for (int j = k_m + k; j < M + 1; j++){
            resMtrx[k_m][j] = resMtrx[k_m][j] / temp_div;
        }

        PrintMatrix(resMtrx);

        cout << endl << "Phase 2: counting" << endl;


        for(int i = 0; i < N; i++){
            for (int j = k_m + k + 1; j < M + 1; j++){
                if (i != k_m && j != k_m){
                    temp_1 = resMtrx[k_m][k_m + k] * resMtrx[i][j];
                    temp_2 = resMtrx[i][k_m + k] * resMtrx[k_m][j];
                    resMtrx[i][j] = temp_1 - temp_2;
                }
            }
        }
        PrintMatrix(resMtrx);

        cout << endl << "Phase 3: Null" << endl;


        for (int i = 0; i < N; i++){
            if (i != k_m){
                resMtrx[i][k_m + k].a = 0;
            }
        }
        PrintMatrix(resMtrx);

        cout << endl << "Phase 4: Check Null" << endl;

        if (!CheckZero(resMtrx)){
            return 1;
        }
        PrintMatrix(resMtrx);

        cout << endl;
    }

    return 0;
}

int main()
{
    SimpleFrac **matrix;

    cout << "Number of varibles: ";
    cin >> M;
    cout << "Number of equations: ";
    cin >> N;

    matrix = new SimpleFrac* [N];

    for (int i = 0; i < N; i++){
        matrix[i] = new SimpleFrac [M + 1];
    }

    cout << "Input your matrix" << endl;

    for (int i = 0; i < N; i++){
        cout << i + 1 << " equation:" << endl;
        for (int j = 0; j < M + 1; j++){
            cin >> matrix[i][j].a;
        }
    }

    PrintMatrix(matrix);
 int k = 0;
    if (!EMatrix(matrix)){
        cout << endl << "Result:" << endl;

        if (N == M){
            for (int i = 0; i < N; i++){
                cout << "x" << i + 1 << " = " << matrix[i][M].a;
                if (matrix[i][M].b != 1)
                    cout << "/" << matrix[i][M].b << endl;
                else
                    cout << endl;
            }
        }
        else {
            for (int i = 0; i < N; i++){
                k = 0;
                while (matrix[i][i + k].a == 0){
                    k++;
                    if (i + k == M + 1){
                        cout << "UNEXPECTED ERROR" << endl;
                        return 0;
                    }
                }
                cout << "x" << i + 1 << " = " << matrix[i][M].a << "/" << matrix[i][M].b << " ";
                for (int j =  i + k + 1; j < M; j++){
                    if (matrix[i][j].a != 0){
                        cout << " + " << matrix[i][j].a * (-1);
                        if (matrix[i][j].b != 1)
                            cout << "/" <<matrix[i][j].b;
                        cout << " * x" << j + 1 << " ";
                    }
                }
                cout << endl;
            }
        }
    }

    else
        cout << "NO RESULTS" << endl;

    return 0;
}

/*
5
5

5
16
12
11
-7
62
17
12
1
18
9
298
15
-15
3
1
-7
-127
-14
-13
-7
-5
-11
-190
-1
13
-16
-6
8
152
*/

/*
 4
 4

 1
 0
 2
 3
 4
 0
 0
 0
 1
 3
 0
 1
 0
 0
 5
 0
 0
 1
 0
 6
 */