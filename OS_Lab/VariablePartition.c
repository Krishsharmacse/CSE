#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1024 // Total memory size
#define MAX_BLOCKS 100

int availableSpace = MEMORY_SIZE;

typedef struct {
    int size;
    int processId;
    long start_address;
} block;

void allocateMemory(int processId, int processSize);
void deallocateMemory(int processId);
void displayMemory();

block memory[MAX_BLOCKS];
int end = 0;

int main() {
    allocateMemory(1, 100);
    allocateMemory(2, 200);
    allocateMemory(3, 50);
    allocateMemory(4, 600);

    allocateMemory(5, 500);  // allocation  fail due to lack of space

    displayMemory();

    deallocateMemory(3);  
    deallocateMemory(1);  

    displayMemory();

    return 0;
}

void allocateMemory(int processId, int processSize) {
    if (processSize > availableSpace) {
        printf("No free space available for process p%d of size %d\n\n", processId, processSize);
        return;
    }

    memory[end].processId = processId;
    memory[end].size = processSize;

    if (end == 0) {
        memory[end].start_address = 0;
    } else {
        memory[end].start_address = memory[end - 1].start_address + memory[end - 1].size;
    }

    availableSpace -= processSize;
    end++;

    printf("Memory allocated to process p%d\n", processId);
    printf("Remaining free space: %d\n\n", availableSpace);
}

void deallocateMemory(int processId) {
    for (int i = 0; i < end; i++) {
        if (memory[i].processId == processId) {
            availableSpace += memory[i].size;
            memory[i].processId = -1;
            memory[i].size = 0;
            memory[i].start_address = 0;

            for (int j = i; j < end - 1; j++) {
                memory[j] = memory[j + 1];
                memory[j].start_address = (j == 0) ? 0 : memory[j - 1].start_address + memory[j - 1].size;
            }
            end--; 

            printf("Memory deallocated for process p%d\n", processId);
            return;
        }
    }

    printf("Process p%d not found in memory.\n\n", processId);
}

void displayMemory() {
    printf("\n\n");
    printf("Partition\tProcess ID\tProcess Size\tStart Address\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < end; i++) {
        if (memory[i].processId > 0) {  
            printf("%d\t\t%d\t\t%d\t\t%ld\n", 
                i, memory[i].processId, memory[i].size, memory[i].start_address);
        }
    }
    printf("\nAvailable Space: %d\n", availableSpace);
    printf("\n\n");
}

