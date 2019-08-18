// Author: xhdhr10000
// Date: 2019-08-12
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find(int *d, int x, int y, int n) {
    if (d[x] < n) return x;
    if (d[y] >= n) return y+1;
    int i = (x+y)/2;
    if (d[i] < n && (i==x || d[i-1] >= n)) return i;
    if (d[i] < n) return find(d, x, i-1, n);
    return find(d, i+1, y, n);
}

int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *ret = (int*)malloc(sizeof(int)*TSize);
    int *ts = (int*)malloc(sizeof(int)*TSize);
    int *is = (int*)malloc(sizeof(int)*TSize);
    int p = 0;
    
    memset(ret, 0, sizeof(int)*TSize);
    for (int i=0; i<TSize; i++) {
        int j = find(ts, 0, p-1, T[i]);
        for (int k=j; k<p; k++) ret[is[k]] = i-is[k];
        p = j+1;
        ts[p-1] = T[i];
        is[p-1] = i;
    }
    *returnSize = TSize;
    free(ts);
    free(is);
    return ret;
}
