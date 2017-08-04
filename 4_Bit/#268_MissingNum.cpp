//#268
//Easy
//Arthor: lhy-loveworld
//Method: Two different methods.
//Complexity: Time O(N); Space O(1)

class Solution {
public:
	//bitwise xor
	//no need to worry about overflow
    int missingNumber(vector<int>& nums) {
        int mask = 0 ^ nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            mask ^= (i ^ nums[i]);
        }
        return mask ^ nums.size();
    }

    //sum
	//can use formula, overflow risk
	int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n * (n + 1) / 2;
        for (int i = 0; i < n; ++i) {
            res -= nums[i];
        }
        return res;
    }
};


