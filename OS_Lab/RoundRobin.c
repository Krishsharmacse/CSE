#include <stdio.h>

#define MAX_PROCESSES 10

int main() {
    int i, j, numProcesses, burstTimes[MAX_PROCESSES], waitingTimes[MAX_PROCESSES], turnaroundTimes[MAX_PROCESSES];
    int timeSlice, remainingBurstTimes[MAX_PROCESSES];
    
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    int maxBurstTime = 0, currentTime = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &numProcesses);
    printf("\n");

    for (i = 0; i < numProcesses; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &burstTimes[i]);
        remainingBurstTimes[i] = burstTimes[i];
    }

    // Input time slice (quantum)
    printf("\nEnter the time slice (quantum): ");
    scanf("%d", &timeSlice);

    for (i = 0; i < numProcesses; i++) {
        if (maxBurstTime < burstTimes[i]) {
            maxBurstTime = burstTimes[i];
        }
    }

    // Round Robin scheduling
    for (i = 0; i < (maxBurstTime / timeSlice) + 1; i++) {
        for (j = 0; j < numProcesses; j++) { 
            if (remainingBurstTimes[j] > 0) {
                if (remainingBurstTimes[j] <= timeSlice) {
                    turnaroundTimes[j] = currentTime + remainingBurstTimes[j];
                    currentTime += remainingBurstTimes[j];
                    remainingBurstTimes[j] = 0;
                } else {
                    remainingBurstTimes[j] -= timeSlice;
                    currentTime += timeSlice;
                }
            }
        }
    }

    for (i = 0; i < numProcesses; i++) {
        waitingTimes[i] = turnaroundTimes[i] - burstTimes[i];
        totalTurnaroundTime += turnaroundTimes[i];
        totalWaitingTime += waitingTimes[i];
    }

    printf("\n\n%5s %15s %17s %18s \n" , "PROCESS", "BURST TIME", "WAITING TIME", "TURNAROUND TIME");
 
    
    for (i = 0; i < numProcesses; i++) {
        printf("  p%-14d %d %16d %15d\n", i + 1, burstTimes[i], waitingTimes[i], turnaroundTimes[i]);
    }

    printf("\nAverage Waiting Time ----- %.2f", totalWaitingTime / numProcesses);
    printf("\nAverage Turnaround Time -- %.2f \n\n", totalTurnaroundTime / numProcesses);

    return 0;
}
