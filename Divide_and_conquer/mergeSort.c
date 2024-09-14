#include<stdio.h>

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
    
    printf("%d\n", mid);

    mergeSort(arr, i, mid);
    mergeSort(arr, mid+1, j);

    merge(arr, i, mid, j);
}


int main(){
    int a[6] = {5,2,4,1,8,0};
    mergeSort(a, 0, 6);

    for(int i = 0; i<6; i++){
        printf("%d", a[i]);
    }
}