
#include<stdio.h>

long long int max(long long int a, long long int b){
    return (a>b)? a: b;
}

long long int power(long long int base, long long int exp){
    if (base == 0) {
        return 0;
    }
    
    if(exp == 0){
        return 1;
    }

    long long res = base;
    for(long long i = 1; i <exp; i++){
        res *= base;
    }
    return res;
}

long long int length(long long int a){ // returns Long int 
   long long int length=0;
    while (a !=0){
       a = a/10;
       length++;
    }
    return length;        
}

long long int karatsuba(long long int x, long long int y){
    if(x<10 || y<10){
        return x*y;
    }
    else{
        long long int n = max(length(x),length(y));
        long long int half = n/2;

        if(n%2 != 0){
            half = (n+1)/2;
            n++;
        }

        long long int C = power(10,half);

        long long int Xl = x / C;
        long long int Xr = x % C;

        long long int Yl = y / C;
        long long int Yr = y % C;

        long long int XlYl = karatsuba(Xl, Yl);
        long long int XrYr = karatsuba(Xr,Yr);


        long long int Res = karatsuba(Xl + Xr, Yl + Yr);
        long long int XlYr_XrYl = Res - XlYl - XrYr;

        return ((power(10,n) * XlYl) + (power(10,half) * XlYr_XrYl) + XrYr); 
    }
}


int main(){
    long long int x = 123;
    long long int y = 123;
    printf("%lld x %lld = %lld",x, y , karatsuba(x,y));
    return 0; 
}