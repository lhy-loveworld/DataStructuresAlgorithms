//#308. Range Sum Query 2D - Mutable
//Hard
//Method: use bit manipulation in 2D
//Complexity: time O(logNlogM) for both. space O(MN)

class NumMatrix {
  vector<vector<int> > originMat;
  vector<vector<int> > sumMat;
  int rows, cols;
public:
    NumMatrix(vector<vector<int>> matrix) {
      if (matrix.empty() || matrix[0].empty()) return;
        rows = matrix.size();
      cols = matrix[0].size();
        originMat = vector<vector<int> > {rows, vector<int>(cols)};
      sumMat = vector<vector<int> > {rows, vector<int>(cols)};
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
          update(i, j, matrix[i][j]);
        }
      }
    }
    
    void update(int row, int col, int val) {
        int diff = val - originMat[row][col];
      originMat[row][col] = val;
      while (row < rows) {
        int tmp = col;
        while (tmp < cols) {
          sumMat[row][tmp] += diff;
          tmp |= tmp + 1;
        }
        row |= row + 1;
      }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
          int res = 0;
          while (row2 >= 0) {
            int tmp = col2;
            while (tmp >= 0) {
              res += sumMat[row2][tmp];
              tmp = (tmp & (tmp + 1)) - 1;
            }
            row2 = (row2 & (row2 + 1)) - 1;
          }
          return res;
        }
      if (row1 == 0) return sumRegion(0, 0, row2, col2) - sumRegion(0, 0, row2, col1 - 1);
      if (col1 == 0) return sumRegion(0, 0, row2, col2) - sumRegion(0, 0, row1 - 1, col2);
      return sumRegion(0, 0, row2, col2) + sumRegion(0, 0, row1 - 1, col1 - 1) - sumRegion(0, 0, row2, col1 - 1) - sumRegion(0, 0, row1 - 1, col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */