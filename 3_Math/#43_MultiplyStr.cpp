//#43. Multiply Strings
//Medium
//Method: double loop
//Complexity: time O(m*n); space O(1)

class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        for (int i = num2.size() - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = num1.size() - 1; j >= 0; --j) {
                int tmp = (num2[i] - '0') * (num1[j] - '0') + carry;
                if (num2.size() + num1.size() - 2 - i - j < res.size()) {
                    tmp += (res[res.size() + 1 + i + j - num1.size() - num2.size()] - '0');
                    res[res.size() + 1 + i + j - num1.size() - num2.size()] = (tmp % 10) + '0';
                } else {
                    res = to_string(tmp % 10) + res;
                }
                carry = (tmp / 10);
            }
            if (carry)
                res = to_string(carry) + res;
        }
        int start = 0;
        for (;start + 1 < res.size() && res[start] == '0'; ++start);
        return res.empty() ? res : res.substr(start);
    }
};