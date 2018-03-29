//#22. Generate Parentheses
//Medium
//Method: backtracking
//Complexity: Time O(2^N); Space O(N)

class Solution {
    vector<string> res;
    string cur;
    void GenSub(int l, int r) {
        if (l == 0 && r == 0) {
            res.push_back(cur);
            return;
        }
        if (l > 0) {
            cur += '(';
            GenSub(l - 1, r);
            cur.pop_back();
        }
        if (r > l) {
            cur += ')';
            GenSub(l, r - 1);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        GenSub(n, n);
        return res;
    }
};