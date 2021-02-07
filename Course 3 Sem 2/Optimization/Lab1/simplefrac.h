#include <math.h>

class SimpleFrac
{
    public:
        SimpleFrac();
        ~SimpleFrac();

        int a, b;

        void FracPlus(SimpleFrac t1, SimpleFrac t2);
        void FracMinus(SimpleFrac t1, SimpleFrac t2);
        void FracMulti(SimpleFrac t1, SimpleFrac t2);
        void FracDiv(SimpleFrac t1, SimpleFrac t2);
};

SimpleFrac::SimpleFrac()
{
    a = 0;
    b = 1;
}

SimpleFrac::~SimpleFrac()
{

}

void SimpleFrac::FracPlus(SimpleFrac t1, SimpleFrac t2)
{
    if (t1.b != t2.b){
        a = t1.a * t2.b + t2.a * t1.b;
        b = t1.b * t2.b;
    }
    else {
        a = t1.a + t2.a;
        b = t1.b;
    }
    
    if ((a < 0 && b < 0) || (a >= 0 && b < 0)) {
    	a *= -1;
    	b *= -1;
	}
}

void SimpleFrac::FracMinus(SimpleFrac t1, SimpleFrac t2)
{
    if (t1.b != t2.b){
        a = t1.a * t2.b - t2.a * t1.b;
        b = t1.b * t2.b;
    }
    else {
        a = t1.a - t2.a;
        b = t1.b;
    }
    
    if ((a < 0 && b < 0) || (a >= 0 && b < 0)) {
    	a *= -1;
    	b *= -1;
	}
}

void SimpleFrac::FracMulti(SimpleFrac t1, SimpleFrac t2)
{
    a = t1.a * t2.a;
    b = t1.b * t2.b;
    
    if ((a < 0 && b < 0) || (a >= 0 && b < 0)) {
    	a *= -1;
    	b *= -1;
	}
}

void SimpleFrac::FracDiv(SimpleFrac t1, SimpleFrac t2)
{
    a = t1.a * t2.b;
    b = t1.b * t2.a;
    
    if ((a < 0 && b < 0) || (a >= 0 && b < 0)) {
    	a *= -1;
    	b *= -1;
	}
	
	if (a % b == 0){
		a = a / b;
		b = 1;
	}
	else if (b % a == 0){
		b = b / a;
		a = 1;
	}
}

