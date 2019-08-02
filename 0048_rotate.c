// Author: xhdhr10000
// Date: 2019-07-23
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int t, n = matrixSize;
    
    for (int r=0; r<n/2; r++) {
        for (int c=0; c<(n+1)/2; c++) {
            int i=r, j=c;
            t = matrix[r][c];
            for (int k=0; k<3; k++) {
                matrix[i][j] = matrix[n-j-1][i];
                int ii = i; i = n-j-1; j = ii;
            }
            matrix[i][j] = t;
        }
    }
}
