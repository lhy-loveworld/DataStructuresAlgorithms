//#33. Search in Rotated Sorted Array
//Medium
//Method: Binary Search
//Complexity: Time O(log(N)); Space O(1)

class Solution {
public:
    int helper(vector<int>& nums, int t, int l, int h) {
        if (h < l) return -1;
        int m = (h + l) / 2;
        if (nums[m] == t) return m;
        if (h == l) return -1;
        if (nums[m] >= nums[l])
            return (t < nums[m] && t >= nums[l]) ? helper(nums, t, l, m - 1) : helper(nums, t, m + 1, h);
        return (t > nums[m] && t <= nums[h]) ? helper(nums, t, m + 1, h) : helper(nums, t, l, m - 1);      
    }
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return helper(nums, target, 0, nums.size() - 1);
    }
};