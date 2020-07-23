// Author: xhdhr10000
// Date: 2020-04-08

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cs(26, 0), ct(26, 0);
        for (char c : s) cs[c-'a']++;
        for (char c : t) ct[c-'a']++;
        return equal(cs.begin(), cs.end(), ct.begin());
    }
};
