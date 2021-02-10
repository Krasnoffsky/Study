#include <iostream>

using namespace std;

void Checker(int** mtrx, int M, int N)
{
	int temp_k;
	int counter;
	int temp_j = -1;
	for (int k = 0; k < M - 1; k++){
		for (int i = k + 1; i < M; i++){
			while ((mtrx[k][temp_j + 1] == 0 || mtrx[i][temp_j + 1] == 0) && temp_j + 1 != M - 1)
				temp_j++;
			cout << temp_j << endl;
			if (temp_j == -1){
				cout << "ERROR" << endl;
				break;
			}
			temp_k = mtrx[k][temp_j] / mtrx[i][temp_j];
			counter = 0;
			
			for (int j = 0; j < N; j++){
				if (mtrx[k][j] == mtrx[i][j] * temp_k)
					counter++;
			}
			if (counter == N){
				cout << "SAME: " << k << " and " << i;
			}
			temp_j = -1;
		}	
	}
	
} 

int main(void)
{
	int N = 3, M = 3;
	int** a = new int*[M];
	for(int i = 0; i < M; i++){
		a[i] = new int[N];
		for (int j = 0; j < N; j++){
			a[i][j] = i * j + j; 
			cout << a[i][j] << " ";	
		}
		cout << endl;
	}
	
	cout << endl << "DELETING" << endl << endl;
	int *b = new int[N];
	b = a[2];
	a[1] = b;

	Checker(a, M, N);
	
	return 0;
}
