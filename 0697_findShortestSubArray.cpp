// Author: xhdhr10000
// Date: 2020-01-29

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        std::map<int, std::pair<int, std::pair<int, int>>> m;
        int d = 0, ans = 0;

        for (int i=0; i<nums.size(); i++) {
            int n = nums[i];
            auto it = m.find(n);
            if (it == m.end()) {
                m[n] = std::pair(1, std::pair(i, i));
            } else {
                auto &e = it->second;
                e.first++;
                e.second.second = i;
                if (e.first > d || e.first == d && e.second.second - e.second.first < ans) {
                    d = e.first;
                    ans = e.second.second - e.second.first;
                }
            }
        }

        return ans+1;
    }
};
