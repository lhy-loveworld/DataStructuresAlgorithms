//#377. Combination Sum IV
//Medium
//Method: DP, the way of looping is different from Coin Change problem. Only a subtle different makes the appearance of duplicate.
//Time complexity: O(M*N)
//Space complexity: O(N)

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        vector<int> combs(target + 1, 0);
        combs[0] = 1;
        //the outer loop is for each target
        for (int i = 0; i < combs.size(); ++i) {
            //inner loop is for each candidate
            for (int j = 0; j < nums.size(); ++j) {
                if (i + nums[j] > target) continue;
                combs[i + nums[j]] += combs[i];
            }
        }
        return combs.back();
    }
};