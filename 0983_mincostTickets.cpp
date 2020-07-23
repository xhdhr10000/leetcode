// Author: xhdhr10000
// Date: 2020-05-06

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if (days.size() == 0) return 0;

        const int dcosts[] = { 1, 7, 30 };
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;

        int i = 0;
        for (int j=1; j<=365; j++) {
            if (days[i] == j) {
                for (int k=0; k<3; k++) {
                    int d = max(0, j-dcosts[k]);
                    dp[j] = min(dp[j], dp[d]+costs[k]);
                }
                i++;
                if (i >= days.size()) return dp[j];
            } else dp[j] = dp[j-1];
        }
        return dp[365];
    }
};
