// Author: xhdhr10000
// Date: 2019-07-29
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

void sort(int **d, int x, int y) {
    int a=x, b=y, c;
    while (a<b) {
        while (a<b && (d[a][0]<d[b][0] || d[a][0]==d[b][0] && d[a][1]<=d[b][1])) a++;
        if (a<b) {
            c=d[a][0]; d[a][0]=d[b][0]; d[b][0]=c;
            c=d[a][1]; d[a][1]=d[b][1]; d[b][1]=c;
        }
        while (a<b && (d[a][0]<d[b][0] || d[a][0]==d[b][0] && d[a][1]<=d[b][1])) b--;
        if (a<b) {
            c=d[a][0]; d[a][0]=d[b][0]; d[b][0]=c;
            c=d[a][1]; d[a][1]=d[b][1]; d[b][1]=c;
        }
    }
    if (x<a-1) sort(d, x, a-1);
    if (b+1<y) sort(d, b+1, y);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **ret = (int**)malloc(sizeof(int*)*intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int)*intervalsSize);
    *returnSize = 0;
    
    if (intervalsSize == 0) return ret;
    sort(intervals, 0, intervalsSize-1);
    ret[*returnSize] = (int*)malloc(sizeof(int)*2);
    ret[*returnSize][0] = intervals[0][0];
    ret[*returnSize][1] = intervals[0][1];
    (*returnColumnSizes)[*returnSize] = 2;
    for (int i=1; i<intervalsSize; i++) {
        if (ret[*returnSize][1] < intervals[i][0]) {
            (*returnSize)++;
            ret[*returnSize] = (int*)malloc(sizeof(int)*2);
            ret[*returnSize][0] = intervals[i][0];
            ret[*returnSize][1] = intervals[i][1];
            (*returnColumnSizes)[*returnSize] = 2;
        } else {
            ret[*returnSize][1] = MAX(ret[*returnSize][1], intervals[i][1]);
        }
    }
    (*returnSize)++;
    
    return ret;
}
