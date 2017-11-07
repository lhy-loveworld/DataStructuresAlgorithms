//#46. Permutations
//Medium
//Method: backtracking
//Complexity: Time O(N^N); Space O(N)

class Solution {
public:
    void subP(vector<int>& nums, vector<int>& tmp, vector<vector<int> >& res, vector<bool>& helper) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!helper[i]) {
                tmp.push_back(nums[i]);
                helper[i] = true;
                subP(nums, tmp, res, helper);
                helper[i] = false;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        vector<bool> helper(nums.size(), false);
        subP(nums, tmp, res, helper);
        return res;
    }
};