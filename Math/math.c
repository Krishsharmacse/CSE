#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cf.h"

/******************************************************************************************************** */

long double myNaN() { return 0.0L / 0.0L; }
long double minusInf() { return -1.0L / 0.0L; }
long double plusInf() { return 1.0L / 0.0L; }

/******************************************************************************************************** */


void Swap(void *x, void *y, unsigned size){
void *temp = malloc(size);
    if(!temp){
        fprintf(stderr, "Swap failed. Abort !!! \n");
        exit( EXIT_FAILURE );
    }

    memcpy(temp,x,size);
    memcpy(x,y,size);
    memcpy(y,temp,size);

    free(temp);
}

/******************************************************************************************************** */
/*                                               Power and Sqrt                                           */
/******************************************************************************************************** */

long double Sqrt(long double x){ //uses Heron's algorithm
    if(x == plusInf()) return x;
    if(x == minusInf()) return myNaN();
    if(!(x == x)) return x; //NaN
    if(x < 0.0L) return myNaN();
    if(x == 0.0L) return 0.0L;
    if(x == 1.0L) return 1.0L;
    if((x + TOL) < 1.0L) return 1.0L;

    long double Sqrt, temp;
    Sqrt = x / 2.0L;
    temp = 0.0L;
    int i = 0;
    while (ABS(Sqrt - temp) > TOL && i<MAXITERATION){
        temp = Sqrt;
        Sqrt = (x / temp + temp) / 2.0L;
        i++;
    }
    return Sqrt;
}

/******************************************************************************************************** */

long double iPower(long double x, long long n){ //The exponent is an integer. x^n
    // __mingw_printf("%lf, %lld\n", x, n);
    if(!(x == x)) return x; //NaN
    if(!(n == n)) return n; //NaN
    if(n == 0) return 1.0L;
    if(x == 0.0L) return (n > 0) ? 0.0L : plusInf();  

    if(x == plusInf()) return (n < 0) ? 0.0L : x;
    if(x == minusInf()){
        if(n % 2){
           return (n < 0) ? -0.0L : minusInf();
        }
        return (n < 0) ? 0.0L : plusInf();
    } 

    if(n < 0){
        x = 1/x;
        n = -n;
    }


    long double pow = 1.0L;
    while(n > 0){
        if(n%2){
            pow = pow*x;
        }
        x *= x;
        n /= 2;
    }
    return pow;
}

/******************************************************************************************************** */

long double rPower(long double x, long double n){  // The exponent is real, x^n
    if(!(n == n) && x  == 0.0L) return  n; 
    if(n == 0) return  1.0L; 
    if((n  = minusInf()) && x  == 0.0L) return  plusInf(); 
    if(x == 0.0L)  return 0.0L; 
    if(x == 1.0L)  return 1.0L;

    if(!(x == x)) return  x; //NaN 
    if(!(n  == n)) return n; //Nan

    if(x==plusInf() && n==plusInf()) return x;
    if(x==plusInf() && n==minusInf()) return 0.0L;
    if(x == plusInf() && n < 0.0L)  return 0.0L;
    if(x  == plusInf() && n >  0.0L) return x;



    if(x == minusInf()){
        if(n  == plusInf()) return  n; 
        if(n  == minusInf()) return  0.0L; 
        if((long long) n  == n){ // n  is  integral,  after converting a long double val(n) to long long int (removing frational part) if it is equal to n then its an integer
            if(n == 0.0L) return  1.0L; 
            if(n < 0.0L) return  0.0L; 
            
            if((long long) n  % 2) return  x; 
            return -x;
        }

        return myNaN();
    }

    if(ABS(n) == plusInf())  { 
        if(ABS(x) == 1.0L) return 1.0L;  // 1^inf or (-1)^inf = 1
        if(n == minusInf() && ABS(x) < 1.0L) return  plusInf();  // x^(-inf) = 1/x^inf , 1/(0.5)^inf = inf
        if(n == minusInf()) return 0.0L; //x^(-inf) = 1/x^inf
        if(n == plusInf() && ABS(x) < 1.0L) return  0.0L; // x^(inf) = 1/x^inf , repeated multiplication of a number less than 1 approaches 0
        return n;
    }

    if((long long) n  == n){
        if  (n == 0.0L) return  1.0L; 
        return iPower(x, (long long) n); 
    }

    return Exp(n *  Ln(x));

}




