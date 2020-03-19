// Author: xhdhr10000
// Date: 2020-03-19

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if (points.size() <= 3) return points;
        list<int> border = { 0, 1, 2 };

        for (int i=3; i<points.size(); i++) {
            auto &p = points[i];
            bool found = false, blank = false;
            // cout << "Point " << i << endl;
            for (auto b=border.begin(); b != border.end(); b++) {
                // cout << "Border " << *b << endl;
                auto pStart = b;
                auto pEnd   = next(border, pStart);
                if (*pEnd == i) break;
                auto pOther = next(border, pEnd);
                while ((*pOther == i || lineSide(points[*pStart], points[*pEnd], points[*pOther]) == 0) &&
                       next(border, pOther) != pStart)
                    pOther = next(border, pOther);
                if (needChange(points[*pStart], points[*pEnd], p, points[*pOther])) {
                    if (found) {
                        // cout << "Remove " << (blank ? *pEnd : *pStart) << endl;
                        b--;
                        border.erase(blank ? pEnd : pStart);
                        if (border.size() <= 3) break;
                    } else {
                        // cout << "Insert " << i << " between " << *pStart << ", " << *pEnd << endl;
                        found = true;
                        border.insert(pEnd, i);
                        if (next(border, b) != border.begin()) b++;
                    }
                } else if (found) blank = true;
            }
        }

        vector<vector<int>> ret;
        for (auto &b : border) ret.push_back(points[b]);
        return ret;
    }
private:
    bool needChange(vector<int> &s, vector<int> &e, vector<int> &n, vector<int> &o) {
        return onSegment(s, e, n) || onSegment(s, e, o) || lineSide(s, e, o) * lineSide(s, e, n) < 0;
    }

    bool onSegment(vector<int> &s, vector<int> &e, vector<int> &p) {
        return (p[1]-s[1])*(e[0]-s[0]) - (p[0]-s[0])*(e[1]-s[1]) == 0 &&
               p[0] >= min(s[0], e[0]) && p[0] <= max(s[0], e[0]) &&
               p[1] >= min(s[1], e[1]) && p[1] <= max(s[1], e[1]);
    }

    int lineSide(vector<int> &s, vector<int> &e, vector<int> &p) {
        // (y-y0)*(x1-x0) - (x-x0)*(y1-y0) = 0
        return (p[1]-s[1])*(e[0]-s[0]) - (p[0]-s[0])*(e[1]-s[1]);
    }

    list<int>::iterator prev(list<int> &l, const list<int>::iterator &it) {
        return it == l.begin() ? std::prev(l.end()) : std::prev(it);
    }

    list<int>::iterator next(list<int> &l, const list<int>::iterator &it) {
        return std::next(it) == l.end() ? l.begin() : std::next(it);
    }
};
