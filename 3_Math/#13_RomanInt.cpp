//#12 Integer to Roman
//Medium
//Method: Directly store a vector of strings representing each digit.
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    //Method 1: merely store the basic charactor for roman integers
    string intToRoman(int num) {
        unordered_map<int, string> mp;
        mp[1] = "I";
        mp[5] = "V";
        mp[10] = "X";
        mp[50] = "L";
        mp[100] = "C";
        mp[500] = "D";
        mp[1000] = "M";
        string res;
        int dig = 1;
        while (num) {
            int tmp = num % 10;
            if (tmp == 9 || tmp == 4)
                res = mp[dig] + mp[(tmp + 1) * dig] + res;
            else {
                if (tmp >= 5) {
                    for (int i = 0; i < tmp - 5; ++i)
                        res = mp[dig] + res;
                    res = mp[dig * 5] + res;
                } else {
                    for (int i = 0; i < tmp; ++i)
                        res = mp[dig] + res;
                }
            }
            dig *= 10;
            num /= 10;
        }
        return res;
    }


};