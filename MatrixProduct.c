// #include<stdio.h>


// int main(){
//     int rowA,colA;
//     int rowB,colB;

//     printf("enter rows and of Matrix A: ");
//     scanf("%d", &rowA );
//     scanf("%d", &colA );
    
//     printf("enter rows and of Matrix B: ");
//     scanf("%d", &rowB );
//     scanf("%d", &colB );


//     if(colA != rowB){
//         printf("matrix can't be multiplied");
//         return 1;
//     }

//     printf("\n");

//     int matrixA[rowA][colA];
//     int matrixB[rowB][colB];
//     int sum[rowA][colB];

//     printf("enter elements of matrix A (%d,%d): ", rowA,colA);
//     for(int i=0;i<rowA;i++){
//         for(int j=0;j<colA;j++){
//             scanf("%d", &matrixA[i][j]);
//         }
//     }

//     printf("\n\n");


//     printf("enter elements of matrix B (%d,%d): ",rowB,colB);
//     for(int i=0;i<rowB;i++){
//         for(int j=0;j<colB;j++){
//             scanf("%d", &matrixB[i][j]);
//         }
//     }






//     for(int i = 0; i<rowA; i++){
//         for(int j = 0; j<colB; j++){
//             sum[i][j] = 0;
//             for(int k = 0; k<rowB; k++){
//                 sum[i][j] = sum[i][j] + matrixA[i][k] * matrixB[k][j];
//             }
//         }
//     }

//     printf("\n\n C = A x B\n\nproduct matrix C : \n");
//     for(int i = 0; i<rowA; i++){
//         for(int j = 0; j<colB; j++){
//             printf(" %d ", sum[i][j]);
//         }
//         printf("\n");

//     }

//     return 0; 
// }


#include<stdio.h>
#include<limits.h>   // For integer type limits
#include<float.h>    // For floating-point type limits

int main() {
    printf("Ranges of different integer data types:\n");
    printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);

    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);

    printf("float: %.5e to %.5e\n", FLT_MIN, FLT_MAX);
    printf("double: %.5e to %.5e\n", DBL_MIN, DBL_MAX);


    return 0;
}
