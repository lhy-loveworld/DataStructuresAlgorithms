// #128. Longest Consecutive Sequence
// Hard
// Method: 3 methods
// Complexity: Time O(N); Space O(N)

class Solution {
 public:
  //Method 1: use a map to store the two ends of a sequence and its length
  int longestConsecutive(vector<int>& nums) {
    int res = 0;
    unordered_map<int, int> DJset;
    for (int i: nums) {
      if (!DJset.count(i)) {// only check for new elements
	int left = DJset.count(i - 1) ? DJset[i - 1] : 0;
        int right = DJset.count(i + 1) ? DJset[i + 1] : 0;
	int num = left + right + 1;
        res = max(res, num);
	DJset[i] = num; //also need to update the current position
        DJset[i - left] = num;
	DJset[i + right] = num;
      }
    }
    return res;
  }

  // Method 2: use a set to store all the numbers, and every time remove all the consecutive numbers to an element
  int longestConsecutive(vector<int>& nums) {
    int res = 0;
    unordered_set<int> Set(nums.begin(), nums.end());
    for (int i: nums) {// for each number in the vector, not the set
      if (Set.count(i)) {
	Set.erase(i);
        int j = i + 1, k = i - 1;
	while (Set.count(j)) Set.erase(j++);
        while (Set.count(k)) Set.erase(k--);
	res = max(res, j - k - 1);
      }
    }
    return res;
  }

  // Method 3: also use another set, but every time only check the left end of a sequence
  int longestConsecutive(vector<int>& nums) {
    int res = 0;
    unordered_set<int> Set(nums.begin(), nums.end());
    for (int i: nums) {
      if (!Set.count(i - 1)) {
	int j = i + 1;
        while (Set.count(j)) j++;
	res = max(res, j - i);
      }
    }
    return res;
  }
};
