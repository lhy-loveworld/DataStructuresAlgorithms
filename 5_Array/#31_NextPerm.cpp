//#31. Next Permutation
//Medium
//Method: 
//Complexity: Time O(NlogN); Space O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                int j = nums.size() - 1;
                for (;nums[j] <= nums[i]; --j);
                swap(nums[i], nums[j]);
                break;
            }
        }
        sort(nums.begin() + i + 1, nums.end());
    }
};