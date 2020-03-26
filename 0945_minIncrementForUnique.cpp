// Author: xhdhr10000
// Date: 2020-03-22

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        bool hash[80000];
        int count = 0;
        memset(hash, 0, sizeof(hash));
        for (int i : A) {
            while (hash[i]) {
                i++;
                count++;
            }
            hash[i] = true;
        }
        return count;
    }
};
