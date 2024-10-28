#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int res[numsSize];
    res[0] = nums[0];
    int index = 1, i = 1;
    while(i < numsSize){
        if(res[index-1] != nums[i]){
            res[index] = nums[i];
            index++;
        }
        i++; 
    }

    for(int j = 0; j < index; j++){
        nums[j] = res[j];
    }

    return index;
}


int main(){
    int num[] = {1,1,2};
    printf("\n%d", removeDuplicates(num, 3));
}