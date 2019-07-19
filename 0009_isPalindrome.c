// Author: xhdhr10000
// Date: 2019-07-17
bool isPalindrome(int x){
    char s[12];
    sprintf(s, "%d", x);
    int i = 0, j = strlen(s)-1;
    while (i<j && s[i]==s[j]) { i++; j--; }
    return i >= j;
}
