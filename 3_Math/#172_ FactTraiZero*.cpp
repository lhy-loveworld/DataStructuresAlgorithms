//#172. Factorial Trailing Zeroes
//Easy
//Method: Count the times for 5. Some number may contain multiple 5
//Complexity: time O(logn); space O(1)

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            n /= 5;
            res += n;
        }
        return res;
    }
};