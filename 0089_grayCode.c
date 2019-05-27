// Author: xhdhr10000
// Date: 2019-05-27
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

const int seq[4] = {0, 1, 3, 2};

void generate(int n, int x, int *d, int *c) {
    if (n < 0) {
        d[*c] = x;
        (*c)++;
    } else if (n%2 == 0) {
        for (int i=0; i<2; i++) {
            x = (x & ~(1 << n)) | (i << n);
            generate(n-1, x, d, c);
        }
    } else {
        int j = *c==0 ? 0 : seq[(d[*c-1] >> (n-1)) & 3];
        for (int i=0; i<4; i++, j=(j+1)%4) {
            x = (x & ~(3 << (n-1))) | (seq[j] << (n-1));
            generate(n-2, x, d, c);
        }
    }
}

int* grayCode(int n, int* returnSize){
    int *ret = (int*)malloc(sizeof(int)*(1<<n));
    if (n == 0) {
        *returnSize = 1;
        ret[0] = 0;
    } else if (n == 1) {
        *returnSize = 2;
        ret[0] = 0;
        ret[1] = 1;
    } else {
        *returnSize = 0;
        generate(n-1, 0, ret, returnSize);
        
        /* verification
        */
        for (int i=1; i<1<<n; i++) {
            int a = ret[i] ^ ret[i-1];
            if (a & a-1) printf("Error at %d: %d -> %d\n", i, ret[i-1], ret[i]);
        }
    }
    
    return ret;
}


int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    int size = 0;
    int *ret = grayCode(n, &size);
    free(ret);
    return 0;
}
