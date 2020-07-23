// Author: xhdhr10000
// Date: 2020-04-23

class Solution {
public:
    int waysToChange(int n) {
        const int coins[] = { 5, 10, 25 };
        vector<int64_t> dp(n+1, 1);
        for (int c : coins) {
            for (int i=c; i<=n; i++) dp[i] += dp[i-c];
        }
        return dp[n] % 1000000007;
    }
};
