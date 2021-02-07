#include <iostream>
#include "simplefrac.h"

using namespace std;

void PrintMatrix(SimpleFrac **mtrx, int N, int M)
{
    cout << endl << "Your matrix:" << endl;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M + 1; j++){
            if (mtrx[i][j].b == 1)
                cout << mtrx[i][j].a << "  ";
            else if (mtrx[i][j].a == 0)
                cout << "0  ";
            else
                cout << mtrx[i][j].a << "/" << mtrx[i][j].b << "  ";
        }
        cout << endl;
    }
}

void MatrixEquate(SimpleFrac **mtrx, SimpleFrac **resMtrx , int N, int M)
{
	for (int i = 0; i < N; i++){
		for (int  j = 0; j < M + 1; j++){
			resMtrx[i][j].a = mtrx[i][j].a;
			resMtrx[i][j].b = mtrx[i][j].b;
		}
	}
}

void EMatrix(SimpleFrac **mtrx, SimpleFrac **resMtrx , int N, int M)
{
	int k_m = 0;
	
	SimpleFrac temp_1, temp_2, temp_div;
		
//	MatrixEquate(mtrx, resMtrx , N, M);
	

	cout << "Start with M = " << M << endl;
	
	for (k_m = 0; k_m < M; k_m++){
	cout << "Col " << k_m << endl;
		for (int i = k_m + 1; i < N; i++){
			for (int j = k_m + 1; j < M + 1; j++){
				cout << "Counting [" << i << " , " << j << "]" << endl; 
				temp_1.FracMulti(mtrx[k_m][k_m], mtrx[i][j]);
				temp_2.FracMulti(mtrx[i][k_m], mtrx[k_m][j]);
				resMtrx[i][j].FracMinus(temp_1, temp_2);
			}
		}
		cout << "Complete counting" << endl;
		
		temp_div.a = resMtrx[k_m + 1][k_m + 1].a;
		temp_div.b = resMtrx[k_m + 1][k_m + 1].b;
		
		cout << "Start Div" << endl;
		
		for (int i = k_m + 1; i < N; i++){
			for (int j = k_m + 1; j < M + 1; j++){
				resMtrx[i][j].FracDiv(resMtrx[i][j], temp_div);
			}
		}
		
		cout << "Complete Div" << endl;
		MatrixEquate(resMtrx, mtrx, N, M);
		cout << "Complete equation" << endl;
		PrintMatrix(mtrx, N, M);
	}	
}

int main()
{
    SimpleFrac **matrix;
    SimpleFrac **resMtrx;
    int M, N;

    cout << "Number of varibles: ";
    cin >> M;
    cout << "Number of equations: ";
    cin >> N;

    matrix = new SimpleFrac* [N];
    resMtrx = new SimpleFrac* [N];

    for (int i = 0; i < N; i++){
        matrix[i] = new SimpleFrac [M + 1];
        resMtrx[i] = new SimpleFrac [M + 1];
    }

    cout << "Input your matrix" << endl;

    for (int i = 0; i < N; i++){
        cout << i + 1 << " equation:" << endl; 
        for (int j = 0; j < M + 1; j++){
            cin >> matrix[i][j].a;
        }
    }
    
    PrintMatrix(matrix, N, M);
    
    EMatrix(matrix, resMtrx, N, M);
    
    PrintMatrix(resMtrx, N, M);
    

    return 0;
}
