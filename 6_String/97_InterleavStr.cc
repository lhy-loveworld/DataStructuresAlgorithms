// #97. Interleaving String
// Hard
// Method: DP. Every bool indicates whether first i char from s1 and first j char from s2 can form first (i + j) char from s3 with any kind of interleaving
//          Can be further optimized to space complexity of O(M or N)
// Complexity: Time O(MN); Space O(MN)
class Solution {
 public:
  // Method 1: backwards dp.
  bool isInterleave(string s1, string s2, string s3) {
    if (s3.size() != s1.size() + s2.size()) return false;
    vector<vector<bool>> helper(s1.size() + 1, vector<bool> (s2.size() + 1, false));
    for (int i = 0; i <= s1.size(); ++i) {
      for (int j = 0; j <= s2.size(); ++j) {
        helper[i][j] = i == 0 && j == 0 || i != 0 && helper[i - 1][j] && s1[i - 1] == s3[i + j - 1] || j != 0 && helper[i][j - 1] && s2[j - 1] == s3[i + j - 1];
      }
    }
    return helper.back().back();
  }

  // Method 2: forwards dp.
  bool isInterleave(string s1, string s2, string s3) {
    int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
    if (l1 + l2 != l3) return false;
    std::vector<std::vector<bool>> dp(l1 + 1, std::vector<bool>(l2 + 1));
    dp[0][0] = true;
    for (int i = 0; i < l1 + 1; ++i) {
      for (int j = 0; j < l2 + 1; ++j) {
	if (dp[i][j]) {
          if (i < l1 && s1[i] == s3[i+j]) {
            dp[i+1][j] = true;
          }
          if (j < l2 && s2[j] == s3[i+j]) {
	    dp[i][j+1] = true;
          }
        }
      }
    }
    return dp[l1][l2];
  }
};
