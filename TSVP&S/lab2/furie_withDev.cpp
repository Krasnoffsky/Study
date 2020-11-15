#include <cmath>
#include <complex>
#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.14159;
const complex <double> i = (0, 1);

void FurieDiscrete(double* k, complex <double>* a, int N)
{
    for (int j = 0; j < N; j++){
        for (int g = 0; g < N; g++){
            a[j] += exp(-2 * PI * i * (double)j * (double)g / (double)N) * k[g];
        }
        a[j] *= (double)1 / (double)N;
        cout << "aMas[" << j << "] = " << a[j] << endl;
    }
}

int main(void)
{
    int size;

//    cout << "Input size of massiv: ";
//    cin >> size;
	size = 5;

    double* kMas = new double[size];
    complex <double>* aMas = new complex <double>[size];

/*    cout << "Input kMas: ";
    for (int i = 0; i < size; i++){
        cin >> kMas[i];
    }
*/
	kMas[0] = 1;
	kMas[1] = 0;    
	kMas[2] = 1;    
	kMas[3] = 0;    
	kMas[4] = 1;    
    
    for (int i = 0; i < size; i++){
        aMas[i] = 0;
    }

    FurieDiscrete(kMas, aMas, size);

    return 0;
}

