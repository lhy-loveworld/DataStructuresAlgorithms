//#260
//Medium
//Arthor: lhy-loveworld
//Method: Divide the numbers into two parts according to their feature.
//Complexity: Time O(N); Space O(N)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res({0, 0});
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;//Use it to get the last bit of diff, or diff ^= diff & (diff - 1);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & diff)
                res[0] ^= nums[i];
            else
                res[1] ^= nums[i];
        }
        return res;
    }
};