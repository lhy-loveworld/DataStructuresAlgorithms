//#405
//Easy
//Arthor: lhy-loveworld
//Method: Caution that negetive number right shift with 1
//Complexity: Time O(1); Space O(1)

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string res;
        unsigned n = num;
        while (n != 0) {
            int i = n & 0xf;
            res = (i >= 10 ? char('a' + i - 10) : char('0' + i)) + res;
            n >>= 4;
        }
        return res;
    }
};