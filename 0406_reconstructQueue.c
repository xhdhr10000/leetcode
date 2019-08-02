// Author: xhdhr10000
// Date: 2019-07-26
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void sort(int **d, int x, int y) {
    int a=x, b=y, c;
    while (a<b) {
        while (a<b && (d[a][0]>d[b][0] || d[a][0]==d[b][0] && d[a][1]<=d[b][1])) a++;
        if (a<b) {
            c = d[a][0]; d[a][0] = d[b][0]; d[b][0] = c;
            c = d[a][1]; d[a][1] = d[b][1]; d[b][1] = c;
        }
        while (a<b && (d[a][0]>d[b][0] || d[a][0]==d[b][0] && d[a][1]<=d[b][1])) b--;
        if (a<b) {
            c = d[a][0]; d[a][0] = d[b][0]; d[b][0] = c;
            c = d[a][1]; d[a][1] = d[b][1]; d[b][1] = c;
        }
    }
    if (x<a-1) sort(d, x, a-1);
    if (b+1<y) sort(d, b+1, y);
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    int **ret = (int**)malloc(sizeof(int*)*peopleSize);
    *returnSize = peopleSize;
    *returnColumnSizes = (int*)malloc(sizeof(int)*peopleSize);
    for (int i=0; i<peopleSize; i++) {
        (*returnColumnSizes)[i] = 2;
        ret[i] = (int*)malloc(sizeof(int)*2);
    }
    
    sort(people, 0, peopleSize-1);
    for (int i=0; i<peopleSize; i++) {
        for (int j=i; j>people[i][1]; j--) { ret[j][0] = ret[j-1][0]; ret[j][1] = ret[j-1][1]; }
        ret[people[i][1]][0] = people[i][0];
        ret[people[i][1]][1] = people[i][1];
    }
    
    return ret;
}
