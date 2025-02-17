#include<stdio.h>


void swap(int i, int j, int *Arr){
    int temp = Arr[i];
    Arr[i] = Arr[j];
    Arr[j] = temp;
}

void SelectionSort(int *Arr, int size){
    for(int i = 0; i < size; i++){
        int minIndex = i;
        for(int j = i+1; j<size; j++){
            if(Arr[j] < Arr[minIndex]) minIndex = j;
        }
        if(minIndex != i) swap(i, minIndex, Arr);
    }
}

void PrintArray(int * Arr, int size){
    for(int i= 0; i< size; i++){
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

int main(){
    int Arr[] = {5,12,2,4,9,5};
    int size = sizeof(Arr) / sizeof(Arr[0]);
    SelectionSort(Arr, size);
    PrintArray(Arr, size);

    return 0;
}