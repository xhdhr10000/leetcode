// Author: xhdhr10000
// Date: 2019-07-29

bool search(int **matrix, int r1, int r2, int c1, int c2, int x) {
    if (r1>r2 || c1>c2) return false;
    int r = (r1+r2)/2, c = (c1+c2)/2;
    if (x == matrix[r][c]) return true;
    if (x < matrix[r][c]) {
        if (r1<=r-1 && c1<=c-1 && search(matrix, r1, r-1, c1, c-1, x)) return true;
        if (r1<=r-1 && search(matrix, r1, r-1, c, c2, x)) return true;
        if (c1<=c-1 && search(matrix, r, r2, c1, c-1, x)) return true;
    } else {
        if (r+1<=r2 && c+1<=c2 && search(matrix, r+1, r2, c+1, c2, x)) return true;
        if (c+1<=c2 && search(matrix, r1, r, c+1, c2, x)) return true;
        if (r+1<=r2 && search(matrix, r+1, r2, c1, c, x)) return true;
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    return search(matrix, 0, matrixRowSize-1, 0, matrixColSize-1, target);
}
