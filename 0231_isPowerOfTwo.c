bool isPowerOfTwo(int n){
    if (n <= 0) return false;
    if (n == 1) return true;
    n--;
    while (n & 1) n >>= 1;
    return n==0;
}
