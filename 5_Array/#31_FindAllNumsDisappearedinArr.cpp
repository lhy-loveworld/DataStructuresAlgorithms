//#448. Find All Numbers Disappeared in an Array
//Easy
//Method: 
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != i + 1) res.push_back(i + 1);
        return res;
    }
};