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


Node* removeNthFromEnd(Node* head, int n) {
    int length = 0;
    Node* temp = head;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }

    if(length <= 1){
        head = NULL;
        return head;
    }  

    int target = length - n, i = 0;

    if(target < 0){
        return NULL;
    }
    if(target == 0){
        return head->next;;
    }

    temp = head;
    while(temp->next != NULL && i<target-1){
        temp = temp->next;
        i++;
    }

    printf("val: %d\n", temp->data);

    if(temp->next->next != NULL){
        temp->next = temp->next->next;
    }else{
        temp->next = NULL;
    }
    
    return head;
}


void disp(Node *head){
    Node *temp = head;

    while (temp != NULL){
        printf(" %d -> ", temp->data);
        temp = temp->next;
    }

    printf("\n");
    
}

int main(){

   
    Insert(1);
    Insert(2);
    // Insert(3);
    // Insert(4);


    disp(head);

    disp(removeNthFromEnd(head, 2));
    


}