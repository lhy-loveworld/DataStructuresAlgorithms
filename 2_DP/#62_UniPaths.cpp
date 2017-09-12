//#62_Unique Paths
//Medium
//Method: DP
//Time complexity: O(M*N)
//Space complexity: O(M*N)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> helper(m, vector<int> (n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                helper[i][j] = helper[i - 1][j] + helper[i][j - 1];
            }
        }
        return helper[m - 1][n - 1];
    }
};