// Author: xhdhr10000
// Date: 2019-12-19
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        unsigned int sum = 0;
        int cur = 0;
        for (int i=0; i<n; i++) {
            sum += A[i];
            cur += i * A[i];
        }
        int max = cur;
        for (int i=n-1; i>0; i--) {
            cur += sum-A[i] - (n-1)*A[i];
            max = std::max(max, cur);
        }
        return max;
    }
};
