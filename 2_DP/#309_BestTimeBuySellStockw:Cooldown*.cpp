//#309 Best Time to Buy and Sell Stock with Cooldown
//Medium
//Method: DP, find the variables to represent the states and deduce the transition function
//Time complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p_buy = 0, buy = INT_MIN, p_sell = 0, sell = 0;
        for (int i = 0; i < prices.size(); ++i) {
            p_buy = buy;
            buy = max(buy, p_sell - prices[i]);
            p_sell = sell;
            sell = max(p_buy + prices[i], sell);
        }
        return sell;
    }
};