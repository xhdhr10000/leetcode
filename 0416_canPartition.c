// Author: xhdhr10000
// Date: 2019-07-26
bool canPartition(int* nums, int numsSize){
    int sum = 0;
    for (int i=0; i<numsSize; i++) sum += nums[i];
    if (sum % 2) return false;
    sum /= 2;
    int *s = (int*)malloc(sizeof(int)*(sum*2+1)), p = 1;
    int *hash = (int*)malloc(sizeof(int)*(sum*2+1));
    memset(hash, 0, sizeof(int)*(sum*2+1));
    s[0] = 0;
    for (int i=0; i<numsSize; i++) {
        for (int j=p-1; j>=0; j--) {
            if (nums[i] + s[j] == sum) { free(s); free(hash); return true; }
            if (!hash[nums[i]+s[j]]) s[p++] = nums[i] + s[j];
            hash[nums[i]+s[j]] = true;
        }
    }
    free(s);
    free(hash);
    return false;
}
