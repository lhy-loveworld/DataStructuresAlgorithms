// #402. Remove K Digits
// Medium
// Method: the smallest possible result is in ascending order, we can use a
// stack method to track it. cautious for diffenrent kinds of corner cases
// Complexity: time O(N). space O(1)
class Solution {
 public:
  string removeKdigits(string num, int k) {
    if (num.size() == k) return "0";
    if (k == 0) return num;
    std::string res;
    res.reserve(num.size() - k);
    for (int i = 0; i < num.size(); ++i) {
      while (k > 0 && !res.empty() && res.back() > num[i]) {
        res.pop_back();
        k--;
      }
      if (!res.empty() || num[i] != '0' || i == num.size() - 1) {
        if (num.size() - i > k) {
          res += num[i];
        } else {
          k--;
        }
      }
    }
    return res;
  }
};
