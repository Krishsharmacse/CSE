#include <stdio.h>
// #include <stdlib.h>

#define MEMORY_SIZE 1024 // Total size of memory
#define PARTITION_SIZE 256 // partition size
#define NUM_PARTITIONS (MEMORY_SIZE / PARTITION_SIZE) // number of partitions

int memory[NUM_PARTITIONS];

void display_partitions();
void allocate_memory(int process_id);

int main() {
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        memory[i] = 0; // free partition
    }

    allocate_memory(1);
    allocate_memory(2);   
    display_partitions();

    allocate_memory(3);
    allocate_memory(4);
    allocate_memory(5);
    display_partitions();
   


    return 0;
}



void display_partitions() {
     printf("\n------------------------------");
    printf("\nMemory Status:\n");
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        printf("Partition %d: %s\n", i, memory[i] ? "Allocated" : "Free");
    }
    printf("------------------------------\n\n");
}

void allocate_memory(int process_id) {
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        if (memory[i] == 0) { 
            memory[i] = process_id;
            printf("Process %d allocated to partition %d\n", process_id, i);
            return;
        }
    }
    printf("No free partition available for process %d\n", process_id);
}
