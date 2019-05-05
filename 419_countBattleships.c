// Author: xhdhr10000
// Date: 2019-04-30
int countBattleships(char** board, int boardSize, int* boardColSize){
    int ret = 0, i, j;
    for (i=0; i<boardSize; i++) {
        for (j=0; j<boardColSize[i]; j++) {
            if (board[i][j] == 'X' &&
               (i==0 || board[i-1][j] != 'X') &&
               (j==0 || board[i][j-1] != 'X')) ret++;
        }
    }
    return ret;
}
