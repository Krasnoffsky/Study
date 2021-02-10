#include <iostream>

using namespace std;

int N, M;

void PrintMatrix(double **mtrx)
{
    cout << "Your matrix:" << endl;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M + 1; j++){
                cout << mtrx[i][j] << "  ";
        }
        cout << endl;
    }
}

void EMatrix(double **resMtrx)
{
	int k_m = 0;
	
	double temp_1, temp_2, temp_div;
	
	for (k_m = 0; k_m < N; k_m++){
		
		cout << "Col " << k_m << endl;
		
		cout << endl << "Phase 1: div" << endl;
		
		temp_div = resMtrx[k_m][k_m];
		for (int j = k_m; j < M + 1; j++){
			resMtrx[k_m][j] /= temp_div;
		}
		
		PrintMatrix(resMtrx);
		
	
		cout << endl << "Phase 2: counting" << endl;
		
	
		for(int i = 0; i < N; i++){ //считаем элементы
			for (int j = k_m + 1; j < M + 1; j++){
				if (i != k_m && j != k_m){
					temp_1 = resMtrx[k_m][k_m] * resMtrx[i][j];
					temp_2 = resMtrx[i][k_m] * resMtrx[k_m][j];
					resMtrx[i][j] = temp_1 - temp_2;
					cout << "Count [" << i << "," << j <<"] = " << resMtrx[k_m][k_m] << " * " << resMtrx[i][j] << " - " << resMtrx[i][k_m] << " * " << resMtrx[k_m][j];
					cout << " = " << temp_1 << " - " << temp_2 << " = " << resMtrx[i][j] << endl;
				}
			}
		}
		PrintMatrix(resMtrx);	
		
		cout << endl << "Phase 3: Null" << endl;
		
		
		for (int i = 0; i < N; i++){ // обнуляем
			if (i != k_m){
				resMtrx[i][k_m] = 0;
			}
		}
		PrintMatrix(resMtrx);
		
	}	
}

int main()
{
    double **matrix;

    cout << "Number of varibles: ";
    cin >> M;
    cout << "Number of equations: ";
    cin >> N;

    matrix = new double* [N];

    for (int i = 0; i < N; i++){
        matrix[i] = new double [M + 1];
    }

    cout << "Input your matrix" << endl;

    for (int i = 0; i < N; i++){
        cout << i + 1 << " equation:" << endl; 
        for (int j = 0; j < M + 1; j++){
            cin >> matrix[i][j];
        }
    }
    
    PrintMatrix(matrix);
    
    EMatrix(matrix);
    
    cout << endl << "Result:" << endl;
    
	if (N == M){
		for (int i = 0; i < N; i++){
			cout << "x" << i + 1 << " = " << matrix[i][M] << endl;
		}	
	}
	else {
		for (int i = 0; i < N; i++){
			cout << "x" << i + 1<< " = " << matrix[i][M] << " ";
			for (int j = i + 1; j < M; j++){
				if (matrix[i][j] != 0){
					
					cout << " + " << matrix[i][j] * (-1)<< " * x" << i + 1<< " ";
				}
			}
			cout << endl;
		}
	}
	
    return 0;
}
