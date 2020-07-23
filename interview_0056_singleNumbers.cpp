// Author: xhdhr10000
// Date: 2020-04-28

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        set<int> s;
        for (int i : nums) {
            auto it = s.find(i);
            if (it == s.end()) s.insert(i);
            else s.erase(it);
        }
        vector<int> ret(s.begin(), s.end());
        return ret;
    }
};
