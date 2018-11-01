//#54. Spiral Matrix
//Medium
//Method: 
//Complexity: Time O(MN); Space O(1)

class Solution {
    //Method 1: recursion, note the boarder width
    vector<int> res;
    void spiralOrderUtil(vector<vector<int>>& m, int i, int j, int d, int t) {
        res.push_back(m[i][j]);
        switch (d) {
            case 0:
                if (j + 1 < m[0].size() - t) spiralOrderUtil(m, i, j + 1, 0, t);
                else {
                    if (i + 1 < m.size() - t) spiralOrderUtil(m, i + 1, j, 1, t);
                }
                break;
            case 1:
                if (i + 1 < m.size() - t) spiralOrderUtil(m, i + 1, j, 1, t);
                else {
                    if (j - 1 > t - 1) spiralOrderUtil(m, i, j - 1, 2, t);
                }
                break;
            case 2:
                if (j - 1 > t - 1) spiralOrderUtil(m, i, j - 1, 2, t);
                else {
                    if (i - 1 > t) spiralOrderUtil(m, i - 1, j, 3, t + 1);
                }
                break;
            case 3:
                if (i - 1 > t - 1) spiralOrderUtil(m, i - 1, j, 3, t);
                else {
                    if (j + 1 < m[0].size() - t) spiralOrderUtil(m, i, j + 1, 0, t);
                }
                break;
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return res;
        spiralOrderUtil(matrix, 0, 0, 0, 0);
        return res;
    }

    //Method 2: note the start and end point at four edges
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return {};
        }
        int up = 0, down = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        int dir = 0;
        
        vector<int> res;
        while(up <= down && left <= right) {
            switch(dir) {
                case 0:
                    for(int j = left; j <= right; j++) {
                        res.push_back(matrix[up][j]);
                    }
                    up++;
                    break;
                case 1:
                    for(int i = up; i <= down; i++) {
                        res.push_back(matrix[i][right]);
                    }
                    right--;
                    break;
                case 2:
                    for(int j = right; j >= left; j--) {
                        res.push_back(matrix[down][j]);
                    }
                    down--;
                    break;
                case 3:
                    for(int i = down; i >= up; i--) {
                        res.push_back(matrix[i][left]);
                    }
                    left++;
                    break;
            }
            dir = (dir + 1) % 4;
        }
        return res;
    }
};