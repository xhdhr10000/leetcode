// Author: xhdhr10000
// Date: 2019-08-05

#define MIN(X, Y) ((X)<(Y)?(X):(Y))
#define MAX(X, Y) ((X)>(Y)?(X):(Y))

int prime(int n) {
    int i;
    n = n%2 ? n+2 : n+1;
    for (;; n+=2) {
        for (i=3; i*i<=n; i++)
            if (n % i == 0) break;
        if (i*i > n) return n;
    }
    return n;
}

int hashidx(__int64_t *h, __int64_t x, int P) {
    int i = x % P;
    while (h[i] != 0 && h[i] != x) i = (i+1) % P;
    return i;
}

int longestConsecutive(int* nums, int numsSize){
    int P = prime(numsSize);
    __int64_t *hash = (__int64_t*)malloc(sizeof(__int64_t)*P), min = 0x7fffffff;
    bool *used = (bool*)malloc(sizeof(bool)*P);
    int ans = numsSize ? 1 : 0;
    
    memset(hash, 0, sizeof(__int64_t)*P);
    memset(used, 0, sizeof(bool)*P);
    for (int i=0; i<numsSize; i++) min = MIN(min, nums[i]);
    min--;
    for (int i=0; i<numsSize; i++) hash[hashidx(hash, nums[i]-min, P)] = nums[i]-min;
    for (int i=0; i<numsSize; i++) {
        if (used[hashidx(hash, nums[i]-min+1, P)]) continue;
        __int64_t j=nums[i]-min+1;
        int c=1, idx=hashidx(hash, j, P);
        while (hash[idx] == j) {
            used[idx] = true;
            c++;
            j++;
            idx = hashidx(hash, j, P);
        }
        ans = MAX(ans, c);
    }
    
    free(used);
    free(hash);
    return ans;
}
