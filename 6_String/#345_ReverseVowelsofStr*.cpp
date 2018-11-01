//#345. Reverse Vowels of a String
//Easy
//Method: cautious for corner case
//Complexity: Time O(N^2); Space O(1)

unordered_set<char> dict{'A','E','I','O','U','a','e','i','o','u'};
class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            for (; l < r && !dict.count(s[l]); ++l);
            for (; r > l && !dict.count(s[r]); --r);
            swap(s[l], s[r]); 
            ++l;    //cautious for corner case
            --r;    //cautious for corner case
        }
        return s;
    }
};