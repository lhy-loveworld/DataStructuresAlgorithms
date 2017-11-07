//#67. Add Binary
//Easy
//Method: single loop
//Complexity: time O(n); space O(1)

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size())
            swap(a, b);
        string res(a.size(), ' ');
        char carry = 0;
        for (int i = 0; i < a.size(); ++i) {
            char a_tmp = a[a.size() - 1 - i] - '0';
            char b_tmp = (i < b.size()) ? b[b.size() - 1 - i] - '0' : 0;
            res[res.size() - 1 - i] = '0' +  a_tmp ^ b_tmp ^ carry;
            carry = (a_tmp + b_tmp + carry) / 2;
        }
        if (carry)
            res = to_string(carry) + res;
        return res;
    }
};