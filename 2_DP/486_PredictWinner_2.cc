// 486. Predict the Winner
// Medium
// Memoization.
// TC: O(N^2)
// SC: O(N^2)
class Solution {
 public:
  std::vector<std::vector<int>> memoization_;

  // Returns total_of_first_pick_player - total_of_second_pick_player.
  int helper(int start, int end, vector<int>& nums) {
    if (start == end) return nums[start];
    if (memoization_[start][end] != INT_MAX) return memoization_[start][end];
    // When pick the left end, in the following round. They will swap the pick
    // order, so we need to minus the result of next round.
    int res_left = nums[start] - helper(start + 1, end, nums);
    int res_right = nums[end] - helper(start, end - 1, nums);
    // First pick player will choose the better situation.
    memoization_[start][end] = max(res_left, res_right);
    return memoization_[start][end];
  }
    
  bool PredictTheWinner(vector<int>& nums) {
    memoization_ = std::vector<std::vector<int>>(nums.size(), std::vector<int>(nums.size(), INT_MAX));
    return helper(0, nums.size() - 1, nums) >= 0;
  }
};
