// Author: xhdhr10000
// Date: 2020-03-26

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0, Rx, Ry;

        // Find R
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j] == 'R') {
                    Rx = i; Ry = j;
                    break;
                }
            }
        }

        // Find p
        const int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
        for (int d=0; d<4; d++) {
            for (int x=Rx, y=Ry; x>=0 && x<board.size() && y>=0 && y<board[x].size(); x+=dir[d][0], y+=dir[d][1]) {
                if (board[x][y] == 'B') break;
                if (board[x][y] == 'p') { ans++; break; }
            }
        }

        return ans;
    }
};
