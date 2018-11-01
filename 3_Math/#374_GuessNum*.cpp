//#374. Guess Number Higher or Lower
//Easy
//Method: cautious about overflow
//Complexity: Time O(logN); Space O(1)

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long l = 1, h = n;
        while (1) {
            int t = (l + h) / 2;
            int res = guess(t);
            if (!res) return t;
            if (res > 0) l = t + 1;
            else h = t - 1;
        }
    }
};