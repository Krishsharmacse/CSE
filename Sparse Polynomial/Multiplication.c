#include<stdio.h>
#include<stdlib.h>

struct sparsePol{
    int exp;
    int coeff;
};

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
    int m=3,n=4;
    int Index=0;
    struct sparsePol PolA[m], PolB[n];

    PolA[0].exp= 7;
    PolA[0].coeff=1;

    PolA[1].exp=1;
    PolA[1].coeff=6;
    
    PolA[2].exp=0;
    PolA[2].coeff=1;
    
// ------------------------------------

    PolB[0].exp= 7;
    PolB[0].coeff=1;

    PolB[1].exp=3;
    PolB[1].coeff=7;

    PolB[2].exp=1;
    PolB[2].coeff=2;

    PolB[3].exp=0;
    PolB[3].coeff=1;


    struct sparsePol *res = multiply(PolA, PolB, m, n, &Index);
    
   
    for(int i=0; i<Index;i++){
        printf(" %d %d", res[i].coeff, res[i].exp);
        printf("\n");
    }

    free(res);

    return 0;
}