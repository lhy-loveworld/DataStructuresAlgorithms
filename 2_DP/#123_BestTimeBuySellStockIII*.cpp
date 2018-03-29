//#123. Best Time to Buy and Sell Stock III
//Hard
//Method: DP
//Time complexity: O(N)
//Space complexity: O(N) or O(1)

class Solution {
public:
    //Method 1: double loops, outer one is for times k, inner one is for each element,
    //          within each loop of k, the content of buy and sell became the optimum solution for 0 ~ k transactions
    //          buy[] means the max profit when we are at the buy status after element j, we may buy at j or prior to j
    //          sell[] means the max profit when we are at the sell status after j, we may sell at or prior to j
    //          buy is related to its previous one or the sell state of priors k
    //          sell is related to the previous buy and sell state at current k
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int res = 0;
        /*if (prices.size() < 6) {
            for (int i = 1; i < prices.size(); ++i) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }*/
        vector<int> buy(prices.size()), sell(prices.size());
        buy[0] = -prices[0];
        sell[0] = 0;
        for (int i = 1; i <= 2; ++i) {
            int prev = sell[0];
            for (int j = 1; j < prices.size(); ++j) {
                buy[j] = max(buy[j - 1], prev - prices[j]);
                prev = sell[j];
                sell[j] = max(buy[j - 1] + prices[j], sell[j - 1]);
                
            }
        }
        return sell.back();
    }

    //Method 2: Also double loops, since k = 2, we can use 3 states to represent it
    //          states[0] means when we are at the state of after first buy
    //          states[1] means when we are at the state of first sell or have done nothing
    //          states[2] means when we are at the state of first buy or second buy
    //          and the sell after states[2] is the result
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int res = 0;
        /*if (prices.size() < 6) {
            for (int i = 1; i < prices.size(); ++i) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }*/
        vector<int> states(3);
        states[2] = INT_MIN;
        states[1] = 0;
        states[0] = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            res = max(res, states[2] + prices[i]);
            states[2] = max(states[2], states[1] - prices[i]);
            states[1] = max(states[1], states[0] + prices[i]);
            states[0] = max(states[0], -prices[i]);
        }
        return res;
    }
};