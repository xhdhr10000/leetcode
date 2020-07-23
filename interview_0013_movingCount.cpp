// Author: xhdhr10000
// Date: 2020-04-08

class Solution {
public:
    int movingCount(int m, int n, int k) {
        int ans = 0;
        bool visited[m][n];
        queue<pair<int, int>> q;

        memset(visited, 0, sizeof(visited));
        visited[0][0] = true;
        q.emplace(0, 0);
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            ans++;
            for (int i=0; i<4; i++) {
                int x = p.first + dir[i][0];
                int y = p.second + dir[i][1];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && isValid(x, y, k)) {
                    visited[x][y] = true;
                    q.emplace(x, y);
                }
            }
        }
        return ans;
    }
private:
    bool isValid(int x, int y, int k) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        while (y) {
            sum += y % 10;
            y /= 10;
        }
        return sum <= k;
    }
    const int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
};
