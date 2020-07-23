// Author: xhdhr10000
// Date: 2020-04-08

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0;
        for (int i=0; i<=max && i<nums.size(); i++)  max = std::max(max, i + nums[i]);
        return max >= nums.size() - 1;
    }
};
