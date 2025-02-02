#include<stdio.h>


int BinarySearch(int * nums, int target, int start, int end){
    if (start > end) {
        return end+1;
    }

    int middle = (start + end)/2;
    if(nums[middle] == target){
        return middle;
    }else if(nums[middle] > target){
        return BinarySearch(nums, target, start, middle-1);
    }else{
        return BinarySearch(nums, target, middle+1, end);
    }
}

int searchInsert(int* nums, int numsSize, int target) {
    return BinarySearch(nums,target,0,numsSize-1);
}