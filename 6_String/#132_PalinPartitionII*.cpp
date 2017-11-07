//#132. Palindrome Partitioning II
//Hard
//Method: DP, palindrome needs to think from center
//Complexity: Time O(N to N^2); Space O(N)

class Solution {
public:
    int minCut(string s) {
        if (s.size() < 2) return 0;
        vector<int> dp(s.size() + 1, INT_MAX);
        dp[0] = -1;
        for (int i = 0; i < s.size(); ++i) {
            dp[i + 1] = min(dp[i + 1], i);
            for (int j = 0; i- j >= 0 && i + j < s.size() && s[i - j] == s[i + j]; ++j)
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
            for (int j = 0; i- j >= 0 && i + j + 1 < s.size() && s[i - j] == s[i + j + 1]; ++j)
                dp[i + j + 2] = min(dp[i + j + 2], dp[i - j] + 1);
        }
        return dp.back();
    }
};