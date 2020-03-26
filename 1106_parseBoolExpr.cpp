// Author: xhdhr10000
// Date: 2020-03-26

class Solution {
public:
    bool parseBoolExpr(string expression) {
        if (expression[0] == 't') return true;
        if (expression[0] == 'f') return false;

        int l = expression.size();
        if (expression[1] != '(' || expression[l-1] != ')') return false;

        // Remove nested brackets.
        string s = expression.substr(2, l-3);
        int left, right;
        while ((left = s.find('(')) != string::npos) {
            int count = 0;
            for (right=left+1; right < s.size() && (s[right] != ')' || count != 0); right++) {
                if (s[right] == '(') count++;
                if (s[right] == ')') count--;
            }
            s.replace(left-1, right-left+2, parseBoolExpr(s.substr(left-1, right-left+2)) ? "t" : "f");
        }

        if (expression[0] == '!') return !parseBoolExpr(s);
        else if (expression[0] == '&') return s.find('f') == string::npos;
        else if (expression[0] == '|') return s.find('t') != string::npos;
        return false;
    }
};
