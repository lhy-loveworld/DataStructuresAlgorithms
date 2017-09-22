//#3 Longest Substring Without Repeating Characters
//Medium
//Method: Hash table
//Complexity: Time O(N to N^2); Space O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        unordered_map<char, int> dict;
        int res = 0;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (dict.count(s[i])) {
                for (int j = start; j < dict[s[i]]; ++j) {
                    dict.erase(s[j]);
                }
                start = dict[s[i]] + 1;
                dict[s[i]] = i;
            } else {
                dict[s[i]] = i;
                res = max(res, i - start + 1);
            }
        }
        return res;
    }
};