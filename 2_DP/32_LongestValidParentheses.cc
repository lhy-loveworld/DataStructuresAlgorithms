// 32. Longest Valid Parentheses
// Hard
class Solution {
 public:
  // Method 1: two passes.
  // TC: O(N), SC: O(1)
  int longestValidParentheses(string s) {
    int res = 0, l = s.size(), status = 0, start = 0;
    // First pass. We only update res when there are more right parentheses than the left parentheses.
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
    // Second pass from right to left. We only update res when left parentheses are more than right ones.
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

  // Use a stack to help tracking.
  // TC: O(N), SC: O(N)
  int longestValidParentheses(string s) {
    std::stack<int> helper; // it always holds the index before the current substring + the index of unmatched left parentheses.
    helper.push(-1); // the index before the current substring.
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        helper.push(i);
      } else {
        helper.pop(); // pop the matching left parenthese or the index before the current substring.
	if (helper.empty()) {
          // unmatched right parenthese becomes the start of new substring
          helper.push(i);
        } else {
          // the right-most unmatched left parenthese is the start of the current substring
	  res = max(res, i - helper.top());
        }
      }
    }
    return res;
  }
};
