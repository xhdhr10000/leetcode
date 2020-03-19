// Author: xhdhr10000
// Date: 2019-12-26

#include <cmath>
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->m = grid.size();
        if (this->m == 0) return 0;
        this->n = grid[0].size();

        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
private:
    const int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    int m, n;

    int dfs(vector<vector<int>>& grid, int r, int c) {
        int ret = 1;
        grid[r][c] = 0;
        for (int i=0; i<4; i++) {
            int rn = r + dir[i][0], cn = c + dir[i][1];
            if (rn >= 0 && rn < this->m && cn >= 0 && cn < this->n && grid[rn][cn] == 1)
                ret += dfs(grid, rn, cn);
        }
        return ret;
    }
};
