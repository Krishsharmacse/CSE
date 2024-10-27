#include<stdio.h>
#include<stdbool.h>

char stack[100];
int top = 0;

void push(char x){
    if(top > 100){
        return;
    }
    stack[top++] = x; 
}

char pop(){
    if(top <= 0){
        return '\0';
    }

    return stack[--top];
}

int isValid(char* s) {
    int i = 0;
    top = 0;
    
    while(s[i] != '\0'){
        char sym = s[i++];
        switch(sym){
            case '(':
            case '{':
            case '[':
                push(sym);
                break;
            case ')':
                if(pop() != '('){
                    return false;
                }
                break;
            case '}':
                if(pop() != '{'){
                   return false;
                }
                break;
            case ']':
                if(pop() != '['){
                    return false;
                }
                break;
            default:
                return false;

        }
    }

    return top == 0;
}


int main(){
    isValid("{[]}()[{}]") ? printf("valid parentheses") : printf("Invalid parentheses");
    return 0;
}