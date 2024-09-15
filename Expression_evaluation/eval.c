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
void validateExpression(char exp[]);
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
    float val = floatHead->data;
    floatHead = floatHead->next;
    free(temp);
    return val;
}

void validateExpression(char exp[]){
    if (exp[length(exp) - 1] == '\n') {
        exp[length(exp) - 1] = '\0';
    }
    
    char lst = exp[length(exp) - 1];
    if(lst == '*' || lst == '/' || lst == '+' ||lst == '-' || lst == '^'){
        printf("invalid expression");
        exit(1);
    }

    int i=0;
    char symbol = exp[i];
    while(symbol != '\0'){
        char stackSymbol;
        switch (symbol){
            case '(':
                push(symbol);
                break;
            case ')':
                stackSymbol = pop();
                if(stackSymbol == '\0' || stackSymbol != '('){
                    printf("invalid equation");
                    exit(1);
                }
                break;
            default:
                break;
        }
        symbol = exp[++i];
    }

    if(head != NULL){
        printf("Invalid Expression");
        exit(1);
    }
}


float eval(char exp[]){
    validateExpression(exp);

    char *postFix = postFixGenerator(exp); 

    int i =0, j= 0;
    while(i < length(postFix)){
        char symbol = postFix[i];
        if(symbol == '*' || symbol == '/' || symbol == '+' ||symbol == '-' || symbol == '^'){
            float op2 = popFloat();
            float op1 = popFloat();
            float res = solve( op1, symbol, op2 );
            pushFloat(res);

        }else{
            float val = 0;
            if(symbol != ' '){
                while (symbol >= '0' && symbol <= '9') {
                    val = val * 10 + (float)symbol - '0';
                    symbol = postFix[++i];
                }
                pushFloat(val); 
                i--;
            }
        }
        i++;
    }

    return popFloat();
}


// int main(){
//     // 7 + (9-5) * 2
//     char exp[] = "12*12";
    
//     // printf("enter the expression: ");
//     // fgets(exp, 100, stdin);

    
//     // if (exp[length(exp) - 1] == '\n') {
//     //     exp[length(exp) - 1] = '\0';
//     // }
    
//     float result = eval(exp);

//     printf("%s = %f\n",exp, result);

//     return 0;
// }
