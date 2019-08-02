// Author: xhdhr10000
// Date: 2019-08-01
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int *ret = (int*)malloc(sizeof(int)*(numsSize+1));
    memset(ret, 0, sizeof(int)*(numsSize+1));
    for (int i=0; i<numsSize; i++) ret[nums[i]]++;
    *returnSize = 0;
    for (int i=1; i<=numsSize; i++) {
        if (!ret[i]) ret[(*returnSize)++] = i;
    }
    return ret;
}
