// #312. Burst Balloons
// Hard
// Method: DP. Each state is determined by the two boundaries. For example,
// when balloons within [a, b] is being bursted, a-1 and b+1 stays the same.
// The transition between states is done through the last ballon being bursted.
// For example, when a < c < b, dp[a][b] = dp[a][c-1] + dp[c+1][b] + nums[a-1] *
// nums[c] * nums[b+1].
// Complexity: Time O(N^3); Space O(N^2)

class Solution {
 public:
  // Method 1: complete the input vector, consume more space but save if clause
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int> > helper(n + 2, vector<int> (n + 2, 0));

    for (int len = 1; len <= n; ++len) {
      for (int start = 0; start + len < n + 1; ++start) {
        for (int last = start + 1; last < start + len + 1; ++last) {
	  helper[start][start + len + 1] = max(helper[start][start + len + 1], helper[start][last] + helper[last][start + len + 1] + nums[start] * nums[last] * nums[start + len + 1]);
        }
      }
    }
    return helper[0].back();
  }

  // Method 2: use if clause
  int maxCoins(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<vector<int> > helper(n, vector<int> (n, 0));
    for (int i = 0; i < n; ++i) {
      helper[i][i] = nums[i] * (i == 0 ? 1 : nums[i - 1]) * (i == n - 1 ? 1 : nums[i + 1]);
    }
    for (int len = 2; len <= n; ++len) {
      for (int start = 0; start <= n - len; ++start) {
	for (int last = start; last < start + len; ++last) {
          int cur = nums[last] * (start == 0 ? 1 : nums[start - 1]) * (start + len == n ? 1 : nums[start + len]);
          if (last != start) cur += helper[start][last - 1];
	  if (last != start + len - 1) cur += helper[last + 1][start + len - 1];
          helper[start][start + len - 1] = max(helper[start][start + len - 1], cur);
        }
      }
    }
    return helper[0].back();
  }

  // Method 3: memoisation and recursion.
  std::vector<std::vector<int>> memo_;
  int RecFind(const std::vector<int>& nums, int start, int end) {
    if (memo_[start][end] >= 0) return memo_[start][end];
    int res = 0;
    int left_edge = start - 1 < 0 ? 1 : nums[start - 1];
    int right_edge = end + 1 >= nums.size() ? 1 : nums[end + 1];
    for (int i = start; i <= end; ++i) { // The last ballon to be bursted.
      int total = left_edge * right_edge * nums[i];
      if (i - 1 >= start) total += RecFind(nums, start, i - 1);
      if (i + 1 <= end) total += RecFind(nums, i + 1, end);
      res = max(total, res);
    }
    memo_[start][end] = res;
    return res;
  }

  int maxCoins(vector<int>& nums) {
    memo_ = std::vector<std::vector<int>>(nums.size(), std::vector<int>(nums.size(), -1));
    return RecFind(nums, 0, nums.size() - 1); 
  }
};
