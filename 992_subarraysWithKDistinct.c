// Author: xhdhr10000
// Date: 2019-05-04
int subarraysWithKDistinct(int* A, int ASize, int K){
    int count = 0;
    int *hash = (int*)malloc(sizeof(int)*(ASize+1)), diff=0, j=0;
    
    memset(hash, 0, sizeof(int)*(ASize+1));
    for (int i=0; i<ASize; i++) {
        if (i>0) {
            hash[A[i-1]]--;
            if (hash[A[i-1]] == 0) diff--;
        }
        while (j >= i && diff >= K) {
            j--;
            hash[A[j]]--;
            if (hash[A[j]] == 0) diff--;
        }
        for (; j<ASize; j++) {
            if (diff > K) break;
            if (hash[A[j]] == 0) diff++;
            hash[A[j]]++;
            if (diff == K) count++;
        }
    }
    free(hash);
    return count;
}



