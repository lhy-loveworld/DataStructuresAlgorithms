//#200. Number of Islands
//Medium
//Method: DFS
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    void findIsland(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        if (i > 0 && grid[i - 1][j] == '1') findIsland(grid, i - 1, j);
        if (j > 0 && grid[i][j - 1] == '1') findIsland(grid, i, j - 1);
        if (i < grid.size() - 1 && grid[i + 1][j] == '1') findIsland(grid, i + 1, j);
        if (j < grid[0].size() - 1 && grid[i][j + 1] == '1') findIsland(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.empty() || grid[0].empty()) return res;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    res++;
                    findIsland(grid, i, j);
                }
            }
        }
        return res;
    }
};