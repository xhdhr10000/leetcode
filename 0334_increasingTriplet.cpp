// Author: xhdhr10000
// Date: 2020-04-17

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for (int i : nums) {
            if (i > m1 && i > m2) return true;
            if (i < m1) m1 = i;
            else if (i > m1 && i < m2) m2 = i;
        }
        return false;
    }
};
