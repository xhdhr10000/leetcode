// Author: xhdhr10000
// Date: 2020-03-19

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] < target) i++;
            else if (numbers[i] + numbers[j] > target) j--;
            else break;
        }
        vector<int> ret = { i+1, j+1 };
        return ret;
    }
};
