// #283 Move Zeroes
// Easy
// https://leetcode.com/problems/maximum-depth-of-binary-tree/tabs/description
// Arthor: lhy-loveworld
// Method: Use of two pointers, all the zeroes can be processed at the same time
// at last.
// Complexity: Time O(N); Space O(1)
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int next_pos = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] != 0) {
        if (i != next_pos) {
          nums[next_pos] = nums[i];
        }
        next_pos++;
      }
    }
    while (next_pos < n) {
      nums[next_pos] = 0;
      next_pos++;
    }
  }
};
