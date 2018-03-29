//#322_Coin Change
//Medium
//Method: DP, two methods
//Time complexity: O(N*amount) O(amount ~ N*amount)
//Space complexity: O(amount) O(amount)

class Solution {
public:
    //Method 1: dynamic DP
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0 || coins.empty()) return -1;
        vector<int> helper(amount + 1, amount + 1);
        helper[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    helper[i] = min(helper[i], helper[i - coins[j]] + 1);
                }
            }
        }
        return helper[amount] > amount ? -1 : helper[amount];
    }

    //Method 2: BFS

    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0 || coins.empty()) return -1;
        if (amount == 0) return 0;
        vector<int> helper(amount, -1); //the reason we need to use helper is to reduce repitition work
        queue<int> helpQ;
        for (int i = 0; i < coins.size(); ++i) {
            if (coins[i] > amount) continue;    //the reason why we don't use break is that coins may not be in ascending order
            helper[coins[i] - 1] = 1;
            helpQ.push(coins[i]);
        }
        int curr = 2;
        while (helper[amount - 1] < 0 && !helpQ.empty()) {
            int rnd = helpQ.size();
            for (int i = 0; i < rnd; ++i) {
                int currn = helpQ.front();
                helpQ.pop();
                for (int j = 0; j < coins.size(); ++j) {
                    if (coins[j] > amount || currn + coins[j] > amount) continue;
                    if (helper[currn + coins[j] - 1] < 0) {
                        helper[currn + coins[j] - 1] = curr;
                        helpQ.push(currn + coins[j]);
                    }
                }
            }
            curr++;
        }
        return helper[amount - 1];
    }
};