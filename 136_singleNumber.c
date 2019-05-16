// Author: xhdhr10000
// Date: 2019-05-12
int singleNumber(int* nums, int numsSize){
    int ret = 0;
    for (int i=0; i<numsSize; i++) ret ^= nums[i];
    return ret;
}



