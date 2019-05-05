// Author: xhdhr10000
// Date: 2019-05-01
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int count = 0;
    int maxr[50], maxc[50];
    
    memset(maxr, 0, sizeof(maxr));
    memset(maxc, 0, sizeof(maxc));
    
    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridColSize[i]; j++) {
            maxr[i] = MAX(maxr[i], grid[i][j]);
            maxc[j] = MAX(maxc[j], grid[i][j]);
        }
    }
    
    for (int i=0; i<gridSize; i++)
        for (int j=0; j<gridColSize[i]; j++)
            count += MIN(maxr[i], maxc[j]) - grid[i][j];
    
    return count;
}



