#include <iomanip>
#include <iostream>
#include <cmath>


using namespace std;

double** mtrx;

void MatrixRotation (double fi){
	
	mtrx[0][0] = cos(fi);
	mtrx[0][1] = -1 * sin(fi);
	mtrx[1][0] = sin(fi);
	mtrx[1][1] = cos(fi);
	mtrx[2][2] = 1;
	
}

int main (void){

	double fi;
	
	mtrx = new double* [3];
	
	for (int i = 0; i < 3; i++){
		mtrx[i] = new double [3];
		mtrx[i] = 0;
	}

	cout << "Input Fi: ";
	cin >> fi;
	
	MatrixRotation(fi);
	
	cout << "_Result_" << endl;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << setprecision(3) << mtrx[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
