#include<stdio.h>
#include<stdlib.h>


int length(char exp[]);
void push(char val);
char pop();
int precedence(char x);
char* postFixGenerator(char exp[]);




// int main(){
//     char exp[] = "7 + (9-5) * 2";

//     char *res = postFixGenerator(exp);

//     printf("%s", res);

//     return 0;
// }







typedef struct Node{
    char data;
    struct  Node *next;
} node;

static node *head = NULL; 

int length(char exp[]){
    int k = 0;
    while(exp[k] != '\0'){
        k++;
    }
    return k;
}


char* postFixGenerator(char exp[]){  
    char *PF = (char *)malloc((length(exp))*sizeof(char));
    if(PF == NULL){
        printf("memory allocation failed");
        return NULL;
    }
    
    int i = 0, j =0;
    char x;
    node *temp_ = head;
    while(exp[i] != '\0'){
        switch (exp[i]){
            case '(': 
                push(exp[i]); 
                break;
            case ')':
                x= pop();
                while(x != '('){
                    PF[j++] = x;
                    x = pop();
                }
                
                break;

            case '-':
            case '+':
            case '*':
            case '/': 
            case '^':
                x = pop();
                while(head != NULL && precedence(x) >= precedence(exp[i])){
                    PF[j++] = x;
                    x = pop();
                }
                push(x);
                push(exp[i]);
                break;
            
            default:
                if(exp[i] != ' '){
                    PF[j++] = exp[i];
                }
                break;
        }
        i++;
    }

    while(head != NULL){
        PF[j++] = pop();
    }
  
    PF[j] = '\0';
    return PF;

    
}






void push(char val){
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data = val;
    temp->next = head;
    head = temp;
}

char pop(){
    if(head == NULL){
        return '\0';
    }
    node *temp = head;
    char val = head->data;
    head = head->next;
    free(temp);
    return val;
}






int precedence(char x){
    switch (x){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}