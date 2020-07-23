// Author: xhdhr10000
// Date: 2020-07-23

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        char *tok = std::strtok(sentence.data(), " ");
        int count = 0;
        while (tok) {
            count++;
            if (!std::strncmp(tok, searchWord.c_str(), searchWord.size())) return count;
            tok = strtok(NULL, " ");
        }
        return -1;
    }
};
