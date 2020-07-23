// Author: xhdhr10000
// Date: 2020-04-08

class Solution {
public:
    int mySqrt(int x) {
        int64_t i = 1;
        while (i * i <= x) i++;
        return i - 1;
    }
};
