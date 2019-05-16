// Author: xhdhr10000
// Date: 2019-05-07
int projectionArea(int** grid, int gridSize, int* gridColSize){
    int *maxr = (int*)malloc(sizeof(int)*gridSize);
    int *maxc = (int*)malloc(sizeof(int)*gridSize);
    int xy = 0, xz = 0, yz = 0;
    
    memset(maxr, 0, sizeof(int)*gridSize);
    memset(maxc, 0, sizeof(int)*gridSize);
    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridColSize[i]; j++) {
            if (grid[i][j] > 0) xy++;
            if (grid[i][j] > maxr[i]) maxr[i] = grid[i][j];
            if (grid[i][j] > maxc[j]) maxc[j] = grid[i][j];
        }
        yz += maxr[i];
    }
    for (int j=0; j<gridSize; j++) xz += maxc[j];
    return xy+yz+xz;
}



