// Author: xhdhr10000
// Date: 2020-03-16
class Solution {
public:
    string compressString(string S) {
        if (S.size() == 0) return S;
        string ans = "";
        for (int i=0; i < S.size();) {
            char c = S[i];
            int j = i;
            while (j < S.size() && S[j] == c) j++;
            ans += c + to_string(j-i);
            i = j;
        }
        return ans.size() < S.size() ? ans : S;
    }
};
