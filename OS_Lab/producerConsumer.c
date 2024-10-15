#include <stdio.h>
#include <stdlib.h>

int S = 1;      // semaphore
int full = 0;   // semaphore
int empty = 10; // semaphore
int i = 0;      // buffer items


void wait(int *x) {
    while ((*x) <= 0);
    (*x)--;
}
void signal(int *x) {
    (*x)++;
}

void producer() {
    wait(&empty);
    wait(&S);

    // critical section 
    printf("\nProducer produces item %d", ++i);

    signal(&S);
    signal(&full);

    
}

void consumer() {
    wait(&full);
    wait(&S);

    // critical section 
    printf("\nConsumer consumes item %d", --i);

    signal(&S);
    signal(&empty);
}


int main() {
    int choice;
    
    printf("\n1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 to Exit\n");

    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (empty != 0) {
                    producer();
                } else {
                    printf("\nBuffer is full \n");
                }
                break;
            case 2:
                if (full != 0) {
                    consumer();
                } else {
                    printf("\nBuffer is empty \n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice \n");
        }
    }
    return 0;
}