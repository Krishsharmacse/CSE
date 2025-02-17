#include<stdio.h>


void swap(int i, int j, int *Arr){
    int temp = Arr[i];
    Arr[i] = Arr[j];
    Arr[j] = temp;
}

void BubbleSort(int *Arr, int size){
    for(int i = size-1; i > 0; i--){
        int flag = 0;
        for(int j = 0; j < i; j++){
            if(Arr[j] > Arr[j+1]){
                flag = 1;
                swap(j, j+1, Arr);
            }
        }
        if(!flag) break;
    }
}

void PrintArray(int * Arr, int size){
    for(int i= 0; i< size; i++){
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

int main(){
    int Arr[] = {5,10,2,4,9,5,8,11,2,3};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    BubbleSort(Arr, size);
    PrintArray(Arr, size);
    return 0;
}