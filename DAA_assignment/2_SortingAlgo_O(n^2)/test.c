
#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void InsertionSort(int *Arr, int size){
    for(int i = 1; i< size; i++){
        int val = Arr[i];
        int j = i - 1;
        while(j > -1 && val < Arr[j]){
            Arr[j+1] = Arr[j];
            printArray(Arr, size);
            j--;
        }   
        Arr[++j] = val;
    }
}


int main() {
    int arr[] = {5, 8, 2, 1, 7};
    // int arr[] = {23, 7, 15, 42, 9, 11, 3, 27, 19, 34, 56, 12, 8, 6, 14, 25, 37, 2, 30, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array : ");
    printArray(arr, n);
    
    InsertionSort(arr, n);

    printf("sorted array :   ");
    printArray(arr, n);
    return 0;
}