/******************************************************************************************************** */
/*                                               Exponent and Log                                         */
/******************************************************************************************************** */

long double Exp(long double x){
    // Exp(x) = e^x = 1 + x/1! + x^2/2! + x^3/3! + ...

    if(x == plusInf()) return plusInf(); 
    if(x == minusInf()) return 0.0L;     
    if(!(x == x)) return myNaN();        
    if(x == 0.0L) return 1.0L;           
    if(x == 1.0L) return E;

    long double sum = 1.0L;
    long double term = 1.0L;

    for(int i = 1; ABS(term)>TOL && i<MAXITERATION; i++){
        term *= x/i;
        sum += term;
    }
    return sum;
}

/******************************************************************************************************** */

long double Ln(long double x){

    // taylor's series
    // ln(y) = ln(1 + (y-1)) => let x = y-1 => ln(1 + x) = x - x^2/2 + x^3/3 + x^4/4 - . . .
    if(!(x==x)) return myNaN();
    if(x == plusInf()) return plusInf();
    if(x < 0.0L) return myNaN();
    if(x == 0.0L) return minusInf();

    int n = 0;
    while(x>2){ //Reduce x to [1,2] range
        x /= 2;
        n++;
    }
    while(x<1){ //increase x to [1,2] range
        x*=2;
        n--;
    }

    long double t = x-1;
    long double sum = 0.0L;

    for(int i = 1; i < MAXITERATION; i++){
        sum += t/i;
        t *= - (x - 1);
    }
    return sum + n*LN2;
}

/******************************************************************************************************** */

long double Log(long double x){
    if(x < 0.0L) return myNaN();
    if(x == 0.0L) return plusInf();

    long double res = Ln(x) / LN10;

    return res;
}

/******************************************************************************************************** */

long double Lg(long double x){
    if(x <= 0.0L) return myNaN();

    long double res = Ln(x) / LN2;

    return res;
}

/******************************************************************************************************** */

static unsigned long long factorial(int n){
    if(n < 0) return 0;  // Invalid

    unsigned long long res = 1;
    for (int i = 2; i <= n; i++){
        res *= i;
    }
    return res;
}


/******************************************************************************************************** */
/*                                       Basic Trignomatry Functions                                      */
/******************************************************************************************************** */

long double Sine(long double x){
    // sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...

    if(!(x==x)) return myNaN();
    if(x == plusInf() || x == minusInf()) return myNaN();
    if(x == 0.0L) return 0.0L;
    if(x == PI || x == -PI) return 0.0L;

    while (x > PI){
        x -= 2 * PI;
    }
    while (x < -PI){
        x += 2 * PI;
    }

    int terms = 10;
    long double res = 0.0L;
    int sign = 1;

    for(int i = 0; i<terms; i++){
        int exp = 2*i+1;
        res += sign * (iPower(x, exp) / factorial(exp));
        sign = -sign;
    }

    return res;
}

/******************************************************************************************************** */

long double Cosine(long double x){
    // sin(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ...

    if(!(x==x)) return myNaN();
    if(x == plusInf() || x == minusInf()) return myNaN();
    if(x == 0.0L) return 1.0L;
    if(x == PI || x == -PI) return -1.0L;


    while (x > PI){
        x -= 2.0L * PI;
    }
    while (x < -PI){
        x += 2.0L * PI;
    }


    int terms = 10;
    long double res = 0.0L;
    int sign = 1;

    for(int i = 0; i<terms; i++){
        int exp = 2*i;
        long double t = (iPower(x, exp) / factorial(exp));
        res += sign * t;
        sign = -sign;
    }

    // if(res < TOL && res > -TOL) return 0.0L;
    return res;
}

/******************************************************************************************************** */

long double Tangent(long double x){
    if(!(x==x)) return myNaN();
    if(x==plusInf() || x == minusInf()) return myNaN();
    if(x == 0.0L) return x; 

    long double cos_val = Cosine(x);
    long double sin_val = Sine(x);

    if(ABS(cos_val) < TOL){
        printf("cos is 0\n");
        return (sin_val>0.0L)? plusInf() : minusInf();
    }

    return sin_val / cos_val;
}

