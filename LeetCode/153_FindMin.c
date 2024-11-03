#include<stdio.h>

int BS(int *num, int left, int right){
    int middle = (left + right) / 2;
    if(left >= right){
        return num[middle];
    }
    int x = num[middle];
    int y = num[right];
    if(x > y){
        return BS(num, middle+1, right);
    }
    else{
        return BS(num, left, middle);
    }
}

int findMin(int* nums, int numsSize) {
    return BS(nums, 0, numsSize-1);
}

int main(){
    int a[] = {2,4,5,6,7,0,1};
    printf("%d", findMin(a, 7));
}