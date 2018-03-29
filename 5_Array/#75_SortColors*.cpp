//#75. Sort Colors
//Medium
//Method: one-pass algorithm
//Complexity: Time O(N); Space O(1)

class Solution {
public:
	//Method 1:
	//one pass
    void sortColors(vector<int>& nums) {
        if (nums.empty()) return;
        int a = 0, b = 0, c = nums.size() - 1;
        while (b <= c) {
            if (nums[b] == 0) swap(nums[a++], nums[b++]);
            else if (nums[b] == 1) b++;
            else swap(nums[b], nums[c--]);
        }
    }

    //Method 2: 2 passes
    void sortColors(vector<int>& nums) {
        vector<int> n(3, 0);
        for (auto i: nums)
            n[i]++;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < n[0]) nums[i] = 0;
            else if (i < n[0] + n[1]) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};