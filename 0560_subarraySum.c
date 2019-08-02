// Author: xhdhr10000
// Date: 2019-07-31
void sort(int *d, int* i, int x, int y) {
    int a=x, b=y, c;
    while (a<b) {
        while (a<b && d[a]<=d[b]) a++;
        if (a<b) {
            c = d[a]; d[a] = d[b]; d[b] = c;
            c = i[a]; i[a] = i[b]; i[b] = c;
        }
        while (a<b && d[a]<=d[b]) b--;
        if (a<b) {
            c = d[a]; d[a] = d[b]; d[b] = c;
            c = i[a]; i[a] = i[b]; i[b] = c;
        }
    }
    if (x<a-1) sort(d, i, x, a-1);
    if (b+1<y) sort(d, i, b+1, y);
}

int subarraySum(int* nums, int numsSize, int k){
    int *sum = (int*)malloc(sizeof(int)*(numsSize+1));
    int *idx = (int*)malloc(sizeof(int)*(numsSize+1));
    int ans = 0;
    sum[0] = 0;
    idx[0] = 0;
    for (int i=1; i<=numsSize; i++) {
        sum[i] = sum[i-1] + nums[i-1];
        idx[i] = i;
    }
    sort(sum, idx, 0, numsSize);
    for (int i=0; i<numsSize; i++) {
        int j = i+1;
        while (j <= numsSize && (k >= 0 && sum[i] + k > sum[j] || k < 0 && sum[j] + k < sum[i])) j++;
        while (j <= numsSize && (k >= 0 && sum[i] + k == sum[j] || k < 0 && sum[j] + k == sum[i])) {
            if (k >= 0 && idx[j] > idx[i] || k < 0 && idx[i] > idx[j]) ans++;
            j++;
        }
    }
    free(sum);
    free(idx);
    return ans;
}
