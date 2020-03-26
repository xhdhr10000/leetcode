// Author: xhdhr10000
// date: 2020-03-24

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ret;
        double max = 0, sum = 0;
        int maxp, n = 0, hn = 0, hs = -1;
        for (int i=0; i<count.size(); i++) {
            if (count[i] == 0) continue;
            if (ret.size() == 0) ret.push_back(i);
            if (ret.size() == 1) ret.push_back(i);
            else ret[1] = i;
            if (count[i] > max) {
                max = count[i];
                maxp = i;
            }
            n += count[i];
            sum += (double)i * count[i];
        }
        ret.push_back(sum / n);
        for (int i=0; i<count.size(); i++) {
            if (count[i] == 0) continue;
            if (hn + count[i] < n / 2) hn += count[i];
            else {
                if (n % 2 != 0) {
                    if (hn + count[i] >= n/2+1) {
                        ret.push_back(i);
                        break;
                    } else hn += count[i];
                } else {
                    if (hn + count[i] == n/2) {
                        hs = i;
                        hn += count[i];
                    } else if (hn + count[i] >= n/2+1) {
                        ret.push_back(hs == -1 ? i : (double)(hs+i)/2);
                        break;
                    }
                }
            }
        }
        ret.push_back(maxp);
        return ret;
    }
};
