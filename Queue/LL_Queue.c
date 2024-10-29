#include<stdio.h>
#include<stdlib.h>

//circular linked list
typedef struct Queue {
    int data;
    struct Queue *next;
} Queue;

Queue *rear = NULL;


void enqueue(int val);
int dequeue();


int main(){
    enqueue(5);
    enqueue(3);
    enqueue(7);
    enqueue(10);

    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    
    return 0;
}


void enqueue(int val){
    Queue *temp = (Queue *)malloc(sizeof(Queue));

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }


    temp->data = val;
    if(rear == NULL){
        temp->next = temp;
    }else{
        temp->next = rear->next;
        rear->next = temp;
    }
    rear = temp;
}

int dequeue(){
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