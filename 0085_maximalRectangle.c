// Author: xhdhr10000
// Date: 2019-07-29
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int inline idx(int row, int col, int dir, int mcol) {
    return row*mcol*2 + col*2 + dir;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0) return 0;
    int row = matrixSize, col = matrixColSize[0];
    int *dp = (int*)malloc(sizeof(int)*row*col*2);
    int ans = 0;
    
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (matrix[i][j] == '0') {
                dp[idx(i,j,0,col)] = dp[idx(i,j,1,col)] = 0;
                continue;
            }
            dp[idx(i,j,0,col)] = i > 0 ? dp[idx(i-1,j,0,col)]+1 : 1;
            dp[idx(i,j,1,col)] = j > 0 ? dp[idx(i,j-1,1,col)]+1 : 1;
            
            if (dp[idx(i,j,0,col)] < dp[idx(i,j,1,col)]) {
                int min = col;
                for (int k=0; k<dp[idx(i,j,0,col)]; k++) {
                    min = MIN(min, dp[idx(i-k,j,1,col)]);
                    ans = MAX(ans, min * (k+1));
                }
            } else {
                int min = row;
                for (int k=0; k<dp[idx(i,j,1,col)]; k++) {
                    min = MIN(min, dp[idx(i,j-k,0,col)]);
                    ans = MAX(ans, min * (k+1));
                }
            }
        }
    }
    
    free(dp);
    return ans;
}
