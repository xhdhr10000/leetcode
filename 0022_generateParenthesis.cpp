// Author: xhdhr10000
// Date: 2020-04-09

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<bool> hash(pow(2, 2*n+1), false);
        vector<string> q;
        vector<string> ans;

        q.push_back("");
        hash[stringToBinary("")] = true;
        for (int i=0; i<q.size(); i++) {
            string s = q[i];
            if (s.size() == 2*n) {
                ans.push_back(digitsToBrackets(s));
                continue;
            }

            string ns = "1" + s + "0";
            unsigned long h = stringToBinary(ns);
            if (!hash[h]) { q.push_back(ns); hash[h] = true; }

            for (int j=0; j<s.size(); j++) {
                ns = s.substr(0, j) + "10" + s.substr(j);
                h = stringToBinary(ns);
                if (!hash[h]) { q.push_back(ns); hash[h] = true; }
            }
        }

        return ans;
    }
private:
    unsigned long stringToBinary(string s) {
        bitset<sizeof(int)*8> b(s);
        return b.to_ulong();
    }

    string digitsToBrackets(string s) {
        string d = "";
        for (char c : s) d += c == '1' ? '(' : ')';
        return d;
    }
};
