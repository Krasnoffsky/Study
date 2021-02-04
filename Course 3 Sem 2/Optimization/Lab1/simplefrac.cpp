#include "simplefrac.h"

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
    }
}

void SimpleFrac::FracMulti(SimpleFrac t1, SimpleFrac t2)
{
    a = t1.a * t2.a;
    b = t1.b * t2.b;
}

void SimpleFrac::FracDiv(SimpleFrac t1, SimpleFrac t2)
{
    a = t1.a * t2.b;
    b = t1.b * t2.a;
}