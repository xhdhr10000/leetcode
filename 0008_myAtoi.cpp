// Author: xhdhr10000
// Date: 2020-04-03

class Solution {
public:
    int myAtoi(string str) {
        if (str.front() == ' ') str.erase(0, str.find_first_not_of(' '));
        if (str.size() == 0) return 0;

        unsigned int ret = 0;
        bool negtive = false;

        if (str.front() == '-' || str.front() == '+') {
            negtive = str.front() == '-';
            str.erase(0, 1);
        }
        if (str.front() < '0' || str.front() > '9') return 0;
        for (char c : str) {
            if (c < '0' || c > '9') break;
            if (ret > threshold ||
                ret == threshold && c > (negtive ? '8' : '7'))
                return negtive ? INT_MIN : INT_MAX;
            ret = ret*10 + c-'0';
        }

        return negtive ? -ret : ret;
    }
private:
    const int threshold = INT_MAX / 10;
};
