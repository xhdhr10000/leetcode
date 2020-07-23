// Author: xhdhr10000
// Date: 2020-04-18

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "";
        bool negtive = (numerator ^ denominator) < 0 && numerator != 0;
        string ans = negtive ? "-" : "";
        unordered_map<int, int> index;

        int64_t up = abs(numerator), down = abs(denominator);
        ans += to_string(up / down);
        up = up % down * 10;
        if (up > 0) ans += '.';
        index[up] = ans.size();

        while (up > 0) {
            while (up < down) { up *= 10; ans += '0'; }
            int q = up / down;
            ans += to_string(q);

            up = up % down * 10;
            if (index.find(up) != index.end()) {
                ans.insert(index[up], "(");
                ans += ')';
                break;
            }
            index[up] = ans.size();
        }

        return ans;
    }
};
