class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int major = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == major) {
                ++count;
            } else {
                if (count) count--;
                else {
                    count++;
                    major = nums[i];
                }
            }
        }
        return major;
    }
};