/******************************************************************************************************** */

long double Cotangent(long double x){
    if(x == plusInf()) return myNaN();
    if(x == minusInf()) return myNaN();
    if(!(x == x)) return myNaN(); 
    if(x == 0.0L) return plusInf();

    long double sin_val = Sine(x);
    long double cos_val = Cosine(x);


    if(ABS(sin_val) < TOL){
        return (x == 0.0L) ? plusInf() : (x > 0.0L) ? plusInf() : minusInf();  
    }

    return cos_val / sin_val;
}

/******************************************************************************************************** */

long double Secant(long double x){
    if(!(x == x)) return myNaN();
    if(x == plusInf()) return myNaN();  
    if(x == minusInf()) return myNaN(); 

    long double cos_val = Cosine(x);
    if(ABS(cos_val) < TOL){
        return (x > 0.0L) ? plusInf() : minusInf();
    }

    return 1.0L / cos_val;
}

/******************************************************************************************************** */

long double Cosecant(long double x){
    long double sin_val = Sine(x);

    if(x == plusInf()) return myNaN();  
    if(x == minusInf()) return myNaN(); 
    if(!(x == x)) return myNaN();       
    if(x == 0.0L) return plusInf(); 

    if(ABS(sin_val) < TOL){
        return (x > 0.0L) ? plusInf() : minusInf();  
    }

    return 1.0L / sin_val;
}



/******************************************************************************************************** */
/*                                       Inverse Trignomatry Functions                                    */
/******************************************************************************************************** */

long double arcSine(long double x){
    if(!(x==x)) return myNaN();
    if(ABS(x) > 1.0) return myNaN();

    if(x == 1.0) return PI / 2.0;
    if(x == 0.0L) return 0.0;
    if(x == -1.0) return -PI / 2.0;

    long double sum = x, term = x;
    x *= x;
    for (int i = 1; ABS(term)>TOL && i<MAXITERATION ; i++){
        term *= x * (2 * i - 1) / (2 * i);
        sum += term / (2 * i + 1);
    }
    return sum;
}

/******************************************************************************************************** */

long double arcCosine(long double x){
    if(!(x==x)) return myNaN();
     if(ABS(x) > 1.0L) return myNaN();

    if(x == 0.0L) return PI/2.0L;        
    if(x == -1.0L) return PI;        
    if(x == 1.0L) return 0.0L;

    long double t = Sqrt(1.0L - (x*x));     
    long double res = PI/2.0L - arcSine(x);  
    return res; 
}

/******************************************************************************************************** */

long double arcTangent(long double x){
    if(!(x == x)) return myNaN();            
    if(x == plusInf()) return PI / 2.0L;    
    if(x == minusInf()) return -PI / 2.0L; 

    long double t = Sqrt(1.0L + x * x);
    return arcSine(x / t);


    // // for x > 1 arctan(x) = pi/2 - arctan(1/x)
    // if(x > 1.0L){
    //     return (PI/2.0L) - arcTangent(1.0L / x);
    // } else if(x < -1.0L){  // for x < -1 arctan(x) = -pi/2 - arctan(1/x)
    //     return -(PI/2.0L) - arcTangent(1.0L / x);
    // }


    // long double res = 0.0L;
    // int sign = 1;
    // int terms = 20;

    // for(int i = 0; i< terms; i++){
    //     int t = 2*i+1;
    //     res += sign * iPower(x,t)/t;
    //     sign = -sign;
    // }

    // return res;
}

/******************************************************************************************************** */

long double arcCosecant(long double x){
    // arcCsc(x)=arcsin(1/x)
    if(!(x==x) || ABS(x) < 1.0L) return  myNaN();
    if(x == plusInf()) return 0.0L;
    if(x == minusInf()) return PI; 


    return arcSine(1.0L / x);
}

/******************************************************************************************************** */

long double arcSecant(long double x){
    // arcSec(x)=arccos(1/x);
    if(!(x==x) || ABS(x) < 1.0L) return  myNaN();
    if(x == plusInf()) return 0.0L;
    if(x == minusInf()) return PI; 

    return arcCosine(1.0L / x);
}

/******************************************************************************************************** */

