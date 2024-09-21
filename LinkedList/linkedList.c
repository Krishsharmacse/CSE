#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;

}Node;

Node *head = NULL;



void Insert(int val){
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;

    
    if(head == NULL){
        head = n;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;

}


void InsetAt(int val, int index){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }


    int i=0;
    Node *temp = head;
    while(temp->next != NULL && i<index-1){
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void disp(Node *head){
    Node *temp = head;

    while (temp != NULL){
        printf(" %d -> ", temp->data);
        temp = temp->next;
    }
    
}

int main(){

   
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);

    InsetAt(5,2);

    disp(head);


}