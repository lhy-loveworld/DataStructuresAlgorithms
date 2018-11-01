//#832. Flipping an Image
//Easy
//Method: cautious about overflow
//Complexity: Time O(N^2); Space O(1)

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; 2 * j <= A[0].size() - 1; ++j) { //vector.size() is unsigned
                swap(A[i][j], A[i][A[0].size() - 1 - j]);
                A[i][j] ^= 1;
                if (j != A[0].size() - 1 - j) A[i][A[0].size() - 1 - j] ^= 1;
            }
        }
        return A;
    }
};