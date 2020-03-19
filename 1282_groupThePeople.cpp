// Author: xhdhr10000
// Date 2020-01-25

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ret;
        vector<int> hash[501];
        for (int i=0; i<groupSizes.size(); i++) {
            hash[groupSizes[i]].push_back(i);
            if (hash[groupSizes[i]].size() == groupSizes[i]) ret.push_back(std::move(hash[groupSizes[i]]));
        }
        return ret;
    }
};
