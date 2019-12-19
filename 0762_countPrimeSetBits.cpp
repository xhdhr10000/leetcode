// Author: xhdhr10000
// Date: 2019-12-19

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int ret = 0;
        for (int i=L; i<=R; i++) ret += isBitsPrime(i);
        return ret;
    }
private:
    int isBitsPrime(int x) {
        int c = 0;
        while (x) {
            c += x & 1;
            x >>= 1;
        }
        return isPrime[c];
    }

    int isPrime[21] = { 
        0, 0, 1, 1, 0, 1, 0,
        1, 0, 0, 0, 1, 0, 1,
        0, 0, 0, 1, 0, 1, 0 };
};
