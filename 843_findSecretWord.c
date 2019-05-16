// Author: xhdhr10000
// Date: 2019-05-07
/**
 * *********************************************************************
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int guess(Master *, char *word);
 */

int sameness(char *w1, char *w2) {
    int same = 0;
    for (int i=0; i<strlen(w1); i++) {
        if (w1[i] == w2[i]) same++;
    }
    return same;
}

void findSecretWord(char** wordlist, int wordlistSize, Master* master) {
    char **candidates[2];
    int pc[2] = {0,0}, ppc = 0;
    
    candidates[0] = (char**)malloc(sizeof(char*)*wordlistSize);
    candidates[1] = (char**)malloc(sizeof(char*)*wordlistSize);
    for (int i=0; i<wordlistSize; i++) candidates[ppc][pc[ppc]++] = wordlist[i];
    
    int c = pc[ppc]/2;
    int same = guess(master, candidates[ppc][c]);
    while (same < 6) {
        pc[1-ppc] = 0;
        for (int i=0; i<pc[ppc]; i++) {
            if (i == c) continue;
            int s = sameness(candidates[ppc][i], candidates[ppc][c]);
            if (s == same) candidates[1-ppc][pc[1-ppc]++] = candidates[ppc][i];
        }
        ppc = 1-ppc;
        int i = pc[ppc]/2;
        int s = guess(master, candidates[ppc][i]);
        same = s;
        c = i;
    }
}
