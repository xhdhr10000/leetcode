// Author: xhdhr10000
// Date: 2020-04-08

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isLetterOrDigit(s[l])) l++;
            while (l < r && !isLetterOrDigit(s[r])) r--;
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++; r--;
        }
        return true;
    }
private:
    bool isLetterOrDigit(char c) {
        return c >= '0' && c <= '9' ||
               c >= 'A' && c <= 'Z' ||
               c >= 'a' && c <= 'z';
    }
};
