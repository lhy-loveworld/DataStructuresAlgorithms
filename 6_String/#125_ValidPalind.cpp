//#125. Valid Palindrome
//Easy
//Method: two pointers, <cctype>
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < s.size() && !isalnum(s[l])) l++;
            while (r > 0 && !isalnum(s[r])) r--;
            if (l >= r) break;
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};