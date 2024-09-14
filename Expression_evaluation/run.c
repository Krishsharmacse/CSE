
#include<stdio.h>
#include "./eval.c"


int main(){
    char exp[] = "7+5*3/5^1+(3-2)";
    
    float result = eval(exp);

    printf("\n%f", result);

    return 0;
}
