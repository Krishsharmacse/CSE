#include<stdio.h>

void swap(int Arr[], int x, int y);
void HeapSort(int Arr[], int n);
void buildHeap(int Arr[], int n);
void Heapify(int Arr[], int n, int i);

int main(){
    int Arr[] = {5,20,6,8,1,0,3};
    int n = sizeof(Arr) / sizeof(Arr[0]) ;
    HeapSort(Arr, n);
    for(int i = 0; i < n; i++){
        printf("%d ", Arr[i]);
    }
    
}

void swap(int Arr[], int x, int y){
    int temp = Arr[y];
    Arr[y] = Arr[x];
    Arr[x] = temp;
}

void Heapify(int Arr[], int n, int i){
    int l,r,max;

    l = 2*i+1;
    r = 2*i+2;
    max = i;
    if(l<n && Arr[l] > Arr[max]){
        max = l;
    }
    if(r<n && Arr[r] > Arr[max]){
        max = r;
    }
    if( max != i){
        swap(Arr, i, max);
        Heapify(Arr, n, max);
    }
}

void buildHeap(int Arr[], int n){
    for(int i = n/2; i >= 0; i--){
        Heapify(Arr, n, i);
    }
}

void HeapSort(int Arr[], int n){
    buildHeap(Arr, n);
    for(int i = n-1; i>=0; i--){
        swap(Arr, 0, i);
        Heapify(Arr, i, 0);
    }
}