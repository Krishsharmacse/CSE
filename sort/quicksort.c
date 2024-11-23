// quickSort
#include <stdio.h>

void swap(int* arr, int i, int j);
int pivot(int *arr, int pivotIndex, int endIndex);
void quickSort(int *arr, int left, int right);
void printArray(int arr[], int size);


int main() {
    // int arr[] = {4,6,1,7,3,2,5};
    int arr[] = {1, 4, 7, 11, 15, 2, 5, 8, 12, 19, 3, 6, 9, 16, 22, 10, 13, 14, 17, 24, 18, 21, 23, 26, 30
};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array : ");
    // printArray(arr, n);
    
    printf("%d\n", n);

    quickSort(arr, 0, n - 1);
    // printf("%d\n", pivot(arr, 0, n));

    printf("size: %d\n", n);


    // printf("sorted array :   ");
    printArray(arr, n);
    return 0;
}


// void swap(int* arr, int i, int j) {
//     int temp = arr[i];
//     arr[i] = arr[j];
//     arr[j] = temp;
// }

// int pivot(int *arr, int pivotIndex, int endIndex){
//     int swapIndex = pivotIndex;
//     for(int i = pivotIndex+1; i < endIndex; i++){
//         int x = arr[i], y = arr[pivotIndex];
//         if(arr[i] < arr[pivotIndex]){
//             swapIndex++;
//             swap(arr, i, swapIndex);
//         }
//     }

//     swap(arr, pivotIndex, swapIndex);
//     return swapIndex;
// }

// void quickSort(int *arr, int left, int right){
//     if(left < right){
//         int index = pivot(arr, left, right);
//         quickSort(arr, left, index);
//         quickSort(arr,index + 1, right);
//     }
// }

void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr, int pivotIndex, int end){
    int swapIndex = pivotIndex;
    
    for(int i = pivotIndex + 1; i < end; i++){
        if(arr[i] < arr[pivotIndex]){
            swapIndex++;
            swap(arr, i, swapIndex);
        }
    }

    swap(arr, pivotIndex, swapIndex);
    return swapIndex;

}

void quickSort(int *arr, int start, int end){
    if(start >= end){
        return;
    }

    int pivot = partition(arr,start,end);
    quickSort(arr, start, pivot);
    quickSort(arr, pivot+1, end);
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

