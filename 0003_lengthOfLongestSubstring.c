// Author: xhdhr10000
// Date: 2019-07-25
int lengthOfLongestSubstring(char * s){
    bool hash[256];
    int ans = 0, len = strlen(s), i=0, j;
    
    memset(hash, 0, sizeof(hash));
    for (j=0; j<len; j++) {
        while (hash[s[j]]) {
            hash[s[i]] = false;
            i++;
        }
        hash[s[j]] = true;
        if (j-i+1 > ans) ans = j-i+1;
    }
    return ans;
}
