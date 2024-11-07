#include<stdio.h>

void mergeSort(int arr[], int i, int j);
void merge(int arr[], int i, int mid, int j);
void printArray(int *a, int n);


int main(){
    int a[] = {5,9,1,7,0,3,5,9};
    int n = sizeof(a) / sizeof(a[0]) ;

    printf("unsorted array: ");
    printArray(a,n);

    printf("sorted array:   ");
    mergeSort(a, 0, n-1);
    printArray(a,n);    
}


void merge(int arr[], int i, int mid, int j){
    int mergedArray[j-i+1];
    int Index=0;
    int x = i, y = mid+1;

    while(x <=mid && y <= j){
        if(arr[x] <= arr[y]){
            mergedArray[Index] = arr[x];
            x++;
        } else{
            mergedArray[Index] = arr[y];
            y++; 
        }
        Index++;
    }

    while(x<=mid){
        mergedArray[Index] = arr[x];
        Index++;
        x++;
    }

    while(y<=j){
        mergedArray[Index] = arr[y];
        Index++;
        y++; 
    }

     for (int k = 0; k < Index; k++) {
        arr[i + k] = mergedArray[k];
    }
 
}


void mergeSort(int arr[], int i, int j){
    if(i>=j){
        return;
    }

    int mid = i + (j-i)/2;

    mergeSort(arr, i, mid);
    mergeSort(arr, mid+1, j);

    merge(arr, i, mid, j);
}


void printArray(int *a, int n){
    for(int i = 0; i < n-1 ; i++){
        printf("%d, ", a[i]);
    }
    printf("%d\n", a[n-1]);
}

