#include<stdio.h>

#define size 20

int Q[size];
int front, rear;

void enqueue(int val);
int Dequeue();

int main(){
    front = rear = 0;

    enqueue(5);
    enqueue(7);
    enqueue(4);
    enqueue(2);

    printf("%d\n", Dequeue());    
    printf("%d\n", Dequeue());    
    printf("%d\n", Dequeue());    
    printf("%d\n", Dequeue());    
    printf("%d\n", Dequeue());    


    return 0; 
}


void enqueue(int val){
    if((rear + 1) % size == front){
        printf("queue is full");
        return;
    }

    Q[rear] = val;
    rear = (rear + 1) % size;
}

int Dequeue(){
    if(front == rear){
        printf("queue is empty ");
        return -1;
    }

    int val = Q[front];
    front = (front + 1) % size;
    return val;
}
