// 581. Shortest Unsorted Continuous Subarray
// Medium
// Two pointers. Basically need to find the position for start and end. start
// is the point where the number starts decreasing. And end is the position
// where the local peak should be placed.
// TC: O(N)
// SC: O(1)
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int start = 0, end = -1, h = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < h) {
	end = i;
      } else {
        h = nums[i];
      }
      if (start == i - 1 && nums[i] >= nums[i - 1]) {
	start++;
      } else {
        while (start >= 0 && nums[start] > nums[i]) {
          start--;
        }
      }
    }
    if (start == nums.size() - 1) return 0;
    return end - start;
  }
};
