// Author: xhdhr10000
// Date: 2019-04-29
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ret = (int*)malloc(sizeof(int)*2);
    int *hash = NULL;
    int min = 0x7fff, max = -0x7fff, i;
    *returnSize = 2;
    for (i=0; i<numsSize; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }
    hash = malloc(sizeof(int)*(max-min+1));
    memset(hash, 0, sizeof(int)*(max-min+1));
    for (i=0; i<numsSize; i++) {
        if (target-nums[i] >= min && target-nums[i] <= max && hash[target-nums[i]-min] != 0) {
            ret[1] = i;
            ret[0] = hash[target-nums[i]-min] - 1;
            free(hash);
            return ret;
        }
        hash[nums[i]-min] = i+1;
    }
    free(hash);
    return ret;
}
