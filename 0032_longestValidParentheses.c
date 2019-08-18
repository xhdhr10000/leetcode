// Author: xhdhr10000
// Date: 2019-08-07
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int longestValidParentheses(char * s){
    int ans = 0, l = 0, p = 0, len = strlen(s);
    int *stack = (int*)malloc(sizeof(int)*len);
    for (int i=0; i<len; i++) {
        if (s[i] == '(') stack[p++] = i;
        else if (p > 0) {
            p--;
            ans = MAX(ans, i-(p ? MAX(stack[p-1]+1,l) : l)+1);
        } else {
            ans = MAX(ans, i-l);
            l = i+1;
            p = 0;
        }
    }
    ans = MAX(ans, len-(p ? MAX(stack[p-1]+1,l) : len));
    free(stack);
    return ans;
}
