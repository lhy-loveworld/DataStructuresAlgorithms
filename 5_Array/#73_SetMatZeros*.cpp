//#73. Set Matrix Zeroes
//Medium
//Method: use a sign for each row and column to indicate whether they need to be set to zero
//          put the sign at the first row and first column, already visited, thus won't affect the result
//          cautious for the first column and first row, which might affect all the columns or rows
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int col1 = 1;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) col1 = 0;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++i) matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++j) matrix[i][j] = 0;
            }
            matrix[i][0] *= col1;
        }
    }
};