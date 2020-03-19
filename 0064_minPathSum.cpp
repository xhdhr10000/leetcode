// Author: xhdhr10000
// Date: 2019-12-26

#include <cmath>
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int ans[m][n];
        ans[0][0] = grid[0][0];
        for (int i=1; i<n; i++) ans[0][i] = ans[0][i-1] + grid[0][i];
        for (int i=1; i<m; i++) ans[i][0] = ans[i-1][0] + grid[i][0];
        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
                ans[i][j] = min(ans[i-1][j], ans[i][j-1]) + grid[i][j];
        return ans[m-1][n-1];
    }
};
