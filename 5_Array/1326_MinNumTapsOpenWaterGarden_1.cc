// 1326. Minimum Number of Taps to Open to Water a Garden
// Hard.
// TC: O(N)
// SC: O(1)
class Solution {
 public:
  // Method 1: use a stack to track the right end of each line segment.
  int minTaps(int n, vector<int>& ranges) {
    std::stack<int> helper;
    helper.push(0);
    for (int i = 0; i <= n; ++i) {
      if (ranges[i] == 0) continue;
      if (i - ranges[i] > helper.top() || i + ranges[i] <= helper.top()) {
	continue;
      }
      int prev = 0;
      while (helper.size() > 1 && helper.top() > i - ranges[i]) {
        prev = helper.top();
        helper.pop();
      }
      if (helper.top() < i - ranges[i] && prev > 0) {
        helper.push(prev);
      }
      if (i + ranges[i] >= n) return helper.size();
      helper.push(i + ranges[i]);
    }
    if (helper.top() < n) return -1;
    return helper.size() - 1;
  }

  // Method 2: stores the right end of each line segment at the original vector
  // at the position of its left end. and see how many line segment is required
  // to fill [0,n]
  int minTaps(int n, vector<int>& ranges) {
    if (ranges[0] >= n) return 1;
    
    // Preprocess the line segments.
    for (int i = 1; i < ranges.size(); i++) {
      if (ranges[i] == 0) {
	ranges[i] = i;
      } else {
	// We don't need to worry about ranges[i] here because this point will
	// always be covered by ranges[left].
	int left = max(0, i - ranges[i]);
        ranges[left] = max(i + ranges[i], ranges[left]);
      }
    }
    
    int max_right = ranges[0];
    int target = ranges[0];
    int res = 1;    
    for(int i = 1; i < n; i++){
      if (max_right < i) return -1;
      max_right = max(max_right, ranges[i]);
      if (i == target){
        res++;
        target = max_right;
      }
    }
    return max_right >= n ? res : -1;    
  }
};
