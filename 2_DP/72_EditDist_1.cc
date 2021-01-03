// #72 Edit Distance
// Hard
// Method: DP. dp[m][n] means the edit distance from word1[0:m] to word2[0:n].
// if word1[m] == word2[n] dp[m][n] = dp[m-1][n-1]
// else dp[m][n] = min(dp[m][n-1] + 1, // insert at back
//                     dp[m-1][n-1] + 1, // replace back
//                     dp[m+1][n] + 1) // delete at back
// Time complexity: O(M*N)
// Space complexity: O(N)

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<int> helper(n + 1, 0);
    int prev;
    for (int i = 1; i <= n; ++i)
      helper[i] = i;
      for (int i = 1; i <= m; ++i) {
        prev = helper[0];
        helper[0] = i;
        for (int j = 1; j <= n; ++j) {
	  swap(helper[j], prev);
          if (word1[i - 1] != word2[j - 1]) helper[j] = min(helper[j - 1] + 1, min(prev + 1, helper[j] + 1));
        }
      }
    return helper.back();
  }
};
