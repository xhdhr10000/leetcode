// Author: xhdhr10000
// Date: 2019-07-17

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
    if (x < a-1) sort(d, x, a-1);
    if (b+1 < y) sort(d, b+1, y);
}

int threeSumClosest(int* nums, int numsSize, int target){
    int ans = nums[0] + nums[1] + nums[2];
    
    sort(nums, 0, numsSize-1);
    for (int i=0; i<numsSize-2; i++) {
        int l = i+1, r = numsSize-1;
        while (l < r) {
            int sum = nums[i]+nums[l]+nums[r];
            if (abs(sum-target) < abs(ans-target)) ans = sum;
            if (ans == target) return ans;
            if (sum < target) l++;
            else r--;
        }
    }
    return ans;
}
