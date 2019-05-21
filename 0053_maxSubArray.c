// Author: xhdhr10000
// Date: 2019-05-20
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int maxSubArray(int* nums, int numsSize){
    int max = numsSize>0 ? nums[0] : -0x80000000;
    for (int i=1; i<numsSize; i++) {
        nums[i] = MAX(nums[i], nums[i] + nums[i-1]);
        max = MAX(max, nums[i]);
    }
    return max;
}



