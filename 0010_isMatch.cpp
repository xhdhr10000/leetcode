// Author: xhdhr10000
// Date: 2020-04-09

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<set<int>> dp(s.size()+1);
        vector<string> ps = splitPattern(p);
        dp[0].insert(0);
        for (int i=0; i < ps.size() && ps[i].size() == 2; i++) dp[0].insert(i+1);
        for (int i=0; i<=s.size(); i++) {
            for (int j : dp[i]) {
                if (j >= ps.size()) continue;
                if (ps[j].size() == 2) {
                    dp[i].insert(j+1);
                    for (int k=i; k < s.size() && (s[k] == ps[j][0] || ps[j][0] == '.'); k++) dp[k+1].insert(j+1);
                } else if (i < s.size() && (s[i] == ps[j][0] || ps[j][0] == '.')) {
                    dp[i+1].insert(j+1);
                }
            }
        }
        return dp[s.size()].find(ps.size()) != dp[s.size()].end();
    }
private:
    vector<string> splitPattern(string &p) {
        vector<string> ret;
        for (int i=0; i<p.size(); i++) {
            if (i == p.size()-1 || p[i+1] != '*') ret.push_back(p.substr(i, 1));
            else {
                ret.push_back(p.substr(i, 2));
                i++;
            }
        }
        return ret;
    }
};
