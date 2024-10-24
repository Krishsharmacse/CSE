#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;

void insert(int);
void printLL(node *);
node *reverseList();

int main(){

    insert(1);
    insert(4);
    insert(6);
    insert(2);


    printLL(head);
    head = reverseList();
    printLL(head);

}


node *CreateNode(int val){
    node *NewNode = (node *)malloc(sizeof(node));
    NewNode->data = val;
    NewNode->next = NULL;
    return NewNode;
}

  
void insert(int val){
    node *n = CreateNode(val);

    if(head == NULL){
        head = n;
        return;
    }

    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
}

node *reverseList(){
    node *prev = NULL, *cur = head, *nex = NULL;
    while (head != NULL){
        nex = head->next;
        head->next = prev;
        prev = head;
        head = nex;
    }
    return prev;
}

void printLL(node *head){
    while(head != NULL){
        printf("%d", head->data);
        head = head->next;
        printf("--> ");
    }
    printf("NULL\n");
}