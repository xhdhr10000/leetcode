// Author: xhdhr10000
// Date: 2019-07-20
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
void sort(int *d, int x, int y) {
    int a=x, b=y, c;
    while (a<b) {
        while (a<b && d[a]<=d[b]) a++;
        if (a<b) {
            c = d[a]; d[a] = d[b]; d[b] = c;
        }
        while (a<b && d[a]<=d[b]) b--;
        if (a<b) {
            c = d[a]; d[a] = d[b]; d[b] = c;
        }
    }
    if (x<a-1) sort(d, x, a-1);
    if (b+1<y) sort(d, b+1, y);
}

void nextPermutation(int* nums, int numsSize){
    int i;
    for (i=numsSize-2; i>=0; i--)
        if (nums[i] < nums[i+1]) break;
    if (i < 0) sort(nums, 0, numsSize-1);
    else {
        int min = nums[i+1], minp = i+1;
        for (int j=i+1; j<numsSize; j++) {
            if (nums[j] > nums[i]) {
                min = MIN(min, nums[j]);
                minp = j;
            }
        }
        min = nums[i]; nums[i] = nums[minp]; nums[minp] = min;
        sort(nums, i+1, numsSize-1);
    }
}
