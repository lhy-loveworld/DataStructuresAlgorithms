//#162. Find Peak Element
//Medium
//Method: binary search
//Complexity: Time O(logN); Space O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || nums[0] > nums[1]) return 0;
        if (nums[n - 2] < nums[n - 1]) return n - 1;
        int l = 0, r = n;
        while (l != r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) return m;
            if (nums[m] < nums[m - 1]) r = m;
            else l = m + 1;
        }
    }
};