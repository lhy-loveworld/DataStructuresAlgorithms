// #11. Container With Most Water
// Medium
// Method: two pointers from both ends. For h[left], we are looking for max
// right that h[left] <= h[right]. For h[right], we are looking for min left
// that h[left] >= h[right].
// Complexity: Time O(N); Space O(1)
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int res = 0, left = 0, right = height.size() - 1;
    while (left < right) {
      if (height[left] < height[right]) {
        res = max(res, height[left] * (right - left));
        left++;
      } else {
        res = max(res, height[right] * (right - left));
        if (height[left] == height[right]) {
          left++;
        }
        right--;
      }
    }
    return res;
  }
};
