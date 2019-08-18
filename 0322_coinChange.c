// Author: xhdhr10000
// Date: 2019-08-06
int coinChange(int* coins, int coinsSize, int amount){
    int *dp = (int*)malloc(sizeof(int)*(amount+1));
    dp[0] = 0;
    for (int i=1; i<=amount; i++) dp[i] = -1;
    for (int i=0; i<coinsSize; i++) {
        for (int j=0; j+coins[i]<=amount; j++) {
            if (dp[j] < 0) continue;
            if (dp[j+coins[i]] < 0 || dp[j]+1 < dp[j+coins[i]]) dp[j+coins[i]] = dp[j] + 1;
        }
    }
    int ret = dp[amount];
    free(dp);
    return ret;
}
