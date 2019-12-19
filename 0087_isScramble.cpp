// Author: xhdhr10000
// Date: 2019-12-19
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        if (s1 == s2) return true;
        int l = s1.length();
        for (int i=1; i<l; i++) {
            string s1l = s1.substr(0, i), s1r = s1.substr(i, l-i);
            string s2l = s2.substr(0, i), s2r = s2.substr(i, l-i);
            if (isSame(s1l, s2l) && isSame(s1r, s2r)) {
                if (isScramble(s1l, s2l) && isScramble(s1r, s2r)) return true;
            }
            string s2sl = s2.substr(l-i, i), s2sr = s2.substr(0, l-i);
            if (isSame(s1l, s2sl) && isSame(s1r, s2sr)) {
                if (isScramble(s1l, s2sl) && isScramble(s1r, s2sr)) return true;
            }
        }
        return false;
    }
private:
    bool isSame(string s1, string s2) {
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};
