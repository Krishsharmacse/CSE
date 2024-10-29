#include<stdio.h>
#include<stdlib.h>

void push(int val);
int pop();
int peek();

typedef struct Node{
    int data;
    struct  Node *next;
} node;

static node *head = NULL; 


int main(){
    push(3);
    push(2);
    push(5);

    printf("peek: %d\n", peek());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());


    return 0;
}


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

int peek(){
    if(head == NULL){
        printf("empty stack ");
        return -1;
    }
    int val = head->data;
    return val;
}