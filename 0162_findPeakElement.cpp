// Author: xhdhr10000
// Date: 2020-04-01

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[nums.size()-1] > nums[nums.size()-2]) return nums.size()-1;
        return findPeakWithin(nums, 1, nums.size()-2);
    }
private:
    int findPeakWithin(vector<int>& nums, int x, int y) {
        int c = (x + y) >> 1;
        if (nums[c] > nums[c-1] && nums[c] > nums[c+1]) return c;
        if (nums[c] < nums[c+1]) return findPeakWithin(nums, c+1, y);
        return findPeakWithin(nums, x, c-1);
    }
};
