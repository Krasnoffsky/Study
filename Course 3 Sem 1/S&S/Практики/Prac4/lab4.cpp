#include <iostream>
#include <cmath>

using namespace std;

void MatrixRotation (double fi, double x, double y, double* x_res, double* y_res){
	
	*x_res = (x * cos(fi) + y * sin(fi));
	*y_res = (y * cos(fi) - x * sin(fi));
	
}

int main (void){

	double x, y, fi;
	
	double* x_res = new double;
	double* y_res = new double;
	
	cout << "Input x: ";
	cin >> x;
	cout << "Input y: ";
	cin >> y;
	cout << "Input Fi: ";
	cin >> fi;
	
	MatrixRotation(fi, x, y, x_res, y_res);
	
	cout << "_Result_" << endl;
	cout << "Vector = { " << *x_res << " ; " << *y_res << " }" << endl;
	
	return 0;
}
