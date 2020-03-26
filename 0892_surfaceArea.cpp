// Author: xhdhr10000
// Date: 2020-03-25

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;
        for (int r=0; r<grid.size(); r++) {
            for (int c=0; c<grid.size(); c++) {
                if (grid[r][c] == 0) continue;
                area += (grid[r][c] << 2) + 2;
                if (r > 0) area -= min(grid[r-1][c], grid[r][c]) << 1;
                if (c > 0) area -= min(grid[r][c-1], grid[r][c]) << 1;
            }
        }
        return area;
    }
};
