// Author: xhdhr10000
// Date: 2019-05-06
#include <math.h>

int calDiff(int d, int a, int b, int *e, int ce) {
    if (b<a) return 0;
    int ret = b-a+1;
    for (int j=a; j<=b; j++)
        if (e[j] > 0) ret--;
    for (int i=1; i<d; i++) {
        ret *= 10-ce-i;
    }
    return ret;
}

int digits(int n) {
    int ret = 0;
    while (n) {
        n /= 10;
        ret++;
    }
    return ret;
}

int getDigit(int n, int i) {
    return (n / (int)pow(10, i-1)) % 10; 
}

int numDupDigitsAtMostN(int N){
    int ret = 0;
    int ds = digits(N);
    int e[10], ce=0;
    memset(e, 0, sizeof(e));
    for (int i=1; i<ds; i++) ret += calDiff(i, 1, 9, e, ce);
    for (int i=ds; i>0; i--) {
        int b = getDigit(N, i);
        ret += calDiff(i, (i==ds)?1:0, (i==1)?b:b-1, e, ce);
        if (e[b] != 0) break;
        ce++;
        e[b]++;
    }
    return N - ret;
}



