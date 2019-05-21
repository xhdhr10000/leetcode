// Author: xhdhr10000
// Date: 2019-05-14
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int deleteAndEarn(int* nums, int numsSize){
    int val[10001], sum[10001], max = 0;
    
    memset(val, 0, sizeof(val));
    for (int i=0; i<numsSize; i++) {
        val[nums[i]] += nums[i];
        max = MAX(max, nums[i]);
    }
    sum[0] = 0;
    sum[1] = val[1];
    for (int i=2; i<=max; i++) {
        sum[i] = MAX(sum[i-1], sum[i-2]+val[i]);
    }
    return sum[max];
}



