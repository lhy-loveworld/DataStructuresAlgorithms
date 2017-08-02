//#344 Reverse String
//Easy
//https://leetcode.com/problems/reverse-string/tabs/description
//Arthor: lhy-loveworld
//Method: Use of string library
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        int i = 0, j = len - 1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
        return s;
    }
};