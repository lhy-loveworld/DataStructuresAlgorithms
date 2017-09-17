//#221 Maximal Square
//Medium
//Method: How a square grows
//Time complexity: O(M*N)
//Space complexity: O(N)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<int> helper1(matrix.front().size(), 0);
        vector<int> helper2(matrix.front().size(), 0);
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            helper2[0] = matrix[i][0] - '0';
            res = max(res, helper2[0]);
            for (int j = 1; j < helper2.size(); ++j) {
                if (matrix[i][j] == '1') {
                    helper2[j] = min(min(helper2[j - 1], helper1[j - 1]), helper1[j]) + 1;
                    res = max(res, helper2[j]);
                } else
                    helper2[j] = 0;
            }
            helper1 = helper2;
        }
        return res * res;
    }
};