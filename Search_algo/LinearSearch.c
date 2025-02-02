#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


int LinearSearch(int target, int *Arr, int size){
    for(unsigned int i= 0; i<size; i++){
        if(Arr[i] == target) return i;
    }   
    return -1;
}

int *GenArr(int size){
    int *Arr = (int*)malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        Arr[i] = i; 
    }
    return Arr;
}

int main(){
    int Sizes[] = {100,1000,10000,100000,1000000};
    int n = sizeof(Sizes) / sizeof(Sizes[0]);

    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);

    printf("Linear Search:\n");
    printf("Input size \t   time taken\n");
    
    for(int i = 0; i< n; i++){

        int s = Sizes[i];
        int *Arr = GenArr(s);
        int target = s-1;

        QueryPerformanceCounter(&start);
        long int i = LinearSearch(target, Arr, s);
        QueryPerformanceCounter(&end);

        double time_taken = (double)(end.QuadPart - start.QuadPart) * 1e9 / frequency.QuadPart;
        printf("%d  %20.2lf ns\n", s, time_taken);

        free(Arr);
    }

}
