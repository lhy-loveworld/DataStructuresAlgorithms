//#48. Rotate Image
//Medium
//Method: Reverse
//Complexity: Time O(N2); Space O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() - 1; ++i) {
            for (int j = 0; j < matrix.size() - 1 - i; ++j) {
                swap(matrix[i][j], matrix[matrix.size() - 1 - j][matrix.size() - 1 - i]);
            }
        }
        reverse(matrix.begin(), matrix.end());
    }
};