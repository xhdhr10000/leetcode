// Author: xhdhr10000
// Date: 2019-04-30
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * case 0: n0 n1 i0 i1 just insert
 * case 1: n0 i0 n1 i1 insert and merge
 * case 2: i0 n0 n1 i1 just ignore
 * case 3: n0 i0 i1 n1 insert, merge and wait
 * case 4: i0 n0 i1 n1 insert, merge and wait
 * case 5: i0 i1 n0 n1 continue
 */
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int **ret = (int**)malloc(sizeof(int*)*(intervalsSize+1));
    int over = 0;
    *returnSize = 0;
    for (int i=0; i<intervalsSize; i++) {
        int *range = (int*)malloc(sizeof(int)*2);
        if (over || intervals[i][1] < newInterval[0]) {
            range[0] = intervals[i][0];
            range[1] = intervals[i][1];
        } else if (newInterval[1] < intervals[i][0]) {
            range[0] = newInterval[0];
            range[1] = newInterval[1];
            over = 1;
            i--;
        } else if (newInterval[0] <= intervals[i][1]) {
            range[0] = MIN(intervals[i][0], newInterval[0]);
            while (newInterval[1] > intervals[i][1] && i<intervalsSize-1) i++;
            if (newInterval[1] < intervals[i][0]) {
                range[1] = newInterval[1];
                i--;
            } else
                range[1] = MAX(intervals[i][1], newInterval[1]);
            over = 1;
        }
        ret[(*returnSize)++] = range;
    }
    if (!over) {
        int *range = (int*)malloc(sizeof(int)*2);
        range[0] = newInterval[0];
        range[1] = newInterval[1];
        ret[(*returnSize)++] = range;
    }
    
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for (int i=0; i<*returnSize; i++) (*returnColumnSizes)[i] = 2;
    return ret;
}



