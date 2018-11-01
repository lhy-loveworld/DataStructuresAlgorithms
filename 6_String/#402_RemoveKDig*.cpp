//#402. Remove K Digits
//Medium
//Method: the smallest possible result is in ascending order, we can use a stack method to track it.
//          cautious for diffenrent kinds of corner cases
//Complexity: time O(N). space O(1)

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        int i = 0;
        while (k > 0) {
            while (k >0 && !res.empty() && (i == num.size() || res.back() > num[i])) {
                res.pop_back();
                k--;
            }
            if (i == num.size()) break;
            if (num[i] != '0' || k == 0) res.push_back(num[i]);
            ++i;
        }
        res += num.substr(i);
        i = 0;
        while (i < num.size() && res[i] == '0') ++i;
        res = res.substr(i);
        if (res.empty()) return "0";
        return res;
    }
};