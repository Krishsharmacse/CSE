#include <stdio.h>


void swap(int* arr, int i, int j);
int pivot(int *arr, int pivotIndex, int endIndex);
void quickSort(int *arr, int left, int right);
void printArray(int arr[], int size);


int main() {
    int arr[] = {4,6,1,7,3,2,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array : ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);

    printf("sorted array :   ");
    printArray(arr, n);
    return 0;
}


void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int pivot(int *arr, int pivotIndex, int endIndex){
    int swapIndex = pivotIndex;
    for(int i = pivotIndex+1; i<= endIndex; i++){
        if(arr[i] < arr[pivotIndex]){
            swapIndex++;
            swap(arr, swapIndex, i);
        }
    }

    swap(arr, pivotIndex, swapIndex);
    return swapIndex;
}

void quickSort(int *arr, int left, int right){
    if(left < right){
        int index = pivot(arr, left, right);
        quickSort(arr, left, index -1);
        quickSort(arr,index + 1, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
