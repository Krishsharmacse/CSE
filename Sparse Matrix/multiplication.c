#include<stdio.h>
#include<stdlib.h>

typedef struct matrix{
    int Row;
    int Col;
    int Val;
} matrix;

void printMatrix(matrix *X, int size);
matrix * SparseMultiplication(matrix *A, matrix * B, int m, int n, int *Index);
matrix * FastTranspose(matrix *A, int m);

int main(){
    int m = 5, n = 4, MulIndex = 0;
    matrix A[m], B[n];
    // A //    0  1  2
    // 0 ->  | 0  5  0 |
    // 1 ->  | 2  0  0 |
    // 2 ->  | 0  0  4 |
    // 3 ->  | 0  7  0 |

    A[0].Row = 4; A[0].Col = 3; A[0].Val = 4;

    A[1].Row = 0; A[1].Col = 1; A[1].Val = 5;
    A[2].Row = 1; A[2].Col = 0; A[2].Val = 2;
    A[3].Row = 2; A[3].Col = 2; A[3].Val = 4;
    A[4].Row = 3; A[4].Col = 1; A[4].Val = 7;


    // B //   0  1  2  3
    // 0 -> | 0  2  0  0 |
    // 1 -> | 0  0  3  0 |
    // 2 -> | 0  5  0  0 |

    B[0].Row = 3; B[0].Col = 4; B[0].Val = 5;

    B[1].Row = 0; B[1].Col = 1; B[1].Val = 2;
    B[2].Row = 1; B[2].Col = 2; B[2].Val = 3;
    B[3].Row = 2; B[3].Col = 1; B[3].Val = 5;



    // BT//   0  1  2
    // 0 -> | 0  0  0 |
    // 1 -> | 2  0  5 |
    // 2 -> | 0  3  0 |
    // 3 -> | 0  0  0 |

    matrix *mul = SparseMultiplication(A, B, m, n, &MulIndex);

    printf("Multiplication: \n");
    
    printMatrix(mul, MulIndex);

}

void printMatrix(matrix *X, int size){
    printf("Row   Column   Value\n");
    printf("%d      %d       %d\n\n", X[0].Row, X[0].Col, X[0].Val);
    for(int i = 1; i< size; i++){
        printf("%d      %d       %02d\n", X[i].Row, X[i].Col, X[i].Val);
    }
    printf("\n\n");
}



matrix *SparseMultiplication(matrix *A, matrix *B, int m, int n, int *Index) {
    matrix *Bt = FastTranspose(B, n);

    matrix *result = (matrix *)malloc(m * n * sizeof(matrix));
    result[0].Row = A[0].Row;  
    result[0].Col = Bt[0].Row; 
    result[0].Val = 0;         
    int k = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (A[i].Col == Bt[j].Row) {
                int product = A[i].Val * Bt[j].Val;
                int found = 0;

                for (int r = 1; r < k; r++) {
                    if (result[r].Row == A[i].Row && result[r].Col == Bt[j].Col) {
                        result[r].Val += product;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    result[k].Row = A[i].Row;
                    result[k].Col = Bt[j].Col;
                    result[k].Val = product;
                    k++;
                }
            }
        }
    }

    result[0].Val = k;
    *Index = k;

    free(Bt);

    return result;
}



matrix *FastTranspose(matrix *B, int n){
    matrix *Bt = (matrix*)malloc(n * sizeof(matrix));
    Bt[0].Row = B[0].Col;
    Bt[0].Col = B[0].Row;
    Bt[0].Val = B[0].Val;

    int C = B[0].Col;
    int counter[C], PosBt[C];

    for (int i = 0; i < C; i++) {
        counter[i] = 0;
        PosBt[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        counter[B[i].Col]++;
    }

    PosBt[0] = 1;  // Start from 1 since Bt[0] contains dimensions
    for (int i = 1; i < C; i++) {
        PosBt[i] = PosBt[i - 1] + counter[i - 1];
    }

    for (int i = 1; i < n; i++) {  // Corrected loop boundary
        int pos = PosBt[B[i].Col]++;
        Bt[pos].Row = B[i].Col;
        Bt[pos].Col = B[i].Row;
        Bt[pos].Val = B[i].Val;
    }

    return Bt;
}
