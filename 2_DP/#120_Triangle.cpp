//#120_Triangle
//Medium
//Method: Can consider from both directions.
//Time complexity: O(N+#query)
//Space complexity: O(N)

class Solution {
public:
    //regular order
    int minimumTotal(vector<vector<int>>& triangle) {
        int res = INT_MAX;
        vector<int> path(triangle.size(), 0);
        path[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            int tmp = path[0];
            path[0] += triangle[i][0];
            for (int j = 1; j < i; ++j) {
                swap(tmp, path[j]);
                path[j] = min(tmp, path[j]) + triangle[i][j];
            }
            path[i] = tmp + triangle[i][i];
        }
        for (int i = 0; i < triangle.size(); ++i) {
            res = min(res, path[i]);
        }
        return res;
    }

    //inverse order
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<int> helper(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                helper[j] = min(helper[j], helper[j + 1]) + triangle[i][j];
            }
        }
        return helper[0];
    }
};