#include <stdio.h>

void swap(int* arr, int i, int j);
int pivot(int *arr, int left, int right);
void quickSort(int *arr, int left, int right);
void printArray(int arr[], int size);


int main() {
    int arr[] = {4,3,7,2,1,9};
    // int arr[] = {23, 7, 15, 42, 9, 11, 3, 27, 19, 34, 56, 12, 8, 6, 14, 25, 37, 2, 30, 17};
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

int pivot(int *arr, int left, int right){
    // int pivot = arr[left];
    // int i = left + 1;
    
    // for (int j = left + 1; j <= right; j++) {
    //     if (arr[j] < pivot) {
    //         swap(arr, i, j);
    //         i++;
    //     }
    // }
    
    // swap(arr, left, i - 1);
    
    // return i - 1;

    int pivotIndex = left;
    int swapIndex = pivotIndex;

    for(int i = pivotIndex + 1; i<= right ; i++){
        if(arr[i] < arr[pivotIndex]){
            swapIndex++;
            swap(arr, swapIndex , i);
        }
    }

    swap(arr, swapIndex, pivotIndex);
    return swapIndex;
}

void quickSort(int *arr, int left, int right){
    if(left < right){
        int index = pivot(arr, left, right);
        printf("pivot = %d", index);
        printf("\n");
        quickSort(arr, left, index-1);
        quickSort(arr,index+1, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}