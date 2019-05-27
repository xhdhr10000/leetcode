// Author: xhdhr10000
// Date: 2019-05-26

int find(int *a, int x, int y, int d) {
    int i = (x+y)/2;
    if (x > y) return -1;
    if (a[i] == d) return i;
    if (a[x] < a[y]) {
        if (d < a[i]) return find(a, x, i-1, d);
        else return find(a, i+1, y, d);
    } else {
        if (a[i] >= a[x]) {
            if (d >= a[x] && d < a[i]) return find(a, x, i-1, d);
            else return find(a, i+1, y, d);
        } else {
            if (d > a[i] && d <= a[y]) return find(a, i+1, y, d);
            else return find(a, x, i-1, d);
        }
    }
}

int search(int* nums, int numsSize, int target){
    return find(nums, 0, numsSize-1, target);
}



