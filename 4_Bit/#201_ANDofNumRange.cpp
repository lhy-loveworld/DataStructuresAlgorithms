//#201
//Medium
//Arthor: lhy-loveworld
//Method: Find the same part of two number
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int x = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            x++;
        }
        return (m << x);
    }
};