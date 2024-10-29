#include<stdio.h>
#include<stdlib.h>

typedef struct matrix{
    int Row;
    int Col;
    int Val;
} matrix;

matrix * SparseAddition(matrix *A, matrix * B, int m, int n, int *Index);

int main(){
    int m = 6, n = 6, AddIndex = 0;
    matrix A[m], B[n];
         //    0  1  2  3
    // 0 ->  | 0  5  0  0 |
    // 1 ->  | 2  0  0  0 |
    // 2 ->  | 0  0  4  0 |
    // 3 ->  | 0  0  0  3 |
    // 4 ->  | 0  1  0  0 |

    A[0].Row = 5; A[0].Col = 4; A[0].Val = 5;

    A[1].Row = 0; A[1].Col = 1; A[1].Val = 5;
    A[2].Row = 1; A[2].Col = 0; A[2].Val = 2;
    A[3].Row = 2; A[3].Col = 2; A[3].Val = 4;
    A[4].Row = 3; A[4].Col = 3; A[4].Val = 3;
    A[5].Row = 4; A[5].Col = 2; A[5].Val = 1;


         //   0  1  2  3
    // 0 -> | 0  2  0  0 |
    // 1 -> | 0  0  3  0 |
    // 2 -> | 0  5  0  0 |
    // 3 -> | 0  0  0  7 |
    // 4 -> | 0  9  0  0 |

    B[0].Row = 5; B[0].Col = 4; B[0].Val = 5;

    B[1].Row = 0; B[1].Col = 1; B[1].Val = 2;
    B[2].Row = 1; B[2].Col = 2; B[2].Val = 3;
    B[3].Row = 2; B[3].Col = 1; B[3].Val = 5;
    B[4].Row = 3; B[4].Col = 3; B[4].Val = 7;    
    B[5].Row = 4; B[5].Col = 1; B[5].Val = 9;    

    matrix *sum = SparseAddition(A, B, m, n, &AddIndex);

    printf("addition: \n");
    printf(" R  C  V\n");
    printf("(%d  %d  %02d)\n", sum[0].Row, sum[0].Col, sum[0].Val);
    for(int i = 0; i< AddIndex; i++){
        printf("(%d  %d  %02d)\n", sum[i].Row, sum[i].Col, sum[i].Val);
    }

}




matrix * SparseAddition(matrix *A, matrix * B, int m, int n, int *Index){

    if(A[0].Row != B[0].Row || A[0].Col != B[0].Col){
        printf("Matrices can't be added\n");
        return NULL;
    }

    int i=1,j=1,k=1;

    matrix * sum = (matrix*)malloc((m+n)* sizeof(matrix));
    sum[0].Row = A[0].Row; sum[0].Col = A[0].Col; sum[0].Val = 0; 


    while(i<m && j<n){
        if(A[i].Row == B[j].Row && A[i].Col == B[j].Col){
            sum[k].Row = A[i].Row; sum[k].Col = A[i].Col;
            sum[k].Val = A[i].Val + B[j].Val;

            i++; j++; k++;

        }else if( (A[i].Row < B[j].Row) || ( (A[i].Row == B[j].Row) && (A[i].Col < B[j].Col)) ){
            sum[k++] = A[i++];
        }else{
            sum[k++] = B[j++];
        }

    }

    while(i<m){
        sum[k++] = A[i++];
    }
    
    while(j<n){
        sum[k++] = B[j++];
    }

    *Index = k;
    sum[0].Val = k;

    return sum;
}