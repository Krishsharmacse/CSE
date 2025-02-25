#include<stdio.h>



int Sum(int *arr, int i, int Size){
    if(i == Size) return arr[i];
    int sum = 0;
    for(int k = i; k<=Size; k++){
        sum+=arr[k];
    }
    return sum;
}


int numOfSubarrays(int* arr, int arrSize) {
    int count = 0;
    for(int i=0; i< arrSize; i++){
        for(int j = arrSize-1; j >= i; j--){
            int sum = Sum(arr, i, j);
            if(sum % 2) count++; 
        }
    }
    return count;
}


int main(){
    int arr[] = {1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", numOfSubarrays(arr, n));

}