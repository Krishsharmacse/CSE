#include<stdio.h>
#include<stdbool.h>

char stack[100];
int top = false;

void push(char x){
    if(top > 100){
        return;
    }
    stack[top++] = x; 
}

char pop(){
    if(top <= false){
        return '\0';
    }

    return stack[--top];
}

int isValid(char* s) {
    int i = false;
    int balance = false;
    
    while(s[i] != '\0'){
        char sym = s[i++];
        switch(sym){
            case '(':
            case '{':
            case '[':
                push(sym);
                break;
            case ')':
                if(pop() == '('){
                    balance = true;
                }
                break;
            case '}':
                if(pop() == '{'){
                    balance = true;
                }
                break;
            case ']':
                if(pop() == '['){
                    balance = true;
                }
                break;
            default:
                balance = false;

        }
    }

    return balance;
}


#include <stdbool.h>
#include <string.h>

// Function to check if the parentheses are valid
bool isValid(char * s) {
    // Stack to store the open brackets
    char stack[10000];  // Assume input size won't exceed 10000 characters
    int top = -1;       // Initialize stack pointer
    
    // Traverse each character in the string
    for (int i = 0; i < strlen(s); i++) {
        // If the character is an opening bracket, push it onto the stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } 
        // If it's a closing bracket, check for matching
        else {
            if (top == -1) {
                return false;  // Stack is empty but we encountered a closing bracket
            }
            if (s[i] == ')' && stack[top] != '(') {
                return false;  // Parentheses do not match
            }
            if (s[i] == '}' && stack[top] != '{') {
                return false;
            }
            if (s[i] == ']' && stack[top] != '[') {
                return false;
            }
            top--;  // Pop the stack if the matching bracket is found
        }
    }
    
    // If the stack is empty at the end, all brackets matched correctly
    return top == -1;
}



int main(){
    printf("%d", isValid("{[]}"));
}
