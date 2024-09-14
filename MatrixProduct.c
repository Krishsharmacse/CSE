#include<stdio.h>


int main(){
    int rowA,colA;
    int rowB,colB;

    printf("enter rows of Matrix A: ");
    scanf("%d", &rowA );
    
    printf("enter column of Matrix A: ");
    scanf("%d", &colA );
    
    printf("enter rows of Matrix B: ");
    scanf("%d", &rowB );
    
    printf("enter column of Matrix B: ");
    scanf("%d", &colB );

    printf("\n-----------------------------------------------\n");


    int matrixA[rowA][colA];
    int matrixB[rowB][colB];

    printf("enter elements of matrix A (%d,%d): ", rowA,colA);
    for(int i=0;i<rowA;i++){
        for(int j=0;j<colA;j++){
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("\n matrix A:");
    printf("\n-------------------------------\n");
    for(int i=0;i<rowA;i++){
        printf("| ");
       for(int j=0;j<colA;j++){
            printf(" %d ", matrixA[i][j]);
       }
       printf(" |\n");
    }
    printf("-------------------------------\n\n");


    printf("enter elements of matrix B (%d,%d): ",rowB,colB);
    for(int i=0;i<rowB;i++){
        for(int j=0;j<colB;j++){
            scanf("%d", &matrixB[i][j]);
        }
    }

    printf("\n matrix B:");
    printf("\n-------------------------------\n");
    for(int i=0;i<rowB;i++){
        printf("| ");
       for(int j=0;j<colB;j++){
            printf(" %d ", matrixB[i][j]);
       }
       printf(" |\n");
    }
    printf("-------------------------------\n\n");


    int sum[rowA][colB];
    for(int i=0;i<rowA;i++){
        for(int j=0;j<colB;j++){
            sum[i][j] = 0;
        }
    }

   
    
    

    
    

    for(int i = 0; i<rowA; i++){
        for(int j = 0; j<colB; j++){
            
            for(int k = 0; k<rowB; k++){
                sum[i][j] = sum[i][j] + matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    printf("product of matrixes : \n");
    for(int i = 0; i<rowA; i++){
        for(int j = 0; j<colB; j++){
            printf(" %d ", sum[i][j]);
        }
        printf("\n");

    }

    return 0; 
}