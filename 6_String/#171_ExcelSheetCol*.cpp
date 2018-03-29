//#171. Excel Sheet Column Number
//Easy
//Method: Relationship between c and res
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (char c: s) {
            res = res * 26 + c - 'A' + 1;
        }
        return res;
    }
};