//#136 Single Number
//Easy
//https://leetcode.com/problems/single-number/tabs/description
//Arthor: lhy-loveworld
//Method: When a number xor another number for two times, it still equals to the original one.
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            res ^= nums[i];
        }
        return res;
    }
};
