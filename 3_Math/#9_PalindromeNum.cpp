//#9
//Easy
//https://leetcode.com/problems/palindrome-number/?tab=Description
//Arthor: lhy-loveworld
//Method: negetive numbers are not palindrome
//        Overflow: only inverse half of this number, thus no need to worry about it
//        When this number is ended with 0, caution for that case
//Complexity: time O(n); space O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0|| (x != 0 && x % 10 == 0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};