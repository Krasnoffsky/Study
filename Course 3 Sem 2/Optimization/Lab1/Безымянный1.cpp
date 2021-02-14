#include <iostream>
#include <time.h>
#include <cstdlib>
#include "simplefrac.h"

using namespace std;

int N = 3, M = 3;


int main(void)
{
	SimpleFrac frac0, frac1, frac2;
	frac1.a = 7;
	frac1.b = 6;
	frac2.a = 8;
	frac2.b = 4;
	
	frac0 = frac2 + frac1;
	
	cout << frac0.a << "/" << frac0.b << endl;
	
	return 0;
}
