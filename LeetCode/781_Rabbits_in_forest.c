#include<stdio.h>



void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int pivot(int *arr, int left, int right){
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


int numRabbits(int* answers, int answersSize) {
    quickSort(answers, 0, answersSize-1);
    int rabbits = 0;
    for(int i = 0; i<answersSize; i++){
        int num = answers[i];
        int num_index = i;
        for(int j = i; (j < answersSize-1 && j < num + num_index) && answers[j] == answers[j+1]; j++){
            i++;
        }
        rabbits += num + 1;
    }
    return rabbits;
}



int main(){
    int arr[] = {1,2,6,5,0,5,7,0,6,7};
    int n = sizeof(arr)/ sizeof(arr[0]);

    printf("%d\n", numRabbits(arr, n));

    return 0;
}