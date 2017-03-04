//#198
//Easy
//https://leetcode.com/problems/house-robber/?tab=Description
//Arthor: lhy-loveworld
//Method: DP
//Complexity: Time O(N) Space O(1)

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[1];
    int sum0 = 0;                     //The largest number of not choosing current house
    int sum1 = nums[0];               //The largest number of choosing current house
    int tmp;
    for (int i = 1; i < nums.size(); i++) {
      tmp = sum1;
      sum1 = sum0 + nums[i];
      sum0 = tmp;
    }
    return (sum0>sum1)sum0?sum1; 
  }
};

//Another aproach
//Method: DP
//Complexity: Time O(N) Space O(1)

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    int sum0 = 0;                           //The largest number for an even number (Maximum between choosing it and not choosing it). For odd number, it means the largest number of not choosing it
    int sum1 = 0;                           //The largest number for an odd number (Maximum between choosing it and not choosing it). For an even number, it means the largest number of not choosing it.
    for (int i = 0; i < nums.size(); i++) {
      if (i % 2 == 0) sum0 = sum0 + nums[i] > sum1 ?  sum0 + nums[i] : sum1;
      else sum1 = sum1 + nums[i] > sum0 ?  sum1 + nums[i] : sum0;
    }
    return sum0 > sum1 ? sum0 : sum1; 
  }
  
};
