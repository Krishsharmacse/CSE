#include<stdio.h>
#include<stdlib.h>


int length(char exp[]);
void push(char val);
char pop();
int precedence(char x);
char* postFixGenerator(char exp[]);




// int main(){
//     char exp[] = "32+15*5";

//     char *res = postFixGenerator(exp);

//     printf("%s ------> %c", res, res[0]);

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
    int len = length(exp);
    char *PF = (char *)malloc((len*2)*sizeof(char));
    if(PF == NULL){
        printf("memory allocation failed");
        return NULL;
    }
    
    int i = 0, j =0;
    char x;
    node *temp_ = head;
    while(i < len){
        char symbol = exp[i];
        switch (symbol){
            case '(': 
                push(symbol); 
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
                while(head != NULL && precedence(x) >= precedence(symbol)){
                    PF[j++] = x;
                    x = pop();
                }
                push(x);
                push(symbol);
                break;
            
            default:
                while(symbol >= '0' && symbol <= '9'){
                    PF[j++] = symbol;
                    symbol = exp[++i];
                }
                PF[j++] = ' ';
                i--;
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