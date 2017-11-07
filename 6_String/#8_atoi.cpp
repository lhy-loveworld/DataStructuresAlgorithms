//#8. String to Integer (atoi)
//Medium
//Method: Caution for overflow check
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;
        int n = str.size();
        int start = 0;
        while (start < str.size() && str[start] == ' ')
            start++;
        if (start >= str.size()) return res;
        if (str[start] == '+' || str[start] == '-') {
            sign = (str[start] == '+') ? 1 : -1;
            start++;
        }
        for (int i = start; i < str.size(); ++i) {
            if (str[i] > '9' || str[i] < '0')
                return res * sign;
            if (res > (INT_MAX - (str[i] - '0')) / 10)
                return (sign > 0) ? INT_MAX : INT_MIN;
            res = res * 10 + (str[i] - '0');
        }
        return (res < 0) ? ((sign > 0) ? INT_MAX : INT_MIN) : res * sign;
    }
};