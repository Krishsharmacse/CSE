#include <stdio.h>
// #include <stdlib.h>

#define MEMORY_SIZE 1024 // Total size of memory
#define PARTITION_SIZE 256 // partition size
#define NUM_PARTITIONS (MEMORY_SIZE / PARTITION_SIZE) // number of partitions

typedef struct{
    int processId;
    int size;
    int IF;
} block;

block memory[NUM_PARTITIONS];

void display_partitions();
void allocate_memory(int processId, int size);
void deallocate_memory(int processId);
void  Fragmentation();

int main() {
    // free partition
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        memory[i].size = 0; 
        memory[i].processId = 0;
        memory[i].IF = 0;
    }

    allocate_memory(1, 200);
    allocate_memory(2, 150);   
    allocate_memory(3, 50);
    display_partitions();

    deallocate_memory(3);

    allocate_memory(4,20);
    allocate_memory(5,60);
    display_partitions();

    Fragmentation();
   


    return 0;
}



void display_partitions() {
     printf("\n------------------------------");
    printf("\nMemory Status:\n");
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        printf("Partition %d: ", i);
        if (memory[i].processId == 0) {
            printf("Free\n");
        } else if (memory[i].processId == -1) {
            printf("Deallocated\n");
        } else {
            printf("Alocated Process %d\n", memory[i].processId);
        }
    }
    printf("------------------------------\n\n");
}

void allocate_memory(int processId, int size) {
    if(size > PARTITION_SIZE){
        printf("Not enough space\n");
        return;
    }
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        if (memory[i].processId == 0) { 
            memory[i].processId = processId;
            memory[i].size = size;
            memory[i].IF = PARTITION_SIZE - size;
            printf("Process %d allocated to partition %d\n", processId, i);
            return;
        }
    }
    printf("No free partition available for process %d\n", processId);
}


void deallocate_memory(int processId){
     for (int i = 0; i < NUM_PARTITIONS; i++) {
        if (memory[i].processId == processId) { 
            memory[i].processId = -1;
            memory[i].size = 0;
            memory[i].IF = 0;
            printf("Process %d is deallocated\n\n", processId);
            return;
        }
    }

    printf("process not found\n");
    return;
}

void Fragmentation() {
    int total = 0;
    printf("Partition\tProcess ID\tInternal Fragmentation\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        if (memory[i].processId > 0) {
            total += memory[i].IF;
            printf("%d\t\t%d\t\t%d\n", i, memory[i].processId, memory[i].IF);
        }
    }
    printf("-------------------------------------------------\n");
    printf("Total Internal Fragmentation: %d\n\n", total);
}
