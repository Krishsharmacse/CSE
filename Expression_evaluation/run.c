
#include<stdio.h>
#include "./eval.c" // eval and length function

#define MAX_LENGTH 100


int main(){
    // 7 + (9-5) * 2
    char exp[MAX_LENGTH];
    
    printf("enter the expression: ");
    fgets(exp, MAX_LENGTH, stdin);

    
    if (exp[length(exp) - 1] == '\n') {
        exp[length(exp) - 1] = '\0';
    }
    
    float result = eval(exp);

    printf("%s = %f\n",exp, result);

    return 0;
}
