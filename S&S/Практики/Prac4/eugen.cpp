#include <iostream>
#include <cmath>

using namespace std;

void MatrixRotation (double fi, double x, double y, double z, double* x_res, double* y_res, double *z_res){
	
	*x_res = (x * cos(fi) - y * sin(fi) + z * 0);
	*y_res = (y * cos(fi) + x * sin(fi) + z * 0);
	*z_res = (z * 1 + x * 0 + y * 0);
	
}

int main (void){

	double x, y, z, fi;
	
	double* x_res = new double;
	double* y_res = new double;
	double* z_res = new double;
	
	cout << "Input x: ";
	cin >> x;
	cout << "Input y: ";
	cin >> y;
	cout << "Input z: ";
	cin >> z;
	cout << "Input Fi: ";
	cin >> fi;
	
	MatrixRotation(fi, x, y, z, x_res, y_res, z_res);
	
	cout << "_Result_" << endl;
	cout << "Vector = { " << *x_res << " ; " << *y_res << " ; " << *z_res << " }" << endl;
	
	return 0;
}
