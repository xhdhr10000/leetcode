// Author: xhdhr10000
// Date: 2019-07-16
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
enum Direction {
    RIGHT = 0,
    DOWN,
    LEFT,
    UP
};

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int m = matrixSize, n = m > 0 ? matrixColSize[0] : 0;
    int *ret = (int*)malloc(sizeof(int)*m*n);
    int pr = 0;
    enum Direction dir = RIGHT;
    int up = 0, right = n-1, down = m-1, left = 0, x = 0, y = 0;
    *returnSize = m*n;
    
    while (pr < *returnSize) {
        ret[pr++] = matrix[y][x];
        for (int i=0; i<4; i++) {
            if (dir == RIGHT) {
                if (x < right) {
                    x++;
                    break;
                } else {
                    up++;
                    dir = DOWN;
                }
            } else if (dir == DOWN) {
                if (y < down) {
                    y++;
                    break;
                } else {
                    right--;
                    dir = LEFT;
                }
            } else if (dir == LEFT) {
                if (x > left) {
                    x--;
                    break;
                } else {
                    down--;
                    dir = UP;
                }
            } else if (dir == UP) {
                if (y > up) {
                    y--;
                    break;
                } else {
                    left++;
                    dir = RIGHT;
                }
            }
        }
    }
    
    return ret;
}
