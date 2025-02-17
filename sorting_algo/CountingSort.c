#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int getMax(int *Arr, int size){
    int max = Arr[0]; 
    for(int i= 1; i < size; i++){
        if(max < Arr[i]) max = Arr[i];
    }

    return max;
}



void CountSort(int *Arr, int size){
    int max = getMax(Arr, size);

    int *count = (int*)calloc(max + 1, sizeof(int));
    if(count == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    
    for(int i=0; i < size; i++){
        count[Arr[i]]++;
    }
    
    for(int i=1; i <= max; i++){
        count[i] += count[i-1];
    }

    int *output = (int*)calloc(size, sizeof(int));
    if(output == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    for(int i = size-1; i >= 0; i--){
        output[--count[Arr[i]]] = Arr[i];
    }

    for(int i = 0; i < size; i++){
        Arr[i] = output[i];
    }

    free(count);
    free(output);
}






int main(){
    int Arr[] = {5,8,2,1,7,2,5};
    int size = sizeof(Arr) / sizeof(Arr[0]); 

    printf("Original array: ");
    printArray(Arr, size);

    CountSort(Arr, size);

    printf("Sorted array: ");
    printArray(Arr, size);


    return 0;
}