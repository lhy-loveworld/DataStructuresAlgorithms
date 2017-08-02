//#258
//Easy
//https://leetcode.com/problems/add-digits/description/
//Arthor: lhy-loveworld
//Method: https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
//Complexity: time O(1); space O(1)

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};