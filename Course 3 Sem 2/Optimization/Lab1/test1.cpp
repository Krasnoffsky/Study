#include <iostream>
#include <string>
#include "simplefrac.h"

using namespace std;

int N, M;

void DeleteLine(SimpleFrac **mtrx, int line)
{
	SimpleFrac *temp = new SimpleFrac[M];
	if (line == N - 1){
		N--;
	}
	else {
		for (int i = line + 1; i < N; i++){
			temp = mtrx[i];
			mtrx[i] = mtrx[i - 1];
			mtrx[i - 1] = temp;
		}
		M--;	
	}
	delete(temp);
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
				
		else if (flag_zero && mtrx[i][M].a == 0)
			DeleteLine(mtrx, i);
			
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
	
	SimpleFrac temp_1, temp_2, temp_div;
	
	for (k_m = 0; k_m < N; k_m++){
		
		cout << "Col " << k_m << endl;
		
		cout << endl << "Phase 1: div" << endl;
		
		temp_div = resMtrx[k_m][k_m];
		for (int j = k_m; j < M + 1; j++){
			resMtrx[k_m][j] = resMtrx[k_m][j] / temp_div;
		}
		
		PrintMatrix(resMtrx);
		
		cout << endl << "Phase 2: counting" << endl;
		
	
		for(int i = 0; i < N; i++){ //считаем элементы
			for (int j = k_m + 1; j < M + 1; j++){
				if (i != k_m && j != k_m){
					temp_1 = resMtrx[k_m][k_m] * resMtrx[i][j];
					temp_2 = resMtrx[i][k_m] * resMtrx[k_m][j];
					resMtrx[i][j] = temp_1 - temp_2;
				}
			}
		}
		PrintMatrix(resMtrx);	
		
		cout << endl << "Phase 3: Null" << endl;
		
		
		for (int i = 0; i < N; i++){ // обнуляем
			if (i != k_m){
				resMtrx[i][k_m].a = 0;
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
    
    if (!EMatrix(matrix)){
    	cout << endl << "Result:" << endl;
    
		if (N == M){
			for (int i = 0; i < N; i++){
				cout << "x" << i + 1 << " = " << matrix[i][M].a << "/" << matrix[i][M].b << endl;
			}	
		}
		else {
			for (int i = 0; i < N; i++){
				cout << "x" << i + 1 << " = " << matrix[i][M].a << "/" << matrix[i][M].b << " ";
				for (int j = i + 1; j < M; j++){
					if (matrix[i][j].a != 0){
						cout << " + " << matrix[i][j].a * (-1) << "/" << matrix[i][j].b << " * x" << i + 1 << " ";
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
