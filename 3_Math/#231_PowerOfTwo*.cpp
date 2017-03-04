//#231
//Easy
//https://leetcode.com/problems/power-of-two/?tab=Description
//Arthor: lhy-loveworld
//Method: Bitwise operation
//Complexity: time O(1); space O(1)

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    return (n>0)&& (!(n&(n-1)));
  }
};
