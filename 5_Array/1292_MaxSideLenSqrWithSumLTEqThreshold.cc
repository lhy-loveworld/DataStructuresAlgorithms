// 1292. Maximum Side Length of a Square with Sum Less than or Equal to
// Threshold
// Medium
// TC: O(MN)
// SC: O(1)
class Solution {
 public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size(), n = mat[0].size();
    int res = 0;
    for (int i = 0; i < m; ++i) {
      bool need_find = true; // if we've already incremented res in the current
                             // row, we don't need to find it anymore.
      for (int j = 0; j < n; ++j) {

	// Calculate the sum between (0,0) and (i,j) inclusive.
	if (i > 0) {
          mat[i][j] += mat[i - 1][j];
	  if (j > 0) {
            mat[i][j] -= mat[i - 1][j - 1];
          }
        }
        if (j > 0) {
	  mat[i][j] += mat[i][j - 1];
        }

	// For each point (i,j), we are checking the square whose side len is
	// res+1 and bottom right point is (i,j).
        if (need_find && j >= res) {
          if (j == res || i == res) {
            if (mat[i][j] <= threshold) {
              res++;
              need_find = false;
            }
          } else if (mat[i][j] + mat[i - res - 1][j - res - 1]
		     - mat[i][j - res - 1] - mat[i - res - 1][j] <= threshold) {
            res++;
            need_find = false;
          }
        }
      }
    }
    return res;
  }
};
