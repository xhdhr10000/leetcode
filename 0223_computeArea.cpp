// Author: xhdhr10000
// Date: 2020-07-23

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int64_t w = max((int64_t)min(C, G) - max(A, E), (int64_t)0);
        int64_t h = max((int64_t)min(D, H) - max(B, F), (int64_t)0);
        return (C - A) * (D - B) - w * h + (G - E) * (H - F);
    }
};
