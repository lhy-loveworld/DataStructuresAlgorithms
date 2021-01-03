//#322_Coin Change
//Medium
//Method: DP, two methods
//Time complexity: O(N*amount) O(amount ~ N*amount)
//Space complexity: O(amount) O(amount)

class Solution {
 public:
  // Method 1: dynamic DP
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    std::vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (int j : coins) {
        if (j <= i && dp[i - j] >= 0) {
	  if (dp[i] < 0 || dp[i] > dp[i - j] + 1) dp[i] = dp[i - j] + 1;
        }
      }
    }
    return dp.back();
  }

  // Method 2: BFS
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

  // Method 3: recursion with memoisation.
  std::vector<int> memo_;
  int RecFind(const std::vector<int>& coins, int amount) {
    if (memo_[amount - 1] >= 0) return memo_[amount - 1];
    for (int i : coins) {
      if (i == amount) {
        memo_[amount - 1] = 1;
        return 1;
      }
      if (i < amount) {
        int tmp = RecFind(coins, amount - i);
        if (tmp > 0 && (memo_[amount - 1] < 0 || memo_[amount - 1] > tmp + 1)) {
            memo_[amount - 1] = tmp + 1;
        }
      }
    }
    if (memo_[amount - 1] < 0) {
      memo_[amount - 1] = 0;
    }
    return memo_[amount - 1];
  }
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    memo_ = std::vector<int>(amount, -1);
    return RecFind(coins, amount) == 0 ? -1 : RecFind(coins, amount);
  }
};
