//#256
//Easy
//Arthor: lhy-loveworld
//Method: Tradeoff between space and time, DP
//        Caution that cannot directly use [] to access a vector and min can only take 2 arguments
//        And no need to store interim values
//Complexity: time O(N) space O(N)

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int res0 = costs[0][0], res1 = costs[0][1], res2 = costs[0][2];
        for (int i = 1; i < costs.size(); ++i) {
            int tmp0 = res0, tmp1 = res1;
            res0 = min(res1, res2) + costs[i][0];
            res1 = min(tmp0, res2) + costs[i][1];
            res2 = min(tmp0, tmp1) + costs[i][2];
        }
        return min(min(res0, res1), res2);
    }
};