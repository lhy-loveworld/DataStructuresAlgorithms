//#10 Regular Expression Matching
//Medium
//Method: DP
//Time complexity: O(M*N)
//Space complexity: O(N)

class Solution {
public:
    //Method 1: DP
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        vector < vector<bool> > helper(2, vector<bool> (p.size() + 1, false));
        helper[0][0] = true;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == '*')
                helper[0][i + 1] = helper[0][i - 1];
        }
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size(); ++j) {
                if (p[j] == '*') {
                    helper[1][j + 1] = helper[1][j - 1] || helper[0][j + 1] && (p[j - 1] == '.' || s[i] == p[j - 1]);
                } else {
                    helper[1][j + 1] = helper[0][j] && (p[j] == '.' || s[i] == p[j]);
                }
            }
            helper[0] = helper[1];
        }
        return helper[0].back();
    }

    //Method 2: recursively
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1 || p[1] != '*') return !s.empty() && (p[0] == '.' || p[0] == s[0]) && isMatch(s.substr(1), p.substr(1));
        return isMatch(s, p.substr(2)) || !s.empty() && (p[0] == '.' || p[0] == s[0]) && isMatch(s.substr(1), p);
    }
};