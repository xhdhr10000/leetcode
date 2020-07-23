// Author: xhdhr10000
// Date: 2020-04-08

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[s.size() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && !dp[i]) i++;
            for (string &w : wordDict) {
                if (s.substr(i, w.size()) == w) {
                    dp[i+w.size()] = true;
                    if (i + w.size() == s.size()) return true;
                }
            }
            i++;
        }
        return dp[s.size()];
    }
};
