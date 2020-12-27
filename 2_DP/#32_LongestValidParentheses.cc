class Solution {
public:
  // Method 1: two passes.
    int longestValidParentheses(string s) {
        int res = 0, l = s.size(), status = 0, start = 0;
        for (int i = 0; i < l; ++i) {
            if (s[i] == '(') {
                ++status;
            } else {
                --status;
                if (status == 0) {
                    res = max(res, i - start + 1);
                } else if (status < 0) {
                    start = i + 1;
                    status = 0;
                }
            }
        }
        start = l - 1;
        status = 0;
        for (int i = l - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++status;
            } else {
                --status;
                if (status == 0) {
                    res = max(res, start - i + 1);
                } else if (status < 0) {
                    start = i - 1;
                    status = 0;
                }
            }
        }
        return res;
    }
};
