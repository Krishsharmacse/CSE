#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void FIFO(int pages[], int numPages, int numFrames);
void LRU(int pages[], int numPages, int numFrames);
void Optimal(int pages[], int numPages, int numFrames);
void printFrames(int frames[], int numFrames);

// Main function
int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int numPages = sizeof(pages) / sizeof(pages[0]);
    int numFrames = 3;

    FIFO(pages, numPages, numFrames);
    LRU(pages, numPages, numFrames);
    Optimal(pages, numPages, numFrames);

    return 0;
}

void FIFO(int pages[], int numPages, int numFrames) {
    int frames[numFrames];
    int index = 0, pageFaults = 0;

    for (int i = 0; i < numFrames; i++)
        frames[i] = -1;

    printf("\nFIFO Page Replacement:\n");
    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        bool found = false;

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == page) {
                found = true;
                break;
            }
        }

        if (!found) {
            frames[index] = page;
            index = (index + 1) % numFrames;
            pageFaults++;
        }

        printFrames(frames, numFrames);
    }
    printf("Total Page Faults (FIFO): %d\n", pageFaults);
}

void LRU(int pages[], int numPages, int numFrames) {
    int frames[numFrames];
    int lastUsed[numFrames];
    int pageFaults = 0;

    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
        lastUsed[i] = -1;
    }

    printf("\nLRU Page Replacement:\n");
    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        bool found = false;

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == page) {
                found = true;
                lastUsed[j] = i;
                break;
            }
        }

        if (!found) {
            int lruIndex = 0;
            for (int j = 1; j < numFrames; j++) {
                if (lastUsed[j] < lastUsed[lruIndex])
                    lruIndex = j;
            }

            frames[lruIndex] = page;
            lastUsed[lruIndex] = i;
            pageFaults++;
        }

        printFrames(frames, numFrames);
    }
    printf("Total Page Faults (LRU): %d\n", pageFaults);
}

void Optimal(int pages[], int numPages, int numFrames) {
    int frames[numFrames];
    int pageFaults = 0;

    for (int i = 0; i < numFrames; i++)
        frames[i] = -1;

    printf("\nOptimal Page Replacement:\n");
    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        bool found = false;

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == page) {
                found = true;
                break;
            }
        }

        if (!found) {
            int replaceIndex = -1, farthest = -1;

            for (int j = 0; j < numFrames; j++) {
                int k;
                for (k = i + 1; k < numPages; k++) {
                    if (frames[j] == pages[k])
                        break;
                }
                if (k > farthest) {
                    farthest = k;
                    replaceIndex = j;
                }
                if (k == numPages) {
                    replaceIndex = j;
                    break;
                }
            }

            frames[replaceIndex] = page;
            pageFaults++;
        }

        printFrames(frames, numFrames);
    }
    printf("Total Page Faults (Optimal): %d\n", pageFaults);
}

void printFrames(int frames[], int numFrames) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] == -1)
            printf("- ");
        else
            printf("%d ", frames[i]);
    }
    printf("\n");
}
