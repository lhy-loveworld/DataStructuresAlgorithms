//#85 Maximal Rectangle
//Hard
//Method: DP. Process row by row, treat rectangles as histograms.
//Time complexity: O(M*N)
//Space complexity: O(N)

class Solution {
public:
    //Method 1: Use stack to find the largest histogram
    //          store the position in the stack in ascending order of their height
    //          if there's a height lower than the previous ones, pop out and compute the area of rectangular with the poped height
    //          its end is fixed, its beginning depends on whether stack is empty or its current top
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n + 1, 0);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1')
                    ++h[j];
                else
                    h[j] = 0;
            }
            stack<int> S;
            for (int j = 0; j < n + 1; ++j) {
                if (S.empty() || h[S.top()] <= h[j])
                    S.push(j);
                else {
                    int tmp = S.top();
                    S.pop();
                    res = max(h[tmp] * (S.empty() ? j : (j - S.top() - 1)), res);
                    --j;
                }
            }
        }
        return res;
    }

    //Method 2: Store the start and end point of each height.
    //          use 3 matrices to store the height of current column, the left end and the right end
    //          matrices can be simplified to vectors
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n, 0), l(n, 0), r(n, n);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            int cur_l = 0, cur_r = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++h[j];
                    l[j] = max(cur_l, l[j]);
                } else {
                    h[j] = 0;
                    cur_l = j + 1;
                    l[j] = 0;
                }
                if (matrix[i][n - j - 1] == '1') {
                    r[n - j - 1] = min(cur_r, r[n - j - 1]);
                } else {
                    r[n - j - 1] = n;
                    cur_r = n - j - 1;
                }
            }
            for (int j = 0; j < n; ++j) {
                res = max(res, h[j] * (r[j] - l[j]));
            }
        }
        return res;
    }
};