#include<stdio.h>
#include<stdlib.h>

//circular linked list
typedef struct Queue {
    int data;
    struct Queue *next;
} Queue;

Queue *rear = NULL;


void insert(int val);
int delete();


int main(){
    insert(5);
    insert(3);
    insert(7);
    insert(10);

    printf("%d\n", delete());
    printf("%d\n", delete());
    printf("%d\n", delete());
    printf("%d\n", delete());
    printf("%d\n", delete());
    
    return 0;
}


void insert(int val){
    Queue *temp = (Queue *)malloc(sizeof(Queue));

    if (temp == NULL) {
        printf(stderr, "Memory allocation failed\n");
        return;
    }


    if(rear == NULL){
        temp->data = val;
        temp->next = temp;
        rear = temp;
    }else{
        temp->data = val;
        temp->next = rear->next;
        rear->next = temp;
        rear = temp;
    }
}

int delete(){
    if (rear == NULL) {
        printf("Queue is empty ");
        return -1;
    }
    Queue *temp = rear->next;
    if(temp == rear){
        rear = NULL;
    }else{
        rear->next = temp->next;
    }
    int val = temp->data;
    free(temp);
    return val;
}