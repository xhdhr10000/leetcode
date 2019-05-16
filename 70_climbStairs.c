// Author: xhdhr10000
// Date: 2019-05-06
int climbStairs(int n){
    if (n <= 1) return 1;
    int a=1, b=1, i;
    for (i=2; i<=n; i++) {
        if (i%2) a += b;
        else b += a;
    }
    return (i%2) ? b : a;
}



