// Author: xhdhr10000
// Date: 2019-05-20
#include <time.h>

int findIn(int *nums, int x, int y, int k) {
    int i = rand() % (y-x+1) + x, j, c, d = nums[i];
    nums[i] = nums[y];
    for (i=x-1, j=x; j<y; j++) {
        if (nums[j]<=d) {
            i++;
            c = nums[i]; nums[i] = nums[j]; nums[j] = c;
        }
    }
    if (i < y) {
        i++;
        nums[y] = nums[i];
        nums[i] = d;
    }
    if (i == k) return d;
    if (i > k) return findIn(nums, x, i-1, k);
    return findIn(nums, i+1, y, k);
}

int findKthLargest(int* nums, int numsSize, int k){
    srand(clock());
    return findIn(nums, 0, numsSize-1, numsSize-k);
}



