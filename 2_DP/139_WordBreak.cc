//#139
//Medium
//Arthor: lhy-loveworld
//Method: 
//Complexity: time O(N^2) space O(N)

class Solution {
 public:
  // Method 1: DP. Loop through the length of string and build a map for dict.
  // helper records whether the front n chars can be broken or not
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

  // Method 2: DP. Loop through the dict vector to avoid looping the string. Do
  // so when length of s >> size of dict.
  bool wordBreak(string s, vector<string>& wordDict) {
    std::vector<bool> helper(s.size());
    helper[0] = true;
    for (int start = 0; start < s.size(); ++start) {
      if (!helper[start]) continue;
      for (const std::string& word : wordDict) {
        if (word.size() + start > s.size()) continue;
        if (word.size() + start == s.size()) {
	  if (s.substr(start) == word) return true;
          continue;
        }
        if (helper[start + word.size()]) continue;
        int i = 0;
        while (i < word.size()) {
	  if (word[i] != s[start + i]) break;
          ++i;
        }
        if (i == word.size()) helper[start + word.size()] = true;
      }
    }
    return false;
  }

  // Method 3: recursion with memoisation.
  std::unordered_set<std::string> dict_;
  std::vector<int> memo_; 
  bool RecBreak(const std::string& s, int start) {
    if (memo_[start]) return memo_[start] == 1;
    if (dict_.count(s.substr(start))) {
      memo_[start] = 1;
      return true;
    }
    for (int l = 1; start + l < s.size(); ++l) {
      if (dict_.count(s.substr(start, l)) && RecBreak(s, start + l)) {
        memo_[start] = 1;
        return true;
      }
    }
    memo_[start] = 2;
    return false;
  }
  bool wordBreak(string s, vector<string>& wordDict) {
    dict_ = {wordDict.begin(), wordDict.end()};
    if (dict_.count(s)) return true;
    memo_ = std::vector<int>(s.size());
    return RecBreak(s, 0);
  }
};
