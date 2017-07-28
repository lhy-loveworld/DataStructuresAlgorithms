//#169 Majority Element
//Easy
//https://leetcode.com/problems/majority-element/tabs/description
//Arthor: lhy-loveworld
//Method: Majority element means its amount is larger than any other elements.
//Complexity: Time O(N); Space O(1)
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
