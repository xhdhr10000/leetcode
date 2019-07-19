// Author: xhdhr10000
// Date: 2019-07-17
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
enum Direction {
    RIGHT, DOWN, LEFT, UP
};

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **ret = (int**)malloc(sizeof(int*)*n);
    enum Direction dir = RIGHT;
    int r = 0, c = 0, up = 0, right = n-1, down = n-1, left = 0;
    
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++) {
        ret[i] = (int*)malloc(sizeof(int)*n);
        (*returnColumnSizes)[i] = n;
    }
    for (int i=1; i<=n*n; i++) {
        ret[r][c] = i;
        for (int j=0; j<2; j++) {
            if (dir == RIGHT) {
                if (c < right) { c++; break; }
                else { dir = DOWN; up++; }
            } else if (dir == DOWN) {
                if (r < down) { r++; break; }
                else { dir = LEFT; right--; }
            } else if (dir == LEFT) {
                if (c > left) { c--; break; }
                else { dir = UP; down--; }
            } else if (dir == UP) {
                if (r > up) { r--; break; }
                else { dir = RIGHT; left++; }
            }
        }
    }
    return ret;
}
