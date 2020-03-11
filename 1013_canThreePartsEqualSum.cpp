// Author: xhdhr10000
// Date: 2020-03-11
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        vector<int> sum;
        int total = A[0], i;
        sum.push_back(A[0]);

        for (i=1; i<A.size(); i++) {
            total += A[i];
            sum.push_back(sum.back() + A[i]);
        }
        if (total % 3 != 0) return false;
        for (i=0; i<sum.size(); i++)
            if (sum[i] == total / 3) break;
        if (i == sum.size()) return false;
        for (i=i+1; i<sum.size(); i++)
            if (sum[i] == total / 3 * 2) break;
        if (i >= sum.size()-1) return false;
        return true;
    }
};
