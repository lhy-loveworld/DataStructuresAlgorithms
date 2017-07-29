//#283 Move Zeroes
//Easy
//https://leetcode.com/problems/maximum-depth-of-binary-tree/tabs/description
//Arthor: lhy-loveworld
//Method: Use of two pointers, all the zeroes can be processed at the same time at last.
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        for (; i < nums.size(); ++i) 
            if (nums[i] != 0) 
                nums[j++] = nums[i];
        for (; j < nums.size(); ++j)
            nums[j] = 0;
    }
};