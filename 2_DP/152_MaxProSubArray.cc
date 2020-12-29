//#152_Maximum Pruduct Subarray
//Medium
//Method: Two methods
//        Critical problem is to determine the max-so-far.
//Time complexity: O(N), Space complexity: O(1)

class Solution {
public:
    //Method 1: Calculate from both directions
    //Because all the int number are > 1, thus contain all the numbers or except the first negetive number or except the last negetive number
    int maxProduct(vector<int>& nums) {
        int frontP = 1, backP = 1, res = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            frontP *= nums[i];
            backP *= nums[nums.size() - i - 1];
            res = max(res, max(frontP, backP));
            frontP = (frontP == 0) ? 1 : frontP;
            backP = (backP == 0) ? 1 : backP;
        }
        return res;
    }

    //Method 2: Calculate from positive and negative products
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1, cmax = nums[0], cmin = nums[0]; i < nums.size(); ++i) {
            if (nums[i] < 0)
                swap(cmax, cmin);
            cmax = max(nums[i], nums[i] * cmax);
            cmin = min(nums[i], nums[i] * cmin);
            res = max(res, cmax);
        }
        return res;
    }
};