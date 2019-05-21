// Author: xhdhr10000
// Date: 2019-05-14
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int largestIsland(int** grid, int gridSize, int* gridColSize){
    int maxCategory = (gridSize/2+1)*gridSize + 2;
    int *count = (int*)malloc(sizeof(int)*maxCategory);
    int max = 0, cur = 2;
    
    memset(count, 0, sizeof(int)*maxCategory);
    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridColSize[i]; j++) {
            if (grid[i][j]) {
                int up = 0, left = 0;
                if (i>0 && grid[i-1][j]>0) up = grid[i-1][j];
                if (j>0 && grid[i][j-1]>0) left = grid[i][j-1];
                while (count[up] < 0) up = -count[up];
                while (count[left] < 0) left = -count[left];
                if (!up && !left) {
                    /* new land */
                    grid[i][j] = cur;
                    count[cur]++;
                    cur++;
                } else if (up && !left) {
                    grid[i][j] = up;
                    count[up]++;
                } else if (left && !up) {
                    grid[i][j] = left;
                    count[left]++;
                } else if (up == left) {
                    grid[i][j] = up;
                    count[up]++;
                } else {
                    grid[i][j] = MIN(up, left);
                    count[MIN(up, left)] += count[MAX(up, left)] + 1;
                    count[MAX(up, left)] = -MIN(up, left);
                }
            }
        }
    }
    for (int i=2; i<cur; i++) max = MAX(max, count[i]);
    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridColSize[i]; j++) {
            if (!grid[i][j]) {
                int up=0, down=0, left=0, right=0;
                if (i>0 && grid[i-1][j]>0) up = grid[i-1][j];
                if (i<gridSize-1 && grid[i+1][j]>0) down = grid[i+1][j];
                if (j>0 && grid[i][j-1]>0) left = grid[i][j-1];
                if (j<gridColSize[i]-1 && grid[i][j+1]>0) right = grid[i][j+1];
                while (count[up] < 0) up = -count[up];
                while (count[down] < 0) down = -count[down];
                while (count[left] < 0) left = -count[left];
                while (count[right] < 0) right = -count[right];
                if (left == up) left = 0;
                if (down == up || down == left) down = 0;
                if (right == up || right == down || right == left) right = 0;
                max = MAX(max, count[up]+count[down]+count[left]+count[right]+1);
            }
        }
    }
    
    free(count);
    return max;
}
