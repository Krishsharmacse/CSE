#include<stdio.h>


int getMax(int *Arr, int size){
    int max = Arr[0];
    for(int i=0; i<size; i++){
        if(max < Arr[i]) max = Arr[i];
    }
    return max;
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void R_CountSort(int *Arr, int size, int exp){
    int count[10];
    for (int i = 0; i < 10; i++) {
        count[i] = 0;
    }
    
    for(int i=0; i < size; i++){
        count[((Arr[i] / exp) % 10 )]++;
    }
     
    for(int i=1; i < 10; i++){
        count[i] += count[i-1];
    }

    int output[size];
    for(int i = size-1; i >= 0; i--){
        output[--count[((Arr[i] / exp) % 10 )]] = Arr[i];
    }

    for(int i = 0; i < size; i++){
        Arr[i] = output[i];
    }
}

void RadixSort(int *Arr, int size){
    int max = getMax(Arr, size);
    for(int exp = 1; max / exp > 0; exp*=10){
        R_CountSort(Arr, size, exp);
        // printArray(Arr, size);
    }

}



int main(){
    int Arr[] = {29,8,56,122,94,11,6};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    RadixSort(Arr, size);
    printArray(Arr, size);

}