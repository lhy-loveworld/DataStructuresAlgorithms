//#326. Power of Three
//Easy
//Method: 
//Complexity: Time O(1), O(log(N)); Space O(1)

class Solution {
public:
    //Method 1:
    bool isPowerOfThree(int n) {
        return n > 0 && int(pow(3, int(log(INT_MAX) / log(3)))) % n == 0;
    }

    //Method 2:
    bool isPowerOfThree(int n) {
        long x = 1;
        while (x < n) x *= 3;
        return x == n;
    }
};