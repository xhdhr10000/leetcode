// Author: xhdhr10000
// Date: 2019-05-14
#include <stdio.h>
//#include <stdlib.h>

int reverse(int x){
    const int min = -0x80000000, max = 0x7fffffff;
    int sign = x<0 ? -1 : 1;
    __int64_t ret = 0, a = llabs(x);
    while (a) {
        ret = ret*10 + a%10;
        a /= 10;
    }
    if (sign*ret < min || sign*ret > max) return 0;
    return sign*ret;
}


int main() {
    int a = 123;
    printf("%d\n", reverse(a));
    return 0;
}
