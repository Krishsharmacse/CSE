#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
void swap(int* arr, int i, int j);
void printArray(int arr[], int size);
int getRandom(int min, int max);
int* GenArr(int size);
//HeapSort
void MaxHeapSort(int Arr[], int n);
void MinHeapSort(int Arr[], int n);
void MaxHeapify(int Arr[], int n, int i);
void MinHeapify(int Arr[], int n, int i);
void buildMaxHeap(int Arr[], int n);
void buildMinHeap(int Arr[], int n);
int main(){
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);
    srand(time(0));
    int Sizes[] = {100, 1000, 10000, 100000, 1000000};
    int n = sizeof(Sizes)/sizeof(Sizes[0]);
    printf("------------------------------------------------------------------------------\n");
    printf("Max Heap sort: \n");
    printf("Input size \t   time taken\n");
    printf("-----------------------------------\n");
    for(int i=0; i<n; i++){
        int size = Sizes[i];
        int *Arr = GenArr(size);
        QueryPerformanceCounter(&start);
        MaxHeapSort(Arr, size);
        QueryPerformanceCounter(&end);
        double time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;
        printf("%-18d  %-5.2lf ns\n", size, time_taken);
        free(Arr);
    }
    printf("------------------------------------------------------------------------------\n");
    printf("Min Heap sort: \n");
    printf("Input size \t   time taken\n");
    printf("-----------------------------------\n");
    for(int i=0; i<n; i++){
        int size = Sizes[i];
        int *Arr = GenArr(size);
        QueryPerformanceCounter(&start);
        MinHeapSort(Arr, size);
        QueryPerformanceCounter(&end);
        double time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / freq.QuadPart;
        printf("%-18d  %-5.2lf ns\n", size, time_taken);
        free(Arr);
    }
}
/*************************************************************************/
/*                      Max Heap Sort (using Max Heap)                   */
/*************************************************************************/
void MaxHeapify(int Arr[], int n, int i){
    int l = 2*i+1, r = 2*i+2, max = i;
    if(l<n && Arr[l] > Arr[max]) max = l;
    if(r<n && Arr[r] > Arr[max]) max = r;
    if( max != i){
        swap(Arr, i, max);
        MaxHeapify(Arr, n, max);
    }
}
 
void buildMaxHeap(int Arr[], int n){
    for(int i = n/2; i >= 0; i--)
        MaxHeapify(Arr, n, i);
}
void MaxHeapSort(int Arr[], int n){
    buildMaxHeap(Arr, n);
    for(int i = n-1; i>=0; i--){
        swap(Arr, 0, i);
        MaxHeapify(Arr, i, 0);
    }
}
/*************************************************************************/
/*                        Min Heap Sort (using Max Heap)                 */
/*************************************************************************/
void MinHeapify(int Arr[], int n, int i){
    int l = 2*i+1,  r = 2*i+2, min = i;
    if(l<n && Arr[l] < Arr[min]) min = l;
    if(r<n && Arr[r] < Arr[min]) min = r;
    if(min != i){
        swap(Arr, i, min);
        MinHeapify(Arr, n, min);
    }
}
void buildMinHeap(int Arr[], int n){
    for(int i = n/2; i >= 0; i--)
        MinHeapify(Arr, n, i);
}
void MinHeapSort(int Arr[], int n){
    buildMinHeap(Arr, n);
    for(int i = n-1; i>=0; i--){
        swap(Arr, 0, i);
        MinHeapify(Arr, i, 0);
    }
}
/*************************************************************************/
/*                             Helper Functions                          */
/*************************************************************************/
void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int getRandom(int min, int max){return min + rand()%(max-min + 1); }
int* GenArr(int size){
    int min = 1, max = 999;
    int* Arr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        Arr[i] = getRandom(min, max);
    return Arr;
}
