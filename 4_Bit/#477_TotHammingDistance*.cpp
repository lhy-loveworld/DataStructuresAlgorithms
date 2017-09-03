//#477
//Medium    
//Arthor: lhy-loveworld
//Method: Compare bit by bit, total hamming distance for each bit is the product of the number of 0 and the number of 1.
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 31; ++i) {
            int a = 0, b = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if ((nums[j] & 1) == 0)
                    ++a;
                else
                    ++b;
                nums[j] >>= 1;
            }
            res += (a * b);
        }
        return res;
    }
};