#include <stdio.h>
#define MAX_PROCESSES 20

int main() {
    int processIDs[MAX_PROCESSES], burstTimes[MAX_PROCESSES], priorities[MAX_PROCESSES];
    int waitingTimes[MAX_PROCESSES], turnaroundTimes[MAX_PROCESSES];
    int numProcesses, i, j, temp;
    float totalWaitingTime, totalTurnaroundTime;

    printf("\nEnter the number of processes: ");
    scanf("%d", &numProcesses);
    printf("\n");

    for (i = 0; i < numProcesses; i++) {
        processIDs[i] = i;
        printf("Enter the Burst Time and Priority of Process %d: ", i);
        scanf("%d %d", &burstTimes[i], &priorities[i]);
    }

    // Sort processes based on priority (ascending order, highest priority first)
    for (i = 0; i < numProcesses - 1; i++) {
        for (j = i + 1; j < numProcesses; j++) {
            if (priorities[i] < priorities[j]) {
                // Swap priorities
                temp = priorities[i];
                priorities[i] = priorities[j];
                priorities[j] = temp;

                // Swap burst times
                temp = burstTimes[i];
                burstTimes[i] = burstTimes[j];
                burstTimes[j] = temp;

                // Swap process IDs
                temp = processIDs[i];
                processIDs[i] = processIDs[j];
                processIDs[j] = temp;
            }
        }
    }

    waitingTimes[0] = 0;
    turnaroundTimes[0] = burstTimes[0];
    totalWaitingTime = waitingTimes[0];
    totalTurnaroundTime = turnaroundTimes[0];

    for (i = 1; i < numProcesses; i++) {
        waitingTimes[i] = waitingTimes[i - 1] + burstTimes[i - 1];
        turnaroundTimes[i] = waitingTimes[i] + burstTimes[i];
        totalWaitingTime += waitingTimes[i];
        totalTurnaroundTime += turnaroundTimes[i];
    }

    printf("\n\n%5s %15s %17s %18s \n" , "PROCESS","PRIORITY", "BURST TIME", "WAITING TIME", "TURNAROUND TIME");



    for (i = 0; i < numProcesses; i++) {
        printf("  p%-14d %d %16d %15d\n", processIDs[i], priorities[i], burstTimes[i], waitingTimes[i], turnaroundTimes[i]);
    }


    printf("\nAverage Waiting Time ----- %.2f", totalWaitingTime / numProcesses);
    printf("\nAverage Turnaround Time -- %.2f \n\n", totalTurnaroundTime / numProcesses);

    return 0;
}
