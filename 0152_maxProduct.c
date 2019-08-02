// Author: xhdhr10000
// Date: 2019-08-02
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int maxProduct(int* nums, int numsSize){
    int *neg = (int*)malloc(sizeof(int)*(numsSize+1));
    int *zero = (int*)malloc(sizeof(int)*(numsSize+1)), pz = 0;
    int *pro = (int*)malloc(sizeof(int)*(numsSize+1));
    int ans = -0x7fffffff;
    neg[0] = 0; pro[0] = 1;
    for (int i=0; i<numsSize; i++) {
        pro[i+1] = pro[i] * nums[i];
        ans = MAX(ans, pro[i+1]);
        neg[i+1] = nums[i] < 0 ? neg[i] + 1 : neg[i];
        if (nums[i] == 0) { zero[pz++] = i+1; pro[i+1] = 1; }
    }
    
    int i = 0, j = 0;
    zero[pz++] = numsSize+1;
    for (int p=0; p<pz; p++) {
        j = zero[p]-1;
        while (i<j && (neg[j]-neg[i])%2) j--;
        if (i<j && nums[j-1]!=0) ans = MAX(ans, pro[j]/pro[i]);
        j = zero[p]-1;
        while (i<j && (neg[j]-neg[i])%2) i++;
        if (i<j && nums[j-1]!=0) ans = MAX(ans, pro[j]/pro[i]);
        i = zero[p];
    }
    
    free(pro);
    free(zero);
    free(neg);
    return ans;
}
