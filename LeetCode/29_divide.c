#include<stdio.h>
#include<limits.h>


int divide(int dividend, double divisor) {

    if(dividend==INT_MIN && divisor==-1) return INT_MAX;
    if(dividend==INT_MIN && divisor==1) return INT_MIN;

    long int absoluteDividend = fabs(dividend);
    long int absoluteDivisor = fabs(divisor);
    int quotient = 0;

    while (absoluteDivisor <= absoluteDividend) {
        long int tempDivisor = absoluteDivisor;
        long int multiple = 1;

        while (tempDivisor <= absoluteDividend - tempDivisor) {
            tempDivisor += tempDivisor;
            multiple += multiple;      
        }
        
        quotient += multiple;         
        absoluteDividend -= tempDivisor;
    }

    if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
        return -quotient;
    }    
        
    return quotient;

}

int main(){
    int x = 20, y = 2;

    printf("%d", divide(x,y));

}