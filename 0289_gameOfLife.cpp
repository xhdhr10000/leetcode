// Author: xhdhr10000
// Date: 2020-04-02

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                int n = countNeighbors(board, i, j);
                if (board[i][j] == 0 && n == 3) board[i][j] = -1;
                else if (board[i][j] == 1 && (n < 2 || n > 3)) board[i][j] = -2;
            }
        }
        for (int i=0; i<board.size(); i++)
            for (int j=0; j<board[i].size(); j++)
                board[i][j] = abs(board[i][j]) % 2;
    }
private:
    int countNeighbors(vector<vector<int>>& board, int x, int y) {
        const int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                {0, 1}, {1, -1}, {1, 0}, {1, 1} };
        int count = 0;
        for (int i=0; i<8; i++) {
            int nx = x+dir[i][0], ny = y+dir[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[nx].size() &&
                (board[nx][ny] == 1 || board[nx][ny] == -2))
                count++;
        }
        return count;
    }
};
