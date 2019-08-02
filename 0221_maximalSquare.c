// Author: xhdhr10000
// Date: 2019-08-01
#define MIN(X,Y,Z) ((X)<(Y)?((X)<(Z)?(X):(Z)):((Y)<(Z)?(Y):(Z)))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0) return 0;
    int *dp = (int*)malloc(sizeof(int)*matrixSize*matrixColSize[0]);
    int ans = 0;
    for (int i=0; i<matrixSize; i++) {
        for (int j=0; j<matrixColSize[i]; j++) {
            if (matrix[i][j] == '1') {
                dp[i*matrixColSize[i]+j] = i>0 && j>0 ?
                    MIN(dp[(i-1)*matrixColSize[i]+j-1], dp[(i-1)*matrixColSize[i]+j], dp[i*matrixColSize[i]+j-1]) + 1 : 1;
                ans = MAX(ans, dp[i*matrixColSize[i]+j]);
            } else dp[i*matrixColSize[i]+j] = 0;
        }
    }
    free(dp);
    return ans*ans;
}
