#include<stdio.h>


void sort(int *matrix, int matrixSize){
    for(int i = 1; i< matrixSize; i++){
        int val = matrix[i];
        int j = i - 1;
        while(j > -1 && val < matrix[j]){
            matrix[j+1] = matrix[j];
            matrix[j--] = val;
        }
        
    }

    
}

int main(){
    int matrix[3][3] = {{3,2,1},{6,5,4},{9,8,7}};
    int matrixSize = 3;
    

    for(int i=0; i<3; i++){
        sort(matrix[i], 3);
    }

    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize; j++){
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}