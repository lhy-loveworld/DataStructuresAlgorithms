//#463. Island Perimeter
//Easy
//Method: 
//Complexity: Time O(MN); Space O(1)

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    if (!i || !grid[i - 1][j]) res++;
                    if (!j || !grid[i][j - 1]) res++;
                    if ((i == grid.size() - 1) || !grid[i + 1][j]) res++;
                    if ((j == grid[0].size() - 1) || !grid[i][j + 1]) res++;
                }
            }
        }
        return res;
    }
};