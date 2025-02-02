#include<stdio.h>

#define size 5

int Queue[size];
int F,R;

void EnQ(int val);
int DeQ();


int main(){
    F = R = -1;

    EnQ(5);
    EnQ(7);
    EnQ(4);
    EnQ(2);
    EnQ(2);

    printf("%d\n", DeQ());    
    printf("%d\n", DeQ());    
    printf("%d\n", DeQ());    
    printf("%d\n", DeQ());    
    printf("%d\n", DeQ());    
    printf("%d\n", DeQ());   

}


void EnQ(int val){
    if((R+1)%size == F){
        printf("Queue is full");
        return;
    }

       
    if(F==-1 && R == -1){
        F = 0;
    }

    R = (R+1)%size;
    Queue[R] = val;
}


int DeQ(){
    if(F == -1){
        printf("empty");
        return -1;
    }

    int val = Queue[F];

    if(F == R){   
        F = R = -1;
    }else{
        F = (F+1) % size;
    }
    return val;
}






