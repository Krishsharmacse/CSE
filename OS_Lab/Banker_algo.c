#include <stdio.h>
#include <stdbool.h>

#define P 3  // Number of processes

bool isSafe(int processes[], int avail, int max[], int allot[]) {
    int need[P]; 
    bool finish[P] = {false};

    // Need = Max - Allocated
    for (int i = 0; i < P; i++) {
        need[i] = max[i] - allot[i];
    }

    while (true) {
        bool found = false;

        for (int i = 0; i < P; i++) {
            if (!finish[i] && need[i] <= avail) {
                avail += allot[i];
                finish[i] = true;
                found = true;
                printf("Process P%d has finished, available resources: %d\n", i + 1, avail);
            }
        }

        // If no process is finished break
        if (!found) {
            break;
        }
    }

    // all processes were able to finish
    for (int i = 0; i < P; i++) {
        if (!finish[i]) {
            return false;  // The system is not in a safe state
        }
    }

    return true;  // The system is in a safe state
}

int main() {
    int processes[P] = {0, 1, 2};
    int avail = 3;
    int max[P] = {10, 4, 9};
    int allot[P] = {5, 2, 2};

    if (isSafe(processes, avail, max, allot)) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is NOT in a safe state.\n");
    }

    return 0;
}
