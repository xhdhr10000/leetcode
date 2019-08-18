// Author: xhdhr10000
// Date: 2019-08-10
typedef struct {
    int r, c;
} Point;

const Point dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int numIslands(char** grid, int gridSize, int* gridColSize){
    if (gridSize == 0) return 0;
    Point *q = (Point*)malloc(sizeof(Point)*gridSize*gridColSize[0]);
    int head, rear;
    int ans = 0;
    
    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridColSize[i]; j++) {
            if (grid[i][j] != '1') continue;
            ans++;
            grid[i][j] = '0';
            head = 0; rear = 0;
            q[rear].r = i;
            q[rear].c = j;
            rear++;
            while (head < rear) {
                for (int k=0; k<4; k++) {
                    int r = q[head].r + dir[k].r, c = q[head].c + dir[k].c;
                    if (r >= 0 && r < gridSize && c >= 0 && c < gridColSize[r] && grid[r][c] == '1') {
                        grid[r][c] = '0';
                        q[rear].r = r;
                        q[rear].c = c;
                        rear++;
                    }
                }
                head++;
            }
        }
    }
    
    free(q);
    return ans;
}
