// Author: xhdhr10000
// Date: 2020-01-29

class Solution {
public:
    string addStrings(string num1, string num2) {
        int inc = 0, i;
        int l1 = std::min(num1.size(), num2.size());
        int l2 = std::max(num1.size(), num2.size());
        string ret = "";
        ret.reserve(l2+1);

        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        for (i=0; i<l1; i++) {
            ret.push_back((num1[i] + num2[i] - 2*'0' + inc) % 10 + '0');
            inc = (num1[i] + num2[i] - 2*'0' + inc) / 10;
        }
        for (; i<l2; i++) {
            ret.push_back(((i < num1.size() ? num1[i] : num2[i]) - '0' + inc) % 10 + '0');
            inc = ((i < num1.size() ? num1[i] : num2[i]) - '0' + inc) / 10;
        }
        if (inc) ret.push_back(inc + '0');
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
}
