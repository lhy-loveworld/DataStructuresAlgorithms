//#91_Decode Ways
//Medium
//Method: DP, no need to store interim values
//Time complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
    int check_even(string& s, int i) {
        if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
            return 1;
        else
            return 0;
    }
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int helper1 = 1, helper2 = (s[0] != '0');
        for (int i = 1; i < s.size(); ++i) {
            swap(helper1, helper2);
            helper2 = check_even(s, i) * helper2 + helper1 * (s[i] != '0');
        }
        return helper2;
    }
};