//#5. Longest Palindromic Substring
//Medium
//Method: Use left and right to specify the center of the substring, can skip consecutive identical characters.
//Complexity: Time O(N to N^2); Space O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0, start = 0, n = s.size();
        for (int i = 0; 2 * (n - 1 - i) + 1 > max_len; ++i) {
            int left = i, right = i;
            while (s[right + 1] == s[left]) right++;
            i = right;
            while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }
            if (max_len < right - left + 1) {
                max_len = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, max_len);
    }
};