// Author: xhdhr10000
// Date: 2019-07-20
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int find(int *nums, int x, int y, int n, bool equal) {
    int i = (x+y)/2;
    if (x > y) y = x;
    if (x == y) return n < nums[x] || equal && n == nums[x] ? x : x+1;
    if (n < nums[i] || equal && n == nums[i]) return find(nums, x, i-1, n, equal);
    return find(nums, i+1, y, n, equal);
}

int findUnsortedSubarray(int* nums, int numsSize){
    int s = numsSize-1, t = 0;
    for (int i=0; i<numsSize; i++) {
        if (i>0 && nums[i] < nums[MIN(i-1, s)]) s = find(nums, 0, MIN(i-1, s), nums[i], false);
        if (i<numsSize-1 && nums[i] > nums[MAX(i+1, t)]) t = find(nums, MAX(i+1, t), numsSize-1, nums[i], true) - 1;
    }
    return s==t ? 0 : MAX(0, t-s+1);
}
