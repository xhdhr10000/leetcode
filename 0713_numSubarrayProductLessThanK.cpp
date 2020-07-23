// Author: xhdhr10000
// Date: 2020-07-23

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ret = 0, i = 0, j = 0, p;
        for (j=0; j<nums.size(); j++) {
            if (i == j) p = nums[j];
            else p *= nums[j];
            while (p >= k && i <= j) p /= nums[i++];
            ret += j-i+1;
        }
        return ret;
    }
};
