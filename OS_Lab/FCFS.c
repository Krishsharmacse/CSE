#include <stdio.h>

#define MAX_PROCESSES 20

// FCFS
int main()
{
    int burstTimes[MAX_PROCESSES], 
        waitingTimes[MAX_PROCESSES], 
        turnaroundTimes[MAX_PROCESSES];
        
    int numProcesses, i;

    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("\nEnter the number of processes (max %d) -- ", MAX_PROCESSES);
    scanf("%d", &numProcesses);
    printf("\n");

    if (numProcesses <= 0 || numProcesses > MAX_PROCESSES) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (i = 0; i < numProcesses; i++) {
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &burstTimes[i]);
    }

    waitingTimes[0] = 0;
    turnaroundTimes[0] = burstTimes[0]; // waitingTimes[0] +  burstTimes[0];

    for (i = 1; i < numProcesses; i++) {
        waitingTimes[i] = waitingTimes[i - 1] + burstTimes[i - 1];
        turnaroundTimes[i] = turnaroundTimes[i - 1] + burstTimes[i];
        totalWaitingTime += waitingTimes[i];
        totalTurnaroundTime += turnaroundTimes[i];
    }


    printf("\n\n%20s %20s %12s %15s \n" , "WAITING TIME", "TURNAROUND TIME", "PROCESS", "BURST TIME");

    for (i = 0; i < numProcesses; i++) {
        printf("%15d %18d %16d %15d\n", i, burstTimes[i], waitingTimes[i], turnaroundTimes[i]);
    }

    printf("\nAverage Waiting Time ----- %.2f", totalWaitingTime / numProcesses);
    printf("\nAverage Turnaround Time -- %.2f \n\n", totalTurnaroundTime / numProcesses);

    return 0;
}
