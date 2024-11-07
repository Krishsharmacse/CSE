#include<stdio.h>

#define size 100

void swap(int *Queue, int i, int j);
void printQ();
void Enqueue(int val);
int Dequeue();
void Heapify(int *Queue, int n, int i);


int Queue[size];
int end = 0;

int main(){

    printf("insertion in priority Queue: ");
    Enqueue(50);
    Enqueue(10);
    Enqueue(5);
    Enqueue(60);
    Enqueue(100);
    Enqueue(1);
    printQ();

    printf("deletion: ");
    int min = Dequeue();
    printf("\nminimum value: %d\n", min);
    printQ();
    return 0;
}

void printQ(){
    for(int i = 0; i < end; i++){
        printf("%d, ", Queue[i]);
    }
    printf("\n");
}

void swap(int *Queue, int i, int j){
    int temp = Queue[i];
    Queue[i] = Queue[j];
    Queue[j] = temp;
}

void Enqueue(int val){
    if(end >= size){
        printf("Q is full");
        return;
    }

    Queue[end++] = val;
    int i = end - 1; // index of last element
    // (i-1)/2 -> index of  parent element
    while(i != 0 && Queue[(i-1)/2] > Queue[i]){
        swap(Queue, i, (i-1)/2); 
        i = (i-1)/2;
    }
}

int Dequeue(){
    if(end <= 0){
        printf("Queue is empty\n");
        return -1;
    }

    int min = Queue[0];

    Queue[0] = Queue[--end];

    Heapify(Queue, end, 0);

    return min;
}


void Heapify(int *Queue, int n, int i){
    int l = 2 * i +1;
    int r = 2 * i +2;
    int min = i;

    if(l < n && Queue[l] < Queue[min]){
        min = l;
    }
    if(r < n && Queue[r] < Queue[min]){
        min = r;
    }

    if(min != i){
        swap(Queue, i, min);
        Heapify(Queue, n, min);
    }
}