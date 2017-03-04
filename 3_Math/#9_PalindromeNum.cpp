//#9
//Easy
//https://leetcode.com/problems/palindrome-number/?tab=Description
//Arthor: lhy-loveworld
//Method: Iterate each digit of this number and create its reverse, test if they are equal
//        All negetive numbers are non-palindrome
//Complexity: time O(n); space O(1)

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int a = x;
    int y = 0;
    while (a != 0) {
      y = y * 10 + a % 10;
      a = a / 10;
    }
    return x == y;
  }
};
