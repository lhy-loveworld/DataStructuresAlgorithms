// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
// Medium
// The maximum of digit.
// TC: O(N)
// SC: O(1)
class Solution {
 public:
  int minPartitions(string n) {
    int res = 0;
    for (char c : n) {
      res = max(res, c - '0');
    }
    return res;
  }
};
