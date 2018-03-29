//#296. Best Meeting Point
//Hard
//Method: Choose the median
//Complexity: Time O(N^2); Space O(N^2)

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<int> rows, columns;
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }
        if (rows.empty()) return 0;
        sort(columns.begin(), columns.end());
        for (int i = 0; i < rows.size() / 2; ++i) {
            res += rows[rows.size() - 1 - i] - rows[i] + columns[rows.size() - 1 - i] - columns[i];
        }
        return res;
    }
};