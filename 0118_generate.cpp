// Author: xhdhr10000
// Date: 2020-04-17

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return vector<vector<int>>();

        vector<vector<int>> ret;
        ret.emplace_back(1, 1);
        for (int i=1; i<numRows; i++) {
            vector<int> row(1, 1);
            for (int j=1; j<i; j++) row.push_back(ret.back()[j-1] + ret.back()[j]);
            row.push_back(1);
            ret.push_back(std::move(row));
        }
        return ret;
    }
};
