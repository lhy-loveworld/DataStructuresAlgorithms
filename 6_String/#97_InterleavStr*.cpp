//#97. Interleaving String
//Hard
//Method: DP. Every bool indicates whether first i char from s1 and first j char from s2 can form first (i + j) char from s3 with any kind of interleaving
//          Can be further optimized to space complexity of O(M or N)
//Complexity: Time O(MN); Space O(MN)

class Solution {
public:
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
};