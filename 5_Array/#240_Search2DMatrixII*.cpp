//#240. Search a 2D Matrix II
//Medium
//Method: 
//Complexity: 

class Solution {
public:
    //Method 1: search diagonally. there is always only one direction because otherwise it would have 2 directions to go earlier.
    //O(M+N)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = 0, n = matrix[0].size() - 1;
        while (m < matrix.size() && n >= 0) {
            if (matrix[m][n] == target) return true;
            if (matrix[m][n] < target) ++m;
            else --n;
        }
        return false;
    }

    //Method 2: binary search every row whose first element is smaller than target.
    // can be furthurly optimized by tracking the end of last row.
    //O(MlogN)
    int high;
    bool subSearch(vector<int>& vec, int target, int low) {
        int mid = (low + high) / 2;
        if (vec[mid] == target) return true;
        if (mid == low) return false;
        if (vec[mid] > target) {
            high = mid;
            return subSearch(vec, target, low);
        }
        return subSearch(vec, target, mid + 1);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        high = n;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] <= target) {
                if (subSearch(matrix[i], target, 0)) return true;
            }
            else
                break;
        }
        return false;
    }
};