// Author: xhdhr10000
// Date: 2019-07-19
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int *stack = (int*)malloc(sizeof(int)*numsSize);
    bool *hash = (bool*)malloc(sizeof(bool)*numsSize);
    int size = 1, p = 0, c = 0, i;
    
    for (i=2; i<=numsSize; i++) size *= i;
    int **ret = (int**)malloc(sizeof(int*)*size);
    
    *returnSize = size;
    *returnColumnSizes = (int*)malloc(sizeof(int)*size);
    for (i=0; i<size; i++) (*returnColumnSizes)[i] = numsSize;
    size = 0;
    
    memset(hash, 0, sizeof(bool)*numsSize);
    while (true) {
        for (i=c; i<numsSize; i++) {
            if (!hash[i]) {
                hash[i] = true;
                stack[p] = i;
                if (p == numsSize-1) {
                    /* Find an answer */
                    ret[size] = (int*)malloc(sizeof(int)*numsSize);
                    for (int j=0; j<numsSize; j++) ret[size][j] = nums[stack[j]];
                    size++;
                }
                break;
            }
        }
        if (p == numsSize-1 || i == numsSize) {
            hash[stack[p]] = false;
            p--;
            if (p < 0) break;
            hash[stack[p]] = false;
            c = stack[p]+1;
        } else {
            p++;
            c = 0;
        }
    }
    free(hash);
    free(stack);
    return ret;
}
