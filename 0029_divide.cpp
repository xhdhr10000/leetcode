// Author: xhdhr10000
// Date: 2020-04-17

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negtive = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        unsigned int total = 0, b = abs(dividend);

        while (b >= abs(divisor)) {
            unsigned int count = 1, c = abs(divisor);
            while (b > c && b >= c + c) { c += c; count += count; }
            b -= c;
            total += count;
            if ((!negtive && total > INT_MAX) || (negtive && total > 0x80000000)) return INT_MAX;
        }
        return negtive ? -total : total;
    }
};
