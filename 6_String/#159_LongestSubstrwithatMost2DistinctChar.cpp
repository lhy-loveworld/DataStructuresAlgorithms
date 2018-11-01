//#159. Longest Substring with At Most Two Distinct Characters
//Hard
//Method: Record each consecutive same substrings, store the beginning of such substring in a queue
//Complexity: time O(N). space O(1)

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        queue<int> helper;
        int res = 0;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (helper.empty() || s[i] != s[helper.back()]) {
                helper.push(i);
            }
            if (helper.size() > 2) {
                char c = s[helper.front()];
                helper.pop();
                if (c != s[helper.back()]) start = helper.front();
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};