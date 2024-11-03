#include<stdio.h>


int BS(int *nums, int target, int left, int right){
     int middle = (left + right) / 2;
    if(left > right){
        return -1;
    }

    if (nums[middle] == target) {
        return middle;
    }

    if (nums[left] <= nums[middle]) {
        if (target >= nums[left] && target < nums[middle]) {
            return BS(nums, target, left, middle - 1);
        } else {
            return BS(nums, target, middle + 1, right);
        }
    }
    else {
        if (target > nums[middle] && target <= nums[right]) {
            return BS(nums, target, middle + 1, right);
        } else {
            return BS(nums, target, left, middle - 1);
        }
    }
}


int search(int* nums, int numsSize, int target) {
    return BS(nums, target, 0, numsSize-1);
}


int main(){
    int a[] = {4,5,6,7,0,1,2};
    int target = 2;

    printf("%d", search(a, 7, target));
}