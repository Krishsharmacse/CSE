#include<stdio.h>
#include<stdlib.h>

struct sparsePol{
    int coeff;
    int exp;
};

struct sparsePol* sparseAddition(struct sparsePol *PolA, struct sparsePol *PolB, int m, int n, int *Index){
   struct sparsePol *sum = (struct sparsePol*)malloc((m+n)*sizeof(struct sparsePol));
    int i=0,j=0;

    while(i<m && j<n){
        if(PolA[i].exp == PolB[j].exp){
            sum[*Index].exp = PolA[i].exp;
            sum[*Index].coeff = PolA[i].coeff + PolB[j].coeff;
            i++;j++;
        } else if(PolA[i].exp < PolB[j].exp){
            sum[*Index] = PolB[j];
            j++;
        } else{
            sum[*Index] = PolA[i];
            i++;
        }
        (*Index)++;
    }

    while (i<m) {
        sum[*Index] = PolA[i];
        i++;
        (*Index)++;
    }

    while (j<n) {
        sum[*Index] = PolB[j];
        j++;
        (*Index)++;
    }
    

    return sum;
}



struct sparsePol* multiply(struct sparsePol *PolA, struct sparsePol *PolB, int m, int n,  int *resSize){
    struct sparsePol *tempRes = (struct sparsePol*)malloc((m*n) * sizeof(struct sparsePol));
    int Index=0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int exp = PolA[i].exp + PolB[j].exp;
            int coeff = PolA[i].coeff * PolB[j].coeff;
            tempRes[Index].exp = exp;
            tempRes[Index].coeff = coeff;
            Index++;
        }
    }

    // simplification
    struct sparsePol *res = (struct sparsePol*)malloc((Index) * sizeof(struct sparsePol));
    int newIndex = 0;
    for (int i = 0; i < Index; i++) {
        int found = 0;
        for (int j = 0; j < newIndex; j++) {
            if (res[j].exp == tempRes[i].exp) {
                res[j].coeff += tempRes[i].coeff;
                found = 1;
                break; 
            }
        }
        if (!found) {
            res[newIndex] = tempRes[i];
            newIndex++;
        }
    }
    free(tempRes); 

    *resSize = newIndex;

    return res;
}




int main(){

    int m = 3,n=4;
    int additionIndex=0, MulIndex = 0;
    
    struct sparsePol PolA[m], PolB[n]; 

// ---------------------------------------
    // Initialize PolA: 7x^99 + 5x^2 +1
    PolA[0].coeff=1; PolA[0].exp= 7;
    PolA[1].coeff=6; PolA[1].exp=1; 
    PolA[2].coeff=1; PolA[2].exp=0; 

// ---------------------------------------

    // Initialize PolB: 2x^100 + 3x^99 + 9x^2 + 2
    PolB[0].coeff = 2; PolB[0].exp = 100;
    PolB[1].coeff = 3; PolB[1].exp = 99;
    PolB[2].coeff = 6; PolB[2].exp = 45;    
    PolB[3].coeff = 8; PolB[3].exp = 0;
// -------------------------------------------

    struct sparsePol *sum = sparseAddition(PolA, PolB, m, n, &additionIndex);

    printf("Addition: \n");
    for(int i=0;i < additionIndex-1;i++){
        printf("%d^%d + ", sum[i].coeff, sum[i].exp);
    }
    printf(" %d^%d \n\n", sum[additionIndex-1].coeff, sum[additionIndex-1].exp);



    struct sparsePol *Multiplication = multiply(PolA, PolB, m, n, &MulIndex);    
   
    printf("\nMultiplication: \n");
    for(int i=0; i<MulIndex-1;i++){
        printf(" %d^%d + ", Multiplication[i].coeff, Multiplication[i].exp);
    }
    printf(" %d^%d\n\n", Multiplication[MulIndex-1].coeff, Multiplication[MulIndex-1].exp);

    free(sum);
    free(Multiplication);

    return 0;
}