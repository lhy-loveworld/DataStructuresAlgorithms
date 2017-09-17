//#357 Count Numbers with Unique Digits
//Medium
//Method: Arrangement
//Time complexity: O(1)
//Space complexity: O(1)

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1;
        int tmp = 9;
        for (int i = 1; i <= n; ++i) {
            if (i > 10) break;
            res += tmp;
            tmp *= (10 - i);
        }
        return res;
    }
};