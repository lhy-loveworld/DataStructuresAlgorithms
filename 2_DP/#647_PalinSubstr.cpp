//#647. Palindromic Substrings
//Medium
//Method: dp
//Time complexity: O(N^2)
//Space complexity: O(1)

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; i - j >= 0 && i + j + 1 < s.size() && s[i - j] == s[i + j + 1]; ++j) res++;
            for (int j = 0; i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]; ++j) res++;
        }
        return res;
    }
};