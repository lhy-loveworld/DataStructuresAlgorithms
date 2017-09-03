//#397
//Medium    
//Arthor: lhy-loveworld
//Method: When eliminating the last bits, the difference between +1 and -1 is left with 1 or 0, cautious for the corner case.
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        if (n == INT_MAX) return 32;
        while (n != 1) {
            if (n == 3) return res + 2;
            if (n & 1) {
                if ((n & 3) == 3)
                    n++;
                else
                    n--;
            } else
                n >>= 1;
            ++res;
        }
        return res;
    }
};