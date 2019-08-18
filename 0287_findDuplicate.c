// Author: xhdhr10000
// Date: 2019-08-10
int findDuplicate(int* nums, int numsSize){
    int f = nums[0], s = nums[0];
    while (true) {
        f = nums[nums[f]];
        s = nums[s];
        if (f == s) break;
    }
    f = nums[0];
    while (f != s) {
        f = nums[f];
        s = nums[s];
    }
    return f;
}
