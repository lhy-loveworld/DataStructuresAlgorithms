//#64_Minimum Path Sum
//Medium
//Method: DP, caution for corner case
//Time complexity: O(M*N)
//Space complexity: O(M*N)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int col = grid.back().size();
        for (int i = 1; i < col; ++i) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < grid.size(); ++i) {
            grid[i][0] += grid[i - 1][0];
            for (int j = 1; j < col; ++j) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid.back().back();
    }
};