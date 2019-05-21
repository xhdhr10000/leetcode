// Author: xhdhr10000
// Date: 2019-05-16
int removeDuplicates(int* nums, int numsSize){
    int p = 0;
    for (int i=1; i<numsSize; i++) {
        if (nums[i] == nums[p]) continue;
        nums[++p] = nums[i];
    }
    return numsSize==0 ? 0 : p+1;
}



