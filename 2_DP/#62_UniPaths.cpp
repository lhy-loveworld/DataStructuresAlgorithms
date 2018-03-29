//#62_Unique Paths
//Medium
//Method: DP
//Time complexity: O(M*N)
//Space complexity: O(M*N)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> helper(2, vector<int> (n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                helper[1][j] = helper[0][j] + helper[1][j - 1];
            }
            helper[0] = helper[1];
        }
        return helper[0].back();
    }
};