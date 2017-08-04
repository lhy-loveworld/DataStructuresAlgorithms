//#13 Roman to Integer
//Easy
//https://leetcode.com/problems/roman-to-integer/discuss/
//Arthor: lhy-loveworld
//Method: Process backwards
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> dict({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});
        int res = dict[s.back()];
        int prev = res;
        for (int i = s.length() - 2; i >= 0; --i) {
            if (dict[s[i]] >= prev)
                res = res + dict[s[i]];
            else
                res = res - dict[s[i]];
            prev = dict[s[i]];
        }
        return res;
    }
};