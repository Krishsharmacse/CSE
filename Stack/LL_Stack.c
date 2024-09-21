#include<stdio.h>
#include<stdlib.h>

void push(int val);
int pop();

typedef struct Node{
    int data;
    struct  Node *next;
} node;

static node *head = NULL; 


// int main(){
//     // push(3);
//     // push(2);
//     // push(5);

//     printf("%d\n", pop());
//     printf("%d\n", pop());
//     printf("%d\n", pop());

//     // node *temp = head;
//     // while(temp != NULL){
//     //     printf("%d\n", temp->data);
//     //     temp = temp->next;
//     // }

//     return 0;
// }


void push(int val){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = head;
    head = temp;
}

int pop(){
    if(head == NULL){
        printf("empty stack");
        return -1;
    }
    node *temp = head;
    int val = head->data;
    head = head->next;
    free(temp);
    return val;
}