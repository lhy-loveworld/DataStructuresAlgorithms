//#469. Convex Polygon
//Medium
//Method: cross product can be used to determine the relative direction of two vectors. x1y2 - x2y1
//Complexity: time O(n); space O(1)

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        if (points.size() < 3) return false;
        if (points.size() == 3) return true;
        int sign = 0;
        for (int i = 0; i < points.size(); ++i) {
            int cp = (points[(i + 1) % points.size()][0] - points[i][0]) * (points[(i + 2) % points.size()][1] - points[i][1]) - (points[(i + 2) % points.size()][0] - points[i][0]) * (points[(i + 1) % points.size()][1] - points[i][1]);
            if (cp == 0) continue; //may be 0
            if (sign != 0 && sign * cp < 0) return false;
            if (sign == 0) sign = cp / abs(cp);
        }
        return true;
    }
};