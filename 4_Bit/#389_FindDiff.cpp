//#389
//Easy
//Arthor: lhy-loveworld
//Method: XOR, no need to check if s is empty.
//Complexity: Time O(1); Space O(1)

class Solution {
public:
    char findTheDifference(string s, string t) {
        char mask = 0;
        for (char ch: s) {
            mask ^= (ch - 'a'); 
        }
        for (char ch: t) {
            mask ^= (ch - 'a'); 
        }
        return 'a' + mask;
    }
};