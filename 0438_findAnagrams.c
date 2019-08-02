// Author: xhdhr10000
// Date: 2019-07-29
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize){
    int *ret = (int*)malloc(sizeof(int)*strlen(s));
    int hp[26], hs[26];
    
    *returnSize = 0;
    if (strlen(s) < strlen(p)) return ret;
    memset(hp, 0, sizeof(hp));
    memset(hs, 0, sizeof(hs));
    for (int i=0; i<strlen(p); i++) {
        hp[p[i]-'a']++;
        hs[s[i]-'a']++;
    }
    if (!memcmp(hp, hs, sizeof(hp))) ret[(*returnSize)++] = 0;
    for (int i=strlen(p); i<strlen(s); i++) {
        hs[s[i]-'a']++;
        hs[s[i-strlen(p)]-'a']--;
        if (!memcmp(hp, hs, sizeof(hp))) ret[(*returnSize)++] = i-strlen(p)+1;
    }
    
    return ret;
}
