// Author: xhdhr10000
// Date: 2019-05-14
char * orderlyQueue(char * S, int K){
    int len = strlen(S);
    char *ret = (char*)malloc(sizeof(char)*(strlen(S)+1));
    
    strcpy(ret, S);
    if (K == 1 && strlen(S) > 0) {
        char *cur = (char*)malloc(sizeof(char)*(strlen(S)+1));
        strcpy(cur, &S[1]);
        cur[len-1] = S[0];
        cur[len] = 0;
        while (strcmp(cur, S)) {
            if (strcmp(cur, ret) < 0) strcpy(ret, cur);
            char c = cur[0];
            for (int i=0; i<len; i++) cur[i] = cur[i+1];
            cur[len-1] = c;
        }
        free(cur);
    } else {
        int *hash = (int*)malloc(sizeof(int)*26);
        memset(hash, 0, sizeof(int)*26);
        for (int i=0; i<len; i++) hash[S[i]-'a']++;
        int p = 0;
        for (int i=0; i<26; i++) {
            for (int j=0; j<hash[i]; j++) ret[p++] = i+'a';
        }
        ret[p] = 0;
        free(hash);
    }
    return ret;
}



