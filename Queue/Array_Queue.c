#include<stdio.h>

#define size 20

int Q[size];
int front, rear;
// int count;

void insert(int val);
int delete();

int main(){
    front = rear = 0;

    insert(5);
    insert(7);
    insert(4);
    insert(2);

    printf("%d\n", delete());    
    printf("%d\n", delete());    
    printf("%d\n", delete());    
    printf("%d\n", delete());    
    printf("%d\n", delete());    
    printf("%d\n", delete());    


    return 0; 
}


void insert(int val){
    if((rear + 1) % size == front){
        printf("queue is full");
        return;
    }

    Q[rear] = val;
    rear = (rear + 1) % size;
}

int delete(){
    if(front == rear){
        printf("queue is empty ");
        return -1;
    }

    int val = Q[front];
    front = (front + 1) % size;
    return val;
}
