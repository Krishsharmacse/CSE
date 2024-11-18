#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printSeekSequence(int *request, int n, int head, int seekCount) {
    printf("\nSeek Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", request[i]);
    }
    printf("\nTotal seek operations: %d\n", seekCount);
}

void fcfs(int request[], int n, int head) {
    int seekCount = 0;
    printf("\nFCFS Disk Scheduling:\nSeek Sequence is:\n");

    for (int i = 0; i < n; i++) {
        int distance = abs(request[i] - head);
        seekCount += distance;
        head = request[i];
        printf("%d -> ", request[i]);
    }
    printf("\nTotal number of seek operations (FCFS): %d\n", seekCount);
}

void sstf(int request[], int n, int head) {
    int seekCount = 0;
    int minDistance, currentTrack, minIndex;
    int remaining[n];
    int tempRequest[n];

    // Create a copy of the request array
    for (int i = 0; i < n; i++) {
        tempRequest[i] = request[i];
    }

    printf("\nSSTF Disk Scheduling:\nSeek Sequence is:\n");

    for (int i = 0; i < n; i++) {
        minDistance = INT_MAX;
        minIndex = -1;

        // Find the closest track (SSTF)
        for (int j = 0; j < n; j++) {
            if (tempRequest[j] != INT_MAX) {
                int distance = abs(tempRequest[j] - head);
                if (distance < minDistance) {
                    minDistance = distance;
                    minIndex = j;
                }
            }
        }

        // Mark the track as processed
        currentTrack = tempRequest[minIndex];
        seekCount += minDistance;
        head = currentTrack;
        tempRequest[minIndex] = INT_MAX;  // Mark this track as processed
        printf("%d -> ", currentTrack);
    }

    printf("\nTotal number of seek operations (SSTF): %d\n", seekCount);
}

void scan(int request[], int n, int head, int diskSize, int direction) {
    int seekCount = 0;
    int currentTrack, distance;
    int sortedRequest[n + 2];

    // Create a copy of the request array and add the boundaries (0 and disk size)
    for (int i = 0; i < n; i++) {
        sortedRequest[i] = request[i];
    }
    sortedRequest[n] = 0;
    sortedRequest[n + 1] = diskSize - 1;

    // Sort the array (request + 0 + diskSize)
    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            if (sortedRequest[i] > sortedRequest[j]) {
                int temp = sortedRequest[i];
                sortedRequest[i] = sortedRequest[j];
                sortedRequest[j] = temp;
            }
        }
    }

    printf("\nSCAN Disk Scheduling:\nSeek Sequence is:\n");

    int headIndex = 0;
    for (int i = 0; i < n + 2; i++) {
        if (sortedRequest[i] >= head) {
            headIndex = i;
            break;
        }
    }

    if (direction == 1) {
        // Move towards the right
        for (int i = headIndex; i < n + 2; i++) {
            currentTrack = sortedRequest[i];
            distance = abs(currentTrack - head);
            seekCount += distance;
            head = currentTrack;
            printf("%d -> ", currentTrack);
        }
        // Then move towards the left
        for (int i = headIndex - 1; i >= 0; i--) {
            currentTrack = sortedRequest[i];
            distance = abs(currentTrack - head);
            seekCount += distance;
            head = currentTrack;
            printf("%d -> ", currentTrack);
        }
    } else {
        // Move towards the left
        for (int i = headIndex - 1; i >= 0; i--) {
            currentTrack = sortedRequest[i];
            distance = abs(currentTrack - head);
            seekCount += distance;
            head = currentTrack;
            printf("%d -> ", currentTrack);
        }
        // Then move towards the right
        for (int i = headIndex; i < n + 2; i++) {
            currentTrack = sortedRequest[i];
            distance = abs(currentTrack - head);
            seekCount += distance;
            head = currentTrack;
            printf("%d -> ", currentTrack);
        }
    }

    printf("\nTotal number of seek operations (SCAN): %d\n", seekCount);
}

int main() {
    int request[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int n = sizeof(request) / sizeof(request[0]);
    int head = 53;
    int diskSize = 200;
    int direction = 1; // 1: moving right, 0: moving left

    fcfs(request, n, head);
    sstf(request, n, head);
    scan(request, n, head, diskSize, direction);

    return 0;
}
