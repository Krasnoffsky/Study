#include <math.h>

class SimpleFrac
{
public:
    SimpleFrac();
    ~SimpleFrac();

    long long int a, b;

    SimpleFrac operator=(SimpleFrac t);
    SimpleFrac operator+(SimpleFrac t);
    SimpleFrac operator-(SimpleFrac t);
	SimpleFrac operator*(SimpleFrac t);
    SimpleFrac operator/(SimpleFrac t);
	
private:
	SimpleFrac Reduce(SimpleFrac t);
};

SimpleFrac::SimpleFrac()
{
    a = 0;
    b = 1;
}

SimpleFrac::~SimpleFrac()
{
	
}

SimpleFrac SimpleFrac::operator+(SimpleFrac t)
{
	SimpleFrac result;
    result.a = a * t.b + t.a * b;
    result.b = b * t.b;
    if (result.b < 0){
    	result.a *= -1;
		result.b *= -1;	
	}
    result = Reduce(result);
    if (result.a == 0)
        result.b = 1;
    return result;
}

SimpleFrac SimpleFrac::operator-(SimpleFrac t)
{
	SimpleFrac result;
    result.a = a * t.b - t.a *b;
    result.b = b * t.b;
    if (result.b < 0){
    	result.a *= -1;
		result.b *= -1;	
	}
    result = Reduce(result);
    if (result.a == 0)
        result.b = 1;
    return result;
}

SimpleFrac SimpleFrac::operator*(SimpleFrac t)
{
	SimpleFrac result;
    SimpleFrac temp1, temp2;
    temp1.a = a;
    temp1.b = t.b;
    temp2.a = t.a;
    temp2.b = b;
    temp1 = Reduce(temp1);
    temp2 = Reduce(temp2);
    result.a = temp1.a * temp2.a;
    result.b = temp1.b * temp2.b;
    if (result.b < 0){
    	result.a *= -1;
		result.b *= -1;	
	}
    result = Reduce(result);
    if (result.a == 0)
        result.b = 1;
    return result;
}

SimpleFrac SimpleFrac::operator/(SimpleFrac t)
{
	SimpleFrac result;
    SimpleFrac temp1, temp2;
    temp1.a = a;
    temp1.b = t.a;
    temp2.a = t.b;
    temp2.b = b;
    temp1 = Reduce(temp1);
    temp2 = Reduce(temp2);
    result.a = temp1.a * temp2.a;
    result.b = temp1.b * temp2.b;
    if (result.b < 0){
    	result.a *= -1;
		result.b *= -1;	
	}
    result = Reduce(result);
    if (result.a == 0)
        result.b = 1;
    return result;
}

SimpleFrac SimpleFrac::operator=(SimpleFrac t)
{
	a = t.a;
	b = t.b;
	return *this;
}

SimpleFrac SimpleFrac::Reduce(SimpleFrac t)
{
    long long int j, less;
	do{
  	  if (abs(t.a) < abs(t.b))                                    
 	       less = abs(t.a);                               
    	else                                                  
     	   less = abs(t.b);                                
    	for(j = less; j > 0; j--){                    
        	if(!(t.a % j) && !(t.b % j)){     
            	t.a /= j;                     
            	t.b /= j;                      
            	break;                        
        	}
    	}
//    	printf("%d\n", j);
	} while (j > 1);
	
	return t; 
}
