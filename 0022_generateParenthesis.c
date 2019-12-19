// Author: xhdhr10000
// Date: 2019-08-18
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(char *s, int l, int r, int n, char ***ret, int *returnSize, int *size) {
    if (strlen(s) == n*2) {
        if (*returnSize >= *size) {
            *size *= 2;
            *ret = (char**)realloc(*ret, sizeof(char*)*(*size));
        }
        (*ret)[(*returnSize)++] = s;
        return;
    }
    if (l < n) {
        char *ls = (char*)malloc(sizeof(char)*(n*2+1));
        sprintf(ls, "%s(", s);
        dfs(ls, l+1, r, n, ret, returnSize, size);
    }
    if (r < l) {
        char *rs = (char*)malloc(sizeof(char)*(n*2+1));
        sprintf(rs, "%s)", s);
        dfs(rs, l, r+1, n, ret, returnSize, size);
    }
    free(s);
}

char ** generateParenthesis(int n, int* returnSize){
    int size = 256;
    char **ret = (char**)malloc(sizeof(char*)*size);
    *returnSize = 0;
    char *s = (char*)malloc(sizeof(char)*(n*2+1));
    sprintf(s, "(");
    dfs(s, 1, 0, n, &ret, returnSize, &size);
    return ret;
}