long double arcCotangent(long double x){
    //arcCot(x)=arctan(1/x),
    if(!(x==x)) return myNaN(); 
    if(x == 0.0L) return PI / 2.0L; 
    if(x == plusInf()) return 0.0L;
    if(x == minusInf()) return PI; 

    return arcTangent(1.0L / x);
}



/******************************************************************************************************** */
/*                                       Hyperbolic Trignomatry Functions                                 */
/******************************************************************************************************** */

long double Sinh(long double x){
    if(!(x == x)) return myNaN();           
    if(x == plusInf()) return plusInf();  
    if(x == minusInf()) return minusInf();
    
    long double a = Exp(x);
    long double b = Exp(-x);
    
    return (a - b) / 2.0L;
}

/******************************************************************************************************** */

long double Cosh(long double x){
    if(!(x==x)) return myNaN();
    if(x == plusInf()) return plusInf();    
    if(x == minusInf()) return plusInf(); 
    
    long double a = Exp(x);
    long double b = Exp(-x);
    
    return (a + b) / 2.0L;
}

/******************************************************************************************************** */

long double Tanh(long double x){
    if(!(x==x)) return myNaN();
    if(x == plusInf()) return 1.0L;   
    if(x == minusInf()) return -1.0L;  
    if(x > 20.0L) return 1.0L;  
    if(x < -20.0L) return -1.0L;
    
    long double a = Exp(x);
    long double b = Exp(-x);
    
    return (a-b) / (a+b);
}

/******************************************************************************************************** */

long double Csch(long double x){
    if(!(x == x)) return myNaN();      
    if(x == 0.0L) return myNaN();
    if(x == plusInf() || x == minusInf()) return 0.0L;

    return 1.0L / Sinh(x);
}

/******************************************************************************************************** */

long double Sech(long double x){
    if(!(x == x)) return myNaN(); 
    if(x == plusInf() || x == minusInf()) return 0.0L;
    return 1.0L / Cosh(x);
}

/******************************************************************************************************** */

long double Coth(long double x){
    if(!(x == x)) return myNaN();          
    if(x == 0.0L) return myNaN();          
    if(x == plusInf()) return 1.0L;
    if(x == minusInf()) return -1.0L; 

    return Cosh(x) / Sinh(x);
}



/******************************************************************************************************** */
/*                                   Inverse Hyperbolic Trignomatry Functions                             */
/******************************************************************************************************** */


long double arcSinh(long double x){
    if(!(x==x) || x < 1.0L) return myNaN();
    if(x == plusInf()) return plusInf();     
    if(x == minusInf()) return minusInf(); 
    if(ABS(x) < 1.0L) return myNaN();

    long double res = Ln(x + Sqrt(x * x + 1.0L));
    return res;
}

/******************************************************************************************************** */

long double arcCosh(long double x){
    if(!(x==x) || x < 1.0L) return myNaN();
    if(x == plusInf()) return plusInf();      
    if(x == minusInf()) return myNaN();

    long double res = Ln(x + Sqrt(x * x - 1.0L));
    return res;
}

/******************************************************************************************************** */

long double arcTanh(long double x){
    if(!(x==x) || ABS(x) > 1.0L) return myNaN();
    if(ABS(x) == 1.0L) return (x>0) ? plusInf() : minusInf();

    long double res = 0.5L * Ln((1.0L + x) / (1.0L - x));
    return res;
}

/******************************************************************************************************** */

long double arcCsch(long double x){
    if(!(x==x)) return myNaN();  
    if(x==0.0L) return plusInf();  

    long double t = 1.0L / x;
    long double res = Ln(t + Sqrt(t * t + 1.0L));

    return res;
}

/******************************************************************************************************** */

long double arcSech(long double x){
    if(!(x==x)) return myNaN();  
    if(x <= 0.0L || x > 1.0L) return myNaN();

    long double t = 1.0L / x;
    long double res = Ln(t + Sqrt(t * t - 1.0L));

    return res;
}

/******************************************************************************************************** */

long double arcCoth(long double x){
    if(ABS(x) < 1.0L) return myNaN();
    if(ABS(x) == 1.0L) return (x > 0) ? plusInf() : minusInf();

    long double res = 0.5L * Ln((x + 1.0L) / (x - 1.0L));
    return res;
}  