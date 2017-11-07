//#329. Longest Increasing Path in a Matrix
//Hard
//Method: recursively and memoization
//Time complexity: O(M*N)
//Space complexity: O(M*N)

class Solution {
public:
    int CurPath(int i, int j, int m, int n, vector<vector<int> >& helper, vector<vector<int>>& matrix) {
        if (helper[i][j])
            return helper[i][j];
        int Max = 0;
        if (i > 0 && matrix[i][j] < matrix[i - 1][j])
            Max = max(Max, CurPath(i - 1, j, m, n, helper, matrix));
        if (i < m - 1 && matrix[i][j] < matrix[i + 1][j])
            Max = max(Max, CurPath(i + 1, j, m, n, helper, matrix));
        if (j < n - 1 && matrix[i][j] < matrix[i][j + 1])
            Max = max(Max, CurPath(i, j + 1, m, n, helper, matrix));
        if (j > 0 && matrix[i][j] < matrix[i][j - 1])
            Max = max(Max, CurPath(i, j - 1, m, n, helper, matrix));
        helper[i][j] = 1 + Max;
        return helper[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > helper(m, vector<int> (n, 0));
        int Max = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                Max = max(Max, CurPath(i, j, m, n, helper, matrix));
            }
        }
        return Max;
    }
};