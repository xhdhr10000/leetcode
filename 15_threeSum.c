// Author: xhdhr10000
// Date: 2019-05-16
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define MAXN  0x7fffffff

int* result(int a, int b, int c) {
    int *ret = (int*)malloc(sizeof(int)*3);
    ret[0] = a;
    ret[1] = b;
    ret[2] = c;
    return ret;
}

void sort(int *d, int x, int y) {
    int a=x, b=y, c;
    while (a<b) {
        while (a<b && d[a]<=d[b]) a++;
        if (a<b) {
            c=d[a];
            d[a]=d[b];
            d[b]=c;
        }
        while (a<b && d[a]<=d[b]) b--;
        if (a<b) {
            c=d[a];
            d[a]=d[b];
            d[b]=c;
        }
    }
    if (x<a-1) sort(d, x, a-1);
    if (b+1<y) sort(d, b+1, y);
}

bool find(int *d, int x, int a, int b) {
    int c = (a+b)/2;
    if (d[c] == x) return true;
    if (d[c] > x && a <= c-1) return find(d, x, a, c-1);
    if (d[c] < x && c+1 <= b) return find(d, x, c+1, b);
    return false;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int rSize = 256;
    int **ret = (int**)malloc(sizeof(int*)*rSize);
    int *ns = (int*)malloc(sizeof(int)*numsSize);
    int *ps = (int*)malloc(sizeof(int)*numsSize);
    int pns = 0, pps = 0, zero = 0, i, j, min=0x7fffffff, max=-0x80000000;
    
    for (i=0; i<numsSize; i++) {
        if (nums[i] < 0) ns[pns++] = nums[i];
        else if (nums[i] > 0) ps[pps++] = nums[i];
        else zero++;
        min = MIN(min, nums[i]);
        max = MAX(max, nums[i]);
    }
    sort(ns, 0, pns-1);
    sort(ps, 0, pps-1);
    
    *returnSize = 0;
    if (zero >= 3) ret[(*returnSize)++] = result(0, 0, 0);
    if (zero >= 1) {
        for (i=0; i<pps; i++) {
            if (i>0 && ps[i]==ps[i-1]) continue;
            if (find(ns, -ps[i], 0, pns-1)) {
                if (*returnSize >= rSize) {
                    rSize *= 2;
                    ret = (int**)realloc(ret, sizeof(int*)*rSize);
                }
                ret[*returnSize] = result(-ps[i], 0, ps[i]);
                (*returnSize)++;
            }
        }
    }
    for (i=0; i<pns; i++) {
        if (i>0 && ns[i]==ns[i-1]) continue;
        j = i+1;
        while (j+1<pns && ns[j+1]==ns[i]) j++;
        for (; j<pns; j++) {
            if (ns[j]!=ns[i] && ns[j]==ns[j-1]) continue;
            if (-(__int64_t)ns[i]-ns[j] <= MAXN && -ns[i]-ns[j] <= max &&
                find(ps, -ns[i]-ns[j], 0, pps-1)) {
                if (*returnSize >= rSize) {
                    rSize *= 2;
                    ret = (int**)realloc(ret, sizeof(int*)*rSize);
                }
                ret[*returnSize] = result(ns[i], ns[j], -ns[i]-ns[j]);
                (*returnSize)++;
            }
        }
    }
    for (i=0; i<pps; i++) {
        if (i>0 && ps[i]==ps[i-1]) continue;
        j = i+1;
        while (j+1<pps && ps[j+1]==ps[i]) j++;
        for (; j<pps; j++) {
            if (ps[j]!=ps[i] && ps[j]==ps[j-1]) continue;
            if (-(__int64_t)ps[i]-ps[j] >= (__int64_t)-MAXN-1 && -ps[i]-ps[j] >= min &&
                find(ns, -ps[i]-ps[j], 0, pns-1)) {
                if (*returnSize >= rSize) {
                    rSize *= 2;
                    ret = (int**)realloc(ret, sizeof(int*)*rSize);
                }
                ret[*returnSize] = result(ps[i], ps[j], -ps[i]-ps[j]);
                (*returnSize)++;
            }
        }
    }
    
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for (int i=0; i<*returnSize; i++) (*returnColumnSizes)[i] = 3;
    
    return ret;
}



