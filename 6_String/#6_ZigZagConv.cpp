//#6. ZigZag Conversion
//Medium
//Method: observe
//Complexity: Time O(N); Space O(N)

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int cur = 0, dir = 1;
        vector<string> helper(numRows);
        for (char c: s) {
            helper[cur] += c;
            cur += dir;
            if (cur == numRows - 1) dir = -1;
            else if (cur == 0) dir = 1;
        }
        string res;
        for (string h: helper)
            res += h;
        return res;
    }
};