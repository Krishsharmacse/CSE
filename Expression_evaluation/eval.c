#include<stdio.h>
#include<stdlib.h>

#include "./Infix_to_postfix.c"


typedef struct FStack{
    float data;
    struct  FStack *next;
} floatStack;

static floatStack *floatHead = NULL; 
 
static float popFloat();
static void pushFloat(float val);
static float eval(char exp[]);
static int power(int base, int exp);
static float solve(float x, char op, float y);




static int power(int base, int exp){
    if (base == 0) return 0;
    if(exp == 0) return 1;

    int res = base;
    for(int i = 1; i <exp; i++){
        res *= base;
    }
    return res;
}



static float solve(float x, char op, float y){
    switch (op){
        case '*': return x * y;
        case '/': return x / y; 
        case '+': return x + y;
        case '-': return x - y;
        case '^': return power((int)x, (int)y); 
        default: return 0.0;
    }
}



static void pushFloat(float val){
    floatStack *temp = (floatStack *)malloc(sizeof(floatStack));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = val;
    temp->next = floatHead;
    floatHead = temp;
}


static float popFloat(){
    if(floatHead == NULL){
        printf("\nempty Stack \n");
        exit(1);
    }
    floatStack *temp = floatHead;
    char val = floatHead->data;
    floatHead = floatHead->next;
    free(temp);
    return val;
}



float eval(char exp[]){
    char *postFix = postFixGenerator(exp); 

    int i =0, j= 0;
    while(postFix[i] != '\0'){
        if(postFix[i] == '*' || postFix[i] == '/' || postFix[i] == '+' ||postFix[i] == '-' || postFix[i] == '^'){
            float res = solve( popFloat(), postFix[i],  popFloat());
            pushFloat(res);

        }else{
            if (postFix[i] >= '0' && postFix[i] <= '9') {
                pushFloat((float)postFix[i]-'0'); 
            }
        }
        i++;
    }

    return popFloat();
}