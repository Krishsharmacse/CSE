#include <stdio.h>

#define BLOCKS 5
#define PROCESSES 4

void firstFit(int blockSizes[], int blockCount, int processSizes[], int processCount) {
    int allocation[processCount];
    for (int i = 0; i < processCount; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < blockCount; j++) {
            if (blockSizes[j] >= processSizes[i]) {
                allocation[i] = j;
                blockSizes[j] -= processSizes[i];
                break;
            }
        }
    }

    printf("First Fit Allocation:\n");
    for (int i = 0; i < processCount; i++) {
        if (allocation[i] != -1)
            printf("Process %d (%d units) -> Block %d\n", i, processSizes[i], allocation[i] + 1);
        else
            printf("Process %d (%d units) -> Not Allocated\n", i, processSizes[i]);
    }
}

void bestFit(int blockSizes[], int blockCount, int processSizes[], int processCount) {
    int allocation[processCount];
    for (int i = 0; i < processCount; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < processCount; i++) {
        int bestIdx = -1;
        for (int j = 0; j < blockCount; j++) {
            if (blockSizes[j] >= processSizes[i]) {
                if (bestIdx == -1 || blockSizes[j] < blockSizes[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSizes[bestIdx] -= processSizes[i];
        }
    }

    printf("Best Fit Allocation:\n");
    for (int i = 0; i < processCount; i++) {
        if (allocation[i] != -1)
            printf("Process %d (%d units) -> Block %d\n", i, processSizes[i], allocation[i] + 1);
        else
            printf("Process %d (%d units) -> Not Allocated\n", i, processSizes[i]);
    }
}

void worstFit(int blockSizes[], int blockCount, int processSizes[], int processCount) {
    int allocation[processCount];
    for (int i = 0; i < processCount; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < processCount; i++) {
        int worstIdx = -1;
        for (int j = 0; j < blockCount; j++) {
            if (blockSizes[j] >= processSizes[i]) {
                if (worstIdx == -1 || blockSizes[j] > blockSizes[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSizes[worstIdx] -= processSizes[i];
        }
    }

    printf("Worst Fit Allocation:\n");
    for (int i = 0; i < processCount; i++) {
        if (allocation[i] != -1)
            printf("Process %d (%d units) -> Block %d\n", i, processSizes[i], allocation[i] + 1);
        else
            printf("Process %d (%d units) -> Not Allocated\n", i, processSizes[i]);
    }
}

int main() {
    int blockSizes[BLOCKS] = {100, 500, 200, 300, 600};
    int processSizes[PROCESSES] = {212, 417, 112, 426};

    int blocksFirstFit[BLOCKS], blocksBestFit[BLOCKS], blocksWorstFit[BLOCKS];
    
    for (int i = 0; i < BLOCKS; i++) {
        blocksFirstFit[i] = blockSizes[i];
        blocksBestFit[i] = blockSizes[i];
        blocksWorstFit[i] = blockSizes[i];
    }

    firstFit(blocksFirstFit, BLOCKS, processSizes, PROCESSES);
    printf("\n");
    bestFit(blocksBestFit, BLOCKS, processSizes, PROCESSES);
    printf("\n");
    worstFit(blocksWorstFit, BLOCKS, processSizes, PROCESSES);

    return 0;
}
