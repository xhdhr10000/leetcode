// Author: xhdhr10000
// Date: 2019-05-06
#define MAX 100000
int distributeCandies(int* candies, int candiesSize){
    int hash[MAX*2+1], ret = 0;
    memset(hash, 0, sizeof(hash));
    for (int i=0; i<candiesSize; i++) {
        if (hash[candies[i]+MAX] == 0) ret++;
        hash[candies[i]+MAX]++;
        if (ret >= candiesSize / 2) break;
    }
    return ret;
}



