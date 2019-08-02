// Author: xhdhr10000
// Date: 2019-07-29
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
int numSquares(int n){
    int *dp = (int*)malloc(sizeof(int)*(n+1));
    int ans = n;
    
    memset(dp, 0, sizeof(int)*(n+1));
    for (int i=0; i<=n; i++) dp[i] = i;
    for (int i=2; i<=(int)sqrt(n); i++) {
        int x = i*i;
        for (int j=x; j<=n; j++) dp[j] = MIN(dp[j], dp[j-x]+1);
    }
    ans = MIN(ans, dp[n]);
    free(dp);
    return ans;
}
