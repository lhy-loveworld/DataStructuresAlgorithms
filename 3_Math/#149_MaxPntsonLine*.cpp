//#149. Max Points on a Line
//Hard
//Method: unordered_map of pairs, overload of operators
//Complexity: Time O(N^2); Space O(N^2)

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

bool operator< (Point &a, Point &b) {
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}

bool operator== ( Point &a, Point &b) {
    return a.x == b.x && a.y == b.y;
}

struct HashFunc {
    size_t operator() (const pair<int, int> &p) const {
        return (p.first ^ p.second);
    }
};

class Solution {
public:
    //Use greatest common divisor to substitute double type slopes
    int FindGCD(int a, int b) {
        if (b == 0) return a;
        if (a % b == 0) return b;
        else return FindGCD(b, a % b);
    }
    
    int maxPoints(vector<Point>& points) {
        if (points.size() < 3) return points.size();
        sort(points.begin(), points.end());
        int res = 2;
        for (int i = 0; i < points.size() - res; ++i) {
            int dup1 = 1, max_slo = 0;
            unordered_map<pair<int, int>, int, HashFunc> slopes;
            while (points[i + 1] == points[i]) {
                i++;
                dup1++;
            }
            res = max(res, dup1);
            for (int j = i + 1; j < points.size(); ++j) {
                int dup2 = 1;
                while (j < points.size() - 1 && points[j + 1] == points[j]) {
                    j++;
                    dup2++;
                }
                int GCD = FindGCD(points[j].y - points[i].y, points[j].x - points[i].x);
                pair<int, int> slo((points[j].y - points[i].y) / GCD, (points[j].x - points[i].x) / GCD);
                slopes[slo] += dup2;
                res = max(res, slopes[slo] + dup1);
            }
        }
        return res;
    }
};