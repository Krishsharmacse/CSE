#include<stdio.h>
#include<stdbool.h>

#define Process 5
#define Resources 3

bool isSafe(int MaxNeed[Process][Resources], int allocated[Process][Resources], int available[Process]);

int main(){
   
    // int need[Process][Resources]= {};

    int MaxNeed[Process][Resources] = {
        {0,0,0},
        {2,0,2},
        {0,0,0},
        {1,0,0},
        {0,0,2},
    };
     int allocated[Process][Resources] = {
        {0,1,0},
        {2,0,0},
        {3,0,3},
        {2,1,1},
        {0,0,2},
    };
    int available[Resources] = {0,0,0};

    if (isSafe(MaxNeed, allocated, available)) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is in Deadlock state.\n");
    }
}


bool isSafe(int MaxNeed[Process][Resources], int allocated[Process][Resources], int available[Process]){
    int need[Process][Resources]; 
    bool finish[Process] = {false};

    for (int i = 0; i < Process; i++) {
        for (int j = 0; j < Resources; j++) {
            need[i][j] = MaxNeed[i][j] - allocated[i][j];
        }
    }

    while (true) {
        bool found = false;

        for (int i = 0; i < Process; i++) {
            if (!finish[i]) {
                bool canFinish = true;
                for (int j = 0; j < Resources; j++) { 
                    if(need[i][j] > available[j]){
                        canFinish = false;
                        break;
                    }   
                }

                if(canFinish){
                    for (int j = 0; j < Resources; j++) {
                        available[j] += allocated[i][j];
                    }

                    finish[i] = true;
                    found = true;

                    printf("Process P%d has finished, available resources: ", i);
                    for (int j = 0; j < Resources; j++) {
                        printf("%d ", available[j]);
                    }
                    printf("\n");

                }
            }
        }

        // If no process is finished break
        if (!found) {
            break;
        }
    }

    for (int i = 0; i < Process; i++) {
        if (!finish[i]) {
            return false;  // The system is not in a safe state
        }
    }

    return true;
}
