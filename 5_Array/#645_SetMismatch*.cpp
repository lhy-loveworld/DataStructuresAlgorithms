//#645. Set Mismatch
//Easy
//Method: two methods
//Complexity: Time O(N); Space O(1)

class Solution {
public:
	//Method 1: use positive and negetive to find the dup, and use xor to find the one miss
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2, 0);
        if (nums.empty()) return res;
        for (int i = 0; i < nums.size(); ++i) {
            res[1] ^= ((i + 1) ^ abs(nums[i]));
            if (nums[abs(nums[i]) - 1] < 0)
                res[0] = abs(nums[i]);
            else
                nums[abs(nums[i]) - 1] *= -1;
        }
        res[1] ^= res[0];
        return res;
    }

    //Method 2: swap all the mismatch index and values, the one after swap still mismatch is the lost one
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2, 0);
        if (nums.empty()) return res;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                while (nums[nums[i] - 1] != nums[i])
                    swap(nums[nums[i] - 1], nums[i]);
                if (nums[i] != i + 1) {
                    res[1] = i + 1;
                }
            }
        }
        res[0] = nums[res[1] - 1];
        return res;
    }
};