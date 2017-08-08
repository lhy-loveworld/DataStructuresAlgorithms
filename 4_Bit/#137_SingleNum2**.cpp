//#137
//Medium
//Arthor: lhy-loveworld
//Method: Consider bit manipulation. The irrelevant bits will be 0 or appears times of 3.
//		  	The first method is counting how many times each bit appears directly.
//				The second method is to use two extra bits to represent the times a bit appears.
//				Ones/twos: 00 -> 10 -> 01 -> 00
//				And then find the relationship between num[i], ones, twos
//				The critical reason that it works is that it can eliminate the bits appears 3 times.
//Complexity: Time O(N); Space O(1)

class Solution {
public:
		//Method 1
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int mask = 1;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            if (i) mask <<= 1;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] & mask)
                    sum++;
            }
            if (sum % 3)
                res |= mask;
        }
        return res;
    }

    //Method 2
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); ++i) {
            a = (a ^ nums[i]) & ~b;
            b = (b ^ nums[i]) & ~a;
        }
        return a;
    }
};