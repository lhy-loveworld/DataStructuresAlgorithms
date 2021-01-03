//#309 Best Time to Buy and Sell Stock with Cooldown
//Medium
//Method: DP, find the variables to represent the states and deduce the transition function
//Time complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int buy = INT_MIN, sell1 = 0, sell2 = 0;
        //buy: buy stock at day i
        //sell1: sell stock at day i
        //sell2: sell stock previous to day i
        for (int i = 0; i < prices.size(); ++i) {
            int tmp = buy;
            buy = max(buy, sell2 - prices[i]);
            sell2 = max(sell1, sell2);
            sell1 = tmp + prices[i];
        }
        return max(sell2, sell1);
    }
};