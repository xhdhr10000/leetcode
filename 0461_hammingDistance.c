// Author: xhdhr10000
// Date: 2019-07-29
int hammingDistance(int x, int y){
    int ans = 0;
    while (x || y) {
        ans += (x&1)^(y&1);
        x >>= 1;
        y >>= 1;
    }
    return ans;
}
