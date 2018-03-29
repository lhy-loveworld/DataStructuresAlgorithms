//#53
//Easy
//https://leetcode.com/problems/maximum-subarray/?tab=Description
//Arthor: lhy-loveworld
//Method: DP and divide and conqure
//Complexity: time O(N) space O(1)

class Solution {
public:
    //Method 1: DP
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

    //Method 2: Divide and conqure
    void dnq(vector<int>& nums, int l, int h, int &lmax, int &rmax, int &amax, int &sum) {
        if (l == h) {
            lmax = rmax = amax = sum = nums[l];
        } else {
            int m = (l + h) / 2;
            int llmax, lrmax, lamax, lsum, rlmax, rrmax, ramax, rsum;
            dnq(nums, l, m, llmax, lrmax, lamax, lsum);
            dnq(nums, m + 1, h, rlmax, rrmax, ramax, rsum);
            lmax = max(llmax, lsum + rlmax);
            rmax = max(rrmax, rsum + lrmax);
            amax = max(max(lamax, ramax), lrmax + rlmax);
            sum = lsum + rsum;
        }
    }
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int lmax, rmax, amax, sum;
        dnq(nums, 0, nums.size() - 1, lmax, rmax, amax, sum);
        return amax;
    }
};
