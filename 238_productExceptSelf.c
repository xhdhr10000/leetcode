// Author: xhdhr10000
// Date: 2019-05-14
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *ret = (int*)malloc(sizeof(int)*numsSize);
    
    int c = 1;
    for (int i=0; i<numsSize; i++) {
        ret[i] = c;
        c *= nums[i];
    }
    
    c = 1;
    for (int i=numsSize-1; i>=0; i--) {
        ret[i] *= c;
        c *= nums[i];
    }
    
    *returnSize = numsSize;
    return ret;
}



