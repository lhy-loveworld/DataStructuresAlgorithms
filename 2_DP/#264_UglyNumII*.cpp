//#264 Ugly Number II
//Medium
//Method: DP, caution for the corner case such as 6, 10 and so on.
//        Can use static members to speed up
//Time complexity: O(N)
//Space complexity: O(N)

class Solution {
    
public:
    static vector<int> helper;
        static int p2, p3, p5;
        
    int nthUglyNumber(int n) {
        while (helper.size() < n) {
            int r = min(min(helper[p2] * 2, helper[p3] * 3), helper[p5] * 5);
            helper.push_back(r);
            if (r == helper[p2] * 2) ++p2;
            if (r == helper[p3] * 3) ++p3;
            if (r == helper[p5] * 5) ++p5;
        }
        return helper[n - 1];
    }
};

vector<int> Solution::helper = {1};
int Solution::p2 = 0, Solution::p3 = 0, Solution::p5 = 0;