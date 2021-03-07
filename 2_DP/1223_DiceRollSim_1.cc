// 1223. Dice Roll Simulation
// Medium
class Solution {
 public:
  // Method 1: DP. dp[i][j] means # of valid sequence with length of i and
  // ending with j+1. sum[i] means the total # of valid sequences with length of
  // i.
  // TC: O(N) if rollMax[i] << n
  // SC: O(N)
  int dieSimulator(int n, vector<int>& rollMax) {
    std::vector<std::vector<long>> dp(n+1, std::vector<long>(6));
    std::vector<long> sum(n+1);
    int m = 1000000007;
    sum[0] = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 6; ++j) {
        if (i + 1 <= rollMax[j]) {
          dp[i][j] = 1;
        }
        for (int k = 1; k <= rollMax[j] && k < i + 1; ++k) {
          dp[i][j] = (dp[i][j] + sum[i-k] - dp[i-k][j] + m) % m;
        }
        sum[i] = (sum[i] + dp[i][j]) % m;
      }
    }
    return sum[n];
  }

  // Method 2: Could use recursion with memoisation for the same logic.
};
