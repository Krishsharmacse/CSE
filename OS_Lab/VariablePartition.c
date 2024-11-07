#include<stdio.h>
#include<stdlib.h>

#define MEMORY_SIZE 1024 // Total memory size
#define MAX_BLOCKS 100

int availableSpace = MEMORY_SIZE;

typedef struct{
    int size;
    int processId;
    long start_address;
} block;

void allocateMemory(int processId, int processSize);
void displayMemory();

block memory[MAX_BLOCKS];
int end = 0;


int main(){
    allocateMemory(1,100);
    allocateMemory(2,200);
    allocateMemory(3,50);
    allocateMemory(4,600);
    allocateMemory(5,500);

    displayMemory();
    allocateMemory(6,700);
}


void allocateMemory(int processId, int processSize){
    if(availableSpace < 0){
        printf("No free space available for process p%d of size %d\n\n", processId, processSize);
        return; 
    }

    memory[end].processId = processId;
    memory[end].size = processSize;
    
    if(end == 0){
        memory[end].start_address = 0;
    }else{
        memory[end].start_address = memory[end-1].start_address + memory[end-1].size;
    }

    printf("memory alloted to the process p%d\n", processId);
    printf("remaining free space: %d\n\n", availableSpace);

    availableSpace -= processSize;
    end++;
}

void displayMemory(){
    printf("\n\n");
    printf("processId\t\tprocess size\t\tstarting address\n");
    for(int i=0;i<end;i++){
        printf("p%d\t\t\t %d \t\t\t %ld\n", memory[i].processId, memory[i].size, memory[i].start_address);
    }
    printf("\n\n");
}