// Author: xhdhr10000
// Date: 2020-04-10

class Solution {
public:
    string reverseWords(string s) {
        vector<string> stack;
        istringstream is(s);
        ostringstream os;
        string word;

        while (is >> word) stack.push_back(word);
        while (!stack.empty()) { os << stack.back() << " "; stack.pop_back(); }

        string ret = os.str();
        if (ret.size() != 0) ret.erase(ret.size()-1, 1);
        return ret;
    }
};
