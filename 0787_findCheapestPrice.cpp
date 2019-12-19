// Author: xhdhr10000
// Date: 2019-12-19
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        std::sort(flights.begin(), flights.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        vector<int> indices;
        for (int i=0; i<flights.size(); i++) {
            while (flights[i][0] >= indices.size()) indices.push_back(i);
        }
        while (n >= indices.size()) indices.push_back(flights.size());

        int ans = 0x7fffffff;
        std::queue<Queue> q;
        q.emplace(src, 0, 0);
        while (!q.empty()) {
            Queue h = q.front(); q.pop();
            for (int i=indices[h.v]; i<indices[h.v+1]; i++) {
                int v = flights[i][1];
                int w = h.w + flights[i][2];
                int d = h.d + 1;
                if (v == dst) {
                    ans = std::min(ans, w);
                    continue;
                }
                if (d > K || w > ans) continue;
                q.emplace(v, w, d);
            }
        }
        return ans == 0x7fffffff ? -1 : ans;
    }

private:
    class Queue {
    public:
        int v; // vertex
        int w; // weight
        int d; // distance

        Queue(int v, int w, int d) : v(v), w(w), d(d) {}
    };
};
