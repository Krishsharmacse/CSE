#include<stdio.h>

long int max(long int a, long int b){
    return (a>b)? a: b;
}

long int power(long int base, long int exp){
    if (base == 0) {
        return 0;
    }
    
    if(exp == 0){
        return 1;
    }

    long res = base;
    for(long i = 1; i <exp; i++){
        res *= base;
    }
    return res;
}

long int length(long int a){ // returns Long int 
   long int length=0;
    while (a !=0){
       a = a/10;
       length++;
    }
    return length;        
}

long int karatsuba(long int x, long int y){
    if(x<10 || y<10){
        return x*y;
    }
    else{
        long int n = max(length(x),length(y));
        long int half = n / 2;
        long int C = power(10,half);

        long int Xl = x / C;
        long int Xr = x % C;

        long int Yl = y / C;
        long int Yr = y % C;

        long int XlYl = karatsuba(Xl, Yl);
        long int XrYr = karatsuba(Xr,Yr);

        long int XlYr_XrYl = karatsuba(Xl + Xr,Yl+Yr) - XlYl - XrYr;

        return ((power(10,n) * XlYl) + (power(10,half) * XlYr_XrYl) + XrYr); 
    }
}


int main(){
    long int x = 111;
    long int y = 123;
    printf("%ld x %ld = %ld",x, y , karatsuba(x,y));
    return 0;
}