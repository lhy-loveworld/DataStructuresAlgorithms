//#139
//Medium
//Arthor: lhy-loveworld
//Method: Determine the situation based on the end of substring instead of the beginning
//Complexity: time O(N^2) space O(N)

class Solution {
public:
    //helper records whether the front n chars can be broken or not
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty()) return false;
        unordered_set<string> Dict(wordDict.begin(), wordDict.end());
        vector<bool> helper(s.size() + 1, false);
        helper[0] = true;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (helper[j])
                    if (Dict.count(s.substr(j, i - j + 1))) {
                        helper[i + 1] = true;
                        break;
                    }
            }
        }
        return helper[s.size()];
    }
};