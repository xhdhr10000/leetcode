// Author: xhdhr10000
// Date: 2019-07-17
int expand(char *s, int x, int y) {
    int l = strlen(s);
    while (x>=0 && y<l && s[x] == s[y]) {
        x--; y++;
    }
    return y-x-1;
}

char * longestPalindrome(char * s){
    int max = 0, maxp = 0, len = strlen(s);
    for (int i=0; i<len; i++) {
        int l = expand(s, i, i);
        if (l > max) {
            max = l;
            maxp = i-l/2;
        }
        if (i<len-1 && s[i]==s[i+1]) {
            l = expand(s, i, i+1);
            if (l > max) {
                max = l;
                maxp = i-l/2+1;
            }
        }
    }
    s[maxp+max] = 0;
    return &s[maxp];
}
