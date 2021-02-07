#include <iostream>

using namespace std;

void PrintMatrix(double **mtrx, int N, int M)
{
    cout << "Your matrix:" << endl;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M + 1; j++){
                cout << mtrx[i][j] << "  ";
        }
        cout << endl;
    }
}

void MatrixEquate(double **mtrx, double **resMtrx , int N, int M)
{
	for (int i = 0; i < N; i++){
		for (int  j = 0; j < M + 1; j++){
			resMtrx[i][j] = mtrx[i][j];
		}
	}
}

void EMatrix(double **mtrx, double **resMtrx , int N, int M)
{
	int k_m = 0;
	
	MatrixEquate(mtrx, resMtrx, N, M);
	
	double temp_1, temp_2, temp_div;
		
//	MatrixEquate(mtrx, resMtrx , N, M);
	

	
	for (k_m = 0; k_m < N; k_m++){
		
		cout << "Col " << k_m << endl;
		
		cout << endl << "Phase 1: div" << endl;
		
		if (k_m != M - 1){
			temp_div = resMtrx[k_m][k_m];
			for (int j = k_m; j < M + 1; j++){
				resMtrx[k_m][j] /= temp_div;
			}
		}
		
		PrintMatrix(resMtrx, N, M);
	
		cout << endl << "Phase 2: counting" << endl;
		
	
		for(int i = 0; i < N; i++){ //считаем элементы
			for (int j = k_m + 1; j < M + 1; j++){
				if (i != k_m && j != k_m){
					temp_1 = mtrx[k_m][k_m] * mtrx[i][j];
					temp_2 = mtrx [i][k_m] * mtrx[k_m][j];
					resMtrx[i][j] = temp_1 - temp_2;
				}
			}
		}
		PrintMatrix(resMtrx, N, M);	
		
		cout << endl << "Phase 3: Null" << endl;
		
		
		for (int i = 0; i < N; i++){ // обнуляем
			if (i != k_m){
				resMtrx[i][k_m] = 0;
			}
		}
		PrintMatrix(resMtrx, N, M);
		
		cout << endl << "Resalt" << endl;
		
		MatrixEquate(resMtrx, mtrx, N, M);
		PrintMatrix(resMtrx, N, M);
	}	
}

int main()
{
    double **matrix;
    double **resMtrx;
    int M, N;

    cout << "Number of varibles: ";
    cin >> M;
    cout << "Number of equations: ";
    cin >> N;

    matrix = new double* [N];
    resMtrx = new double* [N];

    for (int i = 0; i < N; i++){
        matrix[i] = new double [M + 1];
        resMtrx[i] = new double [M + 1];
    }

    cout << "Input your matrix" << endl;

    for (int i = 0; i < N; i++){
        cout << i + 1 << " equation:" << endl; 
        for (int j = 0; j < M + 1; j++){
            cin >> matrix[i][j];
        }
    }
    
    PrintMatrix(matrix, N, M);
    
    EMatrix(matrix, resMtrx, N, M);
    
//    PrintMatrix(resMtrx, N, M);
	if (N == M){
		for (int i = 0; i < N; i++){
			cout << "x" << i + 1 << " = " << resMtrx[i][M] << endl;
		}	
	}
	else {
		for (int i = 0; i < N; i++){
			cout << "x" << i + 1<< " = " << resMtrx[i][M] << " ";
			for (int j = i + 1; j < M; j++){
				if (resMtrx[i][j] != 0){
					
					cout << " + " << resMtrx[i][j] * (-1)<< " * x" << i + 1<< " ";
				}
			}
			cout << endl;
		}
	}
	
    return 0;
}
