// #7
// Easy
// https://leetcode.com/problems/reverse-integer/?tab=Description
// Arthor: lhy-loveworld
// Method: Caution for overflow case!
//         Another method is to use a long long type to do it
//         The second method is a little slower
// Complexity: time O(n); space O(1)

class Solution {
 public:
  int reverse(int x) {
    int sign = 1;
    if (x < 0) sign = -1;
    x = abs(x);
    int ans = 0;
    while (x != 0) {
      if ((ans > INT_MAX / 10 )||(ans * 10 > INT_MAX - x % 10)) return 0;
      else ans = ans * 10 + x % 10;
      x = x / 10;
    }
    return sign * ans;
  }
};

class Solution {
 public:
  int reverse(int x) {
    long long ans = 0;
    while (x) {
      ans = ans * 10 + x % 10;
      x /= 10;
      if (ans < INT_MIN || ans > INT_MAX) return 0;
    }
    return ans;
  }
};
