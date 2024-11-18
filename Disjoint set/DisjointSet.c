#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
    struct Node *Head;
} Node;

Node* makeSet(int val);
Node* find(Node *node);
void Union(Node *x, Node *y);
void printSet(Node *node);

int main(){

    // Node *s1 = makeSet(4);
    // Node *s2 = makeSet(3);
    // Node *s3 = makeSet(6);
    // Node *s4 = makeSet(10);
    // Node *s5 = makeSet(1);
    // Node *s6 = makeSet(22);
    
    // Union(s1, s2);
    // Union(s2, s3);
    // Union(s3, s4);
    // Union(s5, s6);

    Node *s1 = makeSet(1);
    Node *s2 = makeSet(2);
    Node *s3 = makeSet(3);
    Node *s4 = makeSet(2);

    Union(s1, s2);
    Union(s2, s4);

    printSet(s1);
    printSet(s3);

    return 0;
}


Node* makeSet(int val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->Head = node;
    node->next = NULL;

    return node;
}

Node* find(Node *node){
    return node->Head;
}

void Union(Node *x, Node *y){
    Node *xHead = find(x);
    Node *yHead = find(y);

    if(xHead == yHead){
        return;
    }

    Node *temp = xHead;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = yHead;

    temp = yHead;
    while(temp != NULL){
        temp->Head = xHead;
        temp = temp->next;
    }

}   


void printSet(Node *node){
    Node* head = find(node);
    printf("Head %d: ", head->data);
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}






