// Author: xhdhr10000
// Date: 2019-05-04

int count1(int n) {
    int count = 0, x = 0x3fe;
    while (n > 0) {
        if (n & x != n) count++;
        n >>= 1;
        x = (x >> 1) - 1;
    }
    return count;
}

char* binary2TimeStr(int n) {
    int hour = n >> 6, minute = n & 0b111111;
    if (hour > 11 || minute > 59) return NULL;

    char *time = (char*)malloc(sizeof(char)*6);
    sprintf(time, "%d:%02d", hour, minute);
    return time;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** readBinaryWatch(int num, int* returnSize){
    char **ret = (char**)malloc(sizeof(char*)*256);
    *returnSize = 0;
    for (int i=0; i<=0x3ff; i++) {
        if (count1(i) == num) {
            ret[*returnSize] = binary2TimeStr(i);
            if (ret[*returnSize]) (*returnSize)++;
        }
    }
    return ret;
}



