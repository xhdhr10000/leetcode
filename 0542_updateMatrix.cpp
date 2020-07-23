// Author: xhdhr10000
// Date: 2020-04-15

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return vector<vector<int>>();
        vector<vector<int>> ret(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j] == 0) continue;
                int min = 20000;
                for (int k=0; k<2; k++) {
                    if (i+dir_forward[k][0] >= 0 && j+dir_forward[k][1] >= 0 &&
                        j+dir_forward[k][1] < matrix[i].size())
                        min = std::min(min, ret[i+dir_forward[k][0]][j+dir_forward[k][1]]);
                }
                ret[i][j] = min + 1;
            }
        }

        for (int i=matrix.size()-1; i>=0; i--) {
            for (int j=matrix[i].size()-1; j>=0; j--) {
                if (matrix[i][j] == 0) continue;
                int min = 20000;
                for (int k=0; k<2; k++) {
                    if (i+dir_backward[k][0] < matrix.size() && j+dir_backward[k][1] >= 0 &&
                        j+dir_backward[k][1] < matrix[i].size())
                        min = std::min(min, ret[i+dir_backward[k][0]][j+dir_backward[k][1]]);
                }
                ret[i][j] = std::min(min + 1, ret[i][j]);
            }
        }
        return ret;
    }
private:
    const int dir_forward[2][2] = { {-1, 0}, {0, -1} };
    const int dir_backward[2][2] = { {0, 1}, {1, 0} };
};
