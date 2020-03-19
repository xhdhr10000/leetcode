// Author: xhdhr10000
// Date: 2020-01-25

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ret = 0;
        std::map<int, int> map;

        for (int i : arr) {
            auto e = map.find(i-difference);
            map[i] = e != map.end() ? e->second+1 : 1;
            if (map[i] > ret) ret = map[i];
        }

        return ret;
    }
};
