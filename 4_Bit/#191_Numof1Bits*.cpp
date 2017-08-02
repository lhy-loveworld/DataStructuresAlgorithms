//#191
//Easy
//Arthor: lhy-loveworld
//Method: n&(n-1) drops the last bit 1.
//Complexity: Time ; Space O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= (n - 1);
            res++;
        }
        return res;
    }
};