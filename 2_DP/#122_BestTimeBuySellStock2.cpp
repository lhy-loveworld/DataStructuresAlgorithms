//#122. Best Time to Buy and Sell Stock II
//Easy
//Method: dp
//Time complexity: O(N)
//Space complexity: O(N)

class Solution {
public:
    //Method 1:
    //DP, sell: max profit under the circumstance of sell status at the end of day
    //    buy: max profit under the circumstance of buy status
    int maxProfit(vector<int>& prices) {
        int sell = 0, buy = INT_MIN;
        for (int i: prices) {
            int p_sell = sell;
            sell = max(sell, buy + i);
            buy = max(buy, p_sell - i);
        }
        return sell;
    }

    //Method 2:
    //Directly calculate the max intervals between adjacent days
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};