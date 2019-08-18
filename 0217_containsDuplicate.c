// Author: xhdhr10000
// Date: 2019-05-20
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
bool containsDuplicate(int* nums, int numsSize){
    int min = 0x7fffffff, max = -0x80000000;
    if (numsSize == 0) return false;
    for (int i=0; i<numsSize; i++) {
        min = MIN(min, nums[i]);
        max = MAX(max, nums[i]);
    }
    int *hash = (int*)malloc(sizeof(int)*(max-min+1));
    memset(hash, 0, sizeof(int)*(max-min+1));
    for (int i=0; i<numsSize; i++) {
        if (hash[nums[i]-min]) return true;
        hash[nums[i]-min] = 1;
    }
    return false;
}
