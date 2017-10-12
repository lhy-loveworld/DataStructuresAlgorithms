//#119. Pascal's Triangle II
//Easy
//Method: Backwards, no need to store interim value
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};