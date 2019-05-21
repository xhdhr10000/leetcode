// Author: xhdhr10000
// Date: 2019-05-20

int findLessOrEqual(int *nums, int x, int y, int n) {
    if (y < x) return x-1;
    int a = (x+y)/2;
    if (a == x && nums[a] > n) return x-1;
    if (a == y && nums[a] <= n) return y;
    if (nums[a] <= n && nums[a+1] > n) return a;
    if (nums[a] <= n) return findLessOrEqual(nums, a+1, y, n);
    return findLessOrEqual(nums, x, a-1, n);
}

int findIndex(int *nums1, int *nums2, int x1, int y1, int x2, int y2, int i) {
    int a1,a2;
    if (y1 < x1) {
        a2 = (x2+y2)/2;
        int l = a2-x2+1;
        if (l == i) return nums2[a2];
        if (l > i) return findIndex(nums1, nums2, x1, y1, x2, a2-1, i);
        return findIndex(nums1, nums2, x1, y1, a2+1, y2, i-l);
    } else {
        a1 = (x1+y1)/2;
        a2 = findLessOrEqual(nums2, x2, y2, nums1[a1]);
        int l = a1-x1+1+a2-x2+1;
        if (l == i) return nums1[a1];
        if (l > i) return findIndex(nums1, nums2, x1, a1-1, x2, a2, i);
        return findIndex(nums1, nums2, a1+1, y1, a2+1, y2, i-l);
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if ((nums1Size+nums2Size) % 2)
        return findIndex(nums1, nums2, 0, nums1Size-1, 0, nums2Size-1, (nums1Size+nums2Size)/2+1);
    else
        return (findIndex(nums1, nums2, 0, nums1Size-1, 0, nums2Size-1, (nums1Size+nums2Size)/2) +
                findIndex(nums1, nums2, 0, nums1Size-1, 0, nums2Size-1, (nums1Size+nums2Size)/2+1)) / 2.0;
}



