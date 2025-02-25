#include<stdio.h>
#include<stdbool.h>

bool checkStraightLine(int** coordinates, int coordinatesSize) {
    int dx = coordinates[coordinatesSize-1][0] - coordinates[0][0];;
    int dy = coordinates[coordinatesSize-1][1] - coordinates[0][1];
    
    for(int i=1; i< coordinatesSize; i++){
        if( dy * (coordinates[i][0] - coordinates[0][0]) != dx * (coordinates[i][1] - coordinates[0][1]) ) return false;
    }

    return true;
}


int main(){
    int coordinates[6][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};

    // Correct way to pass a 2D array as int** (array of pointers)
    int* coordinatesPtr[6];
    for (int i = 0; i < 6; i++) {
        coordinatesPtr[i] = coordinates[i];  // Point each row pointer to the actual row
    }

    printf("%d", checkStraightLine(coordinatesPtr, 6));
}