// Author: xhdhr10000
// Date: 2019-05-14
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];
    int n = 0;
    for (int i=1; i<=MIN(strlen(strs[0]), strlen(strs[1])); i++) {
        if (strncmp(strs[0], strs[1], i)) break;
        n = i;
    }
    for (int i=1; i<strsSize; i++) {
        while (n>0 && strncmp(strs[0], strs[i], n)) n--;
        if (n == 0) return "";
    }
    strs[0][n] = 0;
    return strs[0];
}



