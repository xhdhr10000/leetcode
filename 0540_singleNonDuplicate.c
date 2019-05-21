// Author: xhdhr10000
// Date: 2019-05-07

int findSingle(int *nums, int x, int y) {
    int z = (x+y)/2;
    if (z > x && nums[z] == nums[z-1]) {
        if ((z-x+1)%2) return findSingle(nums, x, z-2);
        return findSingle(nums, z+1, y);
    } else if (z < y && nums[z] == nums[z+1]) {
        if ((y-z+1)%2) return findSingle(nums, z+2, y);
        return findSingle(nums, x, z-1);
    } else return nums[z];
}

int singleNonDuplicate(int* nums, int numsSize){
    return findSingle(nums, 0, numsSize-1);
}



