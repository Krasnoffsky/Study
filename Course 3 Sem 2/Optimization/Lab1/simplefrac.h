#include <math.h>

class SimpleFrac
{
public:
    SimpleFrac();
    ~SimpleFrac();

    long int a, b;

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
    return result;
}

SimpleFrac SimpleFrac::operator*(SimpleFrac t)
{
	SimpleFrac result;
    result.a = a * t.a;
    result.b = b * t.b;
    if (result.b < 0){
    	result.a *= -1;
		result.b *= -1;	
	}
    result = Reduce(result);
    return result;
}

SimpleFrac SimpleFrac::operator/(SimpleFrac t)
{
	SimpleFrac result;
    result.a = a * t.b;
    result.b = b * t.a;
    if (result.b < 0){
    	result.a *= -1;
		result.b *= -1;	
	}
    result = Reduce(result);
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
	int j, less;                                  
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
