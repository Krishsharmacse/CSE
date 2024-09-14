#include <stdio.h>

#define MAX_PROCESSES 20

int main() {
    int processIDs[MAX_PROCESSES], 
        burstTimes[MAX_PROCESSES], 
        waitingTimes[MAX_PROCESSES], 
        turnaroundTimes[MAX_PROCESSES];

    int i, j, numProcesses, temp, minIndex;
    float totalWaitingTime, totalTurnaroundTime;

    printf("\nEnter the number of processes (max %d) -- ", MAX_PROCESSES);
    scanf("%d", &numProcesses);
    printf("\n");

    if (numProcesses <= 0 || numProcesses > MAX_PROCESSES) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (i = 0; i < numProcesses; i++) {
        processIDs[i]= i;
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &burstTimes[i]);
    }

    // Sort burst times in ascending order using Selection Sort and rearrange process IDs accordingly
    for (i = 0; i < numProcesses - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < numProcesses; j++) {
            if (burstTimes[j] < burstTimes[minIndex]) {
                minIndex = j;
            }
        }

        // Swap burst times
        if (minIndex != i) {
            temp = burstTimes[i];
            burstTimes[i] = burstTimes[minIndex];
            burstTimes[minIndex] = temp;

            // Swap process IDs
            temp = processIDs[i];
            processIDs[i] = processIDs[minIndex];
            processIDs[minIndex] = temp;
        }
    }

    waitingTimes[0] = 0;
    turnaroundTimes[0] = burstTimes[0];
    totalWaitingTime = 0;
    totalTurnaroundTime = burstTimes[0];

    for (i = 1; i < numProcesses; i++) {
        waitingTimes[i] = waitingTimes[i - 1] + burstTimes[i - 1];
        turnaroundTimes[i] = waitingTimes[i] + burstTimes[i];
        totalWaitingTime += waitingTimes[i];
        totalTurnaroundTime += turnaroundTimes[i];
    }

    printf("\n\n%5s %15s %17s %18s \n" , "PROCESS", "BURST TIME", "WAITING TIME", "TURNAROUND TIME");

    for (i = 0; i < numProcesses; i++) {
        printf("  p%-14d %d %16d %15d\n", processIDs[i], burstTimes[i], waitingTimes[i], turnaroundTimes[i]);
    }

    printf("\nAverage Waiting Time ----- %.2f", totalWaitingTime / numProcesses);
    printf("\nAverage Turnaround Time -- %.2f \n\n", totalTurnaroundTime / numProcesses);

    return 0;
}
