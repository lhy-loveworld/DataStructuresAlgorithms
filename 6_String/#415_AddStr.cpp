//#415. Add Strings
//Easy
//Method:
//Complexity: time O(N). space O(1)

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int carry = 0;
        if (num1.size() > num2.size()) swap(num1, num2);
        auto it1 = num1.rbegin(), it2 = num2.rbegin();
        while (it1 != num1.rend()) {
            int t = *it1 - '0' + *it2 - '0' + carry;
            res += '0' + (t % 10);
            carry = t / 10;
            it1++;
            it2++;
        }
        while (it2 != num2.rend()) {
            int t = *it2 - '0' + carry;
            res += '0' + (t % 10);
            carry = t / 10;
            it2++;
        }
        if (carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};