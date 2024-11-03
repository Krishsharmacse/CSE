#include<stdio.h>

int BinarySearch(int * nums, int target, int start, int end){
    if (start > end) {
        return -1;
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

int main(){
    int nums[] = {5,5,7,7,7,7,8,10};
    int target = 7;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int index = BinarySearch(nums, target, 0, numsSize-1); 

    printf("%d\n", index);
    int temp = index, start = index;
    while(temp != -1){
        start = temp;
        temp = BinarySearch(nums, target, 0, start);
        nums[temp] = -1;
    }
    printf("%d\n", start);
    
    temp = index;
    int end = index;
    while(temp != -1){
        end = temp;
        temp = BinarySearch(nums, target, end, numsSize-1);
        nums[temp] = -1;
    }
    printf("%d\n", end);

}