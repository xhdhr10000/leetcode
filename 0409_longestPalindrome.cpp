// Author: xhdhr10000
// Date: 2020-03-19

class Solution {
public:
    int longestPalindrome(string s) {
        int count[52];
        memset(count, 0, sizeof count);
        for (char c : s) {
            if (c <= 'Z') count[c-'A']++;
            else count[c-'a'+26]++;
        }

        bool odd = false;
        int ans = 0;
        for (int c : count) {
            if (c % 2 != 0) {
                odd = true;
                ans += c-1;
            } else ans += c;
        }
        if (odd) ans++;
        return ans;
    }
};
