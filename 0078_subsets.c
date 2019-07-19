// Author: xhdhr10000
// Date: 2019-06-05
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 1 << numsSize;
    int **ret = (int**)malloc(sizeof(int*)*(*returnSize));
    int *index = (int*)malloc(sizeof(int)*(*returnSize));
    int p = 1, i;
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    ret[0] = NULL;
    (*returnColumnSizes)[0] = 0;
    for (int l=1; l<=numsSize; l++) {
        index[0] = 0;
        i = 0;
        while (index[0] < numsSize - l + 1) {
            while (i+1 < l) {
                i++;
                index[i] = index[i-1] + 1;
            }
            ret[p] = (int*)malloc(sizeof(int)*l);
            (*returnColumnSizes)[p] = l;
            for (int j=0; j<=i; j++) ret[p][j] = nums[index[j]];
            p++;
            index[i]++;
            while (i > 0 && index[i] >= numsSize - l + i + 1) {
                i--;
                index[i]++;
            }
        }
    }
    free(index);
    return ret;
}



