// Author: xhdhr10000
// Date: 2020-04-27

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int j, k;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == i+1) continue;
            j = nums[i];
            nums[i] = 0;
            while (j > 0 && j <= nums.size() && nums[j-1] != j) {
                k = nums[j-1];
                nums[j-1] = j;
                j = k;
            }
        }
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != i+1) return i+1;
        }
        return nums.size()+1;
    }
};
