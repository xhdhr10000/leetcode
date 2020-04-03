// Author: xhdhr10000
// Date: 2020-04-01

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> stack;
        vector<int> ans;
        for (int i=0; i<seq.size(); i++) {
            if (seq[i] == '(') {
                ans.push_back(stack.size() % 2);
                stack.push_back(i);
            } else {
                ans.push_back(ans[stack.back()]);
                stack.pop_back();
            }
        }
        return ans;
    }
};
