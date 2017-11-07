//#50. Pow(x, n)
//Medium
//Method: binary reduce its order
//Complexity: time O(logn); space O(1)

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
            return (1 / myPow(x, -(n + 1))) / x;
        if (n == 0)
            return 1;
        return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
    }
};