// Author: xhdhr10000
// Date: 2020-04-23

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for (int i=0; i<nums.size()-count; i++) {
            nums[i] = nums[i+count];
            if (nums[i] == 0) { count++; i--; }
        }
        for (int i=nums.size()-count; i<nums.size(); i++) nums[i] = 0;
    }
};
