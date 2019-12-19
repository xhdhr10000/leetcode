// Author: xhdhr10000
// Date: 2019-10-07
char * minWindow(char * s, char * t){
    int hasht[256], hashs[256], count = 0, i, j;
    char *minp = "";
    int min = strlen(s);

    if (!strlen(t)) return minp;
    memset(hasht, 0, sizeof(hasht));
    memset(hashs, 0, sizeof(hashs));
    for (i=0; i<strlen(t); i++) hasht[t[i]]++;
    i = 0;
    for (j=0; j<strlen(s); j++) {
        hashs[s[j]]++;
        if (hasht[s[j]] && hashs[s[j]] <= hasht[s[j]]) count++;
        while (count == strlen(t)) {
            if (j-i+1 <= min) {
                min = j-i+1;
                minp = &s[i];
            }
            if (hasht[s[i]] && hashs[s[i]] <= hasht[s[i]]) count--;
            hashs[s[i]]--;
            i++;
        }
    }
    if (min != strlen(s)) minp[min] = 0;
    return minp;
}
