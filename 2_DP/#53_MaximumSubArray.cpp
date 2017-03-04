//#53
//Easy
//https://leetcode.com/problems/maximum-subarray/?tab=Description
//Arthor: lhy-loveworld
//Method: DP
//Complexity: time O(N) space O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            ans = ans>currentSum?ans:currentSum;
            currentSum = currentSum>0?currentSum:0;
        }
        return ans;
    }
};
