//#121
//Easy
//Arthor: lhy-loveworld
//Method: Two methods
//Complexity: time O(N) space O(1)

class Solution {
public:
    //Record the current minimum
    int maxProfit(vector<int>& prices) {
        int res = 0, Min = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < Min) {
                Min = prices[i];
            } else {
                res = max(res, prices[i] - Min);
            }
        }
        return res;
    }

    //Same as the max sum of subsequence
    int maxProfit(vector<int>& prices) {
        int res = 0, Max = 0;
        for (int i = 1; i < prices.size(); ++i) {
            Max = max(0, Max += prices[i] - prices[i - 1]);
            res = max(res, Max);
        }
        return res;
    }
};