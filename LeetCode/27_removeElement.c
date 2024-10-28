int removeElement(int* nums, int numsSize, int val) {
    if(numsSize <= 0){
        return 0;
    }
    int res[numsSize];
    int index = 0, i = 0;
    while(i < numsSize){
        if(nums[i] != val){
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