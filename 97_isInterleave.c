// Author: xhdhr10000
// Date: 2019-05-06
bool isInterleave(char * s1, char * s2, char * s3){
    bool ret;
    int l1 = strlen(s1), l2 = strlen(s2), l3 = strlen(s3);
    if (l1+l2 != l3) return false;
    
    bool **dp = (bool**)malloc(sizeof(bool*)*(l1+1));
    for (int i=0; i<=l1; i++) {
        dp[i] = (bool*)malloc(sizeof(bool)*(l2+1));
        if (i == 0) {
            dp[0][0] = 1;
            for (int j=1; j<=l2; j++) dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        } else
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    }
    for (int i=1; i<=l1; i++) {
        for (int j=1; j<=l2; j++) {
            dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1] ||
                       dp[i][j-1] && s2[j-1] == s3[i+j-1];
        }
    }
    ret = dp[l1][l2];
    
    for (int i=0; i<=l1; i++) free(dp[i]);
    free(dp);
    return ret;
}



