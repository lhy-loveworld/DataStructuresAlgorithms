//#238. Product of Array Except Self
//Medium
//Method: from both ends
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int front = 1, back = 1;
        for (int i = 0; i < nums.size(); ++i) {
            res[i] *= front;
            res[nums.size() - 1 - i] *= back;
            front *= nums[i];
            back *= nums[nums.size() - 1 - i];
        }
        return res;
    }
};