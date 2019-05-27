// Author: xhdhr10000
// Date: 2019-05-26
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int *nums3 = (int*)malloc(sizeof(int)*m);
    int i=0, j=0, k=0;
    memcpy(nums3, nums1, sizeof(int)*m);
    while (j < n && k < m) {
        if (nums2[j] <= nums3[k]) nums1[i++] = nums2[j++];
        else nums1[i++] = nums3[k++];
    }
    while (j < n) nums1[i++] = nums2[j++];
    while (k < m) nums1[i++] = nums3[k++];
    free(nums3);
}



