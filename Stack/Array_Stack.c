#include<stdio.h>

#define length 20

void push(int val);
int pop();
int peek();

static int stack[length];
static int top = 0;

int main(){
    push(3);
    push(2);
    push(5);

    printf("top = %d, val -> %d\n",top, peek());
    printf("top = %d, val -> %d\n",top, pop());
    printf("top = %d, val -> %d\n",top, pop());
    printf("top = %d, val -> %d\n",top, pop());
    printf("top = %d, val -> %d\n",top, pop());

    return 0;
}



void push(int val){
    if(top >= length){
        printf("stack is full\n");
        return;
    }
    stack[top++] = val;
}


int pop(){
    if(top <= 0){
        printf("stack is empty\n");
        return -1;
    }
    int val = stack[--top];
    return val;
}


int peek(){
    if(top <= 0){
        printf("stack is empty\n");
        return -1;
    }
    int val = stack[top-1];
    return val;
}