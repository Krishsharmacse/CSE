#include<stdio.h>
#include<stdlib.h>

typedef struct CharStack {
    char val;
    struct CharStack* next;
} stack;

stack* head = NULL;

int Len(char *exp);
void reverse(char *exp);
void push(char val);
char pop();
int precedence(char x);
char* IndixToPreFix(char *exp);

int main(){
    // char expression[] = "A+B*(C-D)";
    char expression[] = "7+5*3/5^1+(3-2)";
    char *prefix = IndixToPreFix(expression);
    printf("%s", prefix);
   
    return 0;
}


int Len(char *exp){
    int count = 0;
    while(exp[count] != '\0'){
        count++;
    }
    return count;
}

void reverse(char *exp){
    int i = 0;
    int j = Len(exp)-1;
    while(i < j){
        char temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
        i++; j--;
    }

    i=0;
    while(exp[i] != '\0'){
        if(exp[i] == '('){
            exp[i] = ')';
        } else if(exp[i] == ')'){
            exp[i] = '(';
        }
        i++;
    }
}


char* IndixToPreFix(char *exp){
    reverse(exp); 
    int length = Len(exp);
    int i = 0,j=0;

    char *PF = (char *)malloc((length+1)*sizeof(char));
    if(PF == NULL){
        printf("memory allocation failed");
        return NULL;
    }

    // PF[length+1] = '\0';

    while(i < length){
        char sym = exp[i];
        char x;
        switch(sym){
            case '(':
                push(sym);
                break;
            case ')':
                x = pop();
                while(x != '('){
                    PF[j++] = x;
                    x= pop();
                }
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                x = pop();
                while(x != '\0' && precedence(x) > precedence(sym)){
                    PF[j++] = x;
                    x = pop();
                }
                push(x);
                push(sym);
                break;

            default:
                PF[j++] = sym;
                break;
        }
        i++;
    }

    char x = pop();
    while(x != '\0'){
        PF[j++] = x;
        x= pop();
    }

    PF[j]='\0';

    reverse(PF);

    printf("%s\n\n", PF);
    return PF;
}



void push(char val){
    stack* node = (stack*)malloc(sizeof(stack));
    if(node == NULL){
        printf("malloc error \n");
        exit(1);
    }
    node->val = val;
    node->next = head;
    head = node;
}

char pop(){
    if(head == NULL){
        return '\0';
    }
    stack* temp = head;
    char val = head->val; 
    head = head->next;
    free(temp);
    return val;
}



int precedence(char x){
    switch(x){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}