#include<stdio.h>


#define TOL 1.00e-6L

#define ABS(x) (((x) < 0) ? (-(x)) : (x))

double NewtonMin(double (*f)(double), double (*f1)(double), double (*f2)(double), double a){
    double x = a;
    int count = 0;
    while(count < 50){
        double fd1 = f1(x);
        double fd2 = f2(x);

        printf("%5lf %4lf\n", x, f(x));

        if(ABS(fd1) < TOL) break;
        if(ABS(fd2)<TOL){
            printf("Second deriv is too small\n");
            // return (fnData){x, f1(x), count, 0};
        }

        x = x - fd1 / fd2;
        count++;
    }
    return f1(x);
}




double f(double x){
    return x*x*x*x - 3*x*x*x + 2 ;
}
double f1(double x){
    return 4*x*x*x - 9*x*x;
}
double f2(double x){
    return 12*x*x - 18*x;
}


int main(){
    NewtonMin(f, f1, f2, 5);
}
