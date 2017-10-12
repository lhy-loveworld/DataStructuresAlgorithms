//#26. Remove Duplicates from Sorted Array
//Easy
//Method: two pointers
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int end = 0;
        for (int cur = 1; cur < nums.size(); ++cur) {
            if (nums[cur] != nums[end])
                nums[++end] = nums[cur];
        }
        return end + 1;
    }
};