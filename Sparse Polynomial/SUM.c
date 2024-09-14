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

int main(){

    int m = 9,n=4;
    int Index=0;
    
    struct sparsePol PolA[m], PolB[n]; 

// ---------------------------------------
    // Initialize PolA: 7x^99 + 5x^2 +1
    PolA[0].coeff = 7;  PolA[0].exp = 99;
    PolA[1].coeff = 5;  PolA[1].exp = 50;
    PolA[2].coeff = 1;  PolA[2].exp = 60;
    PolA[3].coeff = 9;  PolA[3].exp = 30;       
    PolA[4].coeff = 23; PolA[4].exp = 15;
    PolA[5].coeff = 12; PolA[5].exp = 10;
    PolA[6].coeff = 32; PolA[6].exp = 7;
    PolA[7].coeff = 22; PolA[7].exp = 6;
    PolA[8].coeff = 21; PolA[8].exp = 0;

// ---------------------------------------

    // Initialize PolB: 2x^100 + 3x^99 + 9x^2 + 2
    PolB[0].coeff = 2; PolB[0].exp = 100;
    PolB[1].coeff = 3; PolB[1].exp = 99;
    PolB[2].coeff = 6; PolB[2].exp = 45;    
    PolB[3].coeff = 8; PolB[3].exp = 0;
// -------------------------------------------

    struct sparsePol *sum = sparseAddition(PolA, PolB, m, n, &Index);

    // printf("%d", Index);

    for(int i=0;i<Index;i++){
        printf("%d   %d\n", sum[i].coeff, sum[i].exp);
    }

    return 0;
}