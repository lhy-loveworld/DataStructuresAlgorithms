//#264 Ugly Number ||
//Medium
//Method: DP, caution for the corner case such as 6, 10 and so on.
//Time complexity: O(N)
//Space complexity: O(N)

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> helper(1, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = helper.size(); i < n; ++i) {
            int r = min(min(helper[p2] * 2, helper[p3] * 3), helper[p5] * 5);
            helper.push_back(r);
            if (r == helper[p2] * 2) ++p2;
            if (r == helper[p3] * 3) ++p3;
            if (r == helper[p5] * 5) ++p5;
        }
        return helper.back();
    }
};