// #1297. Maximum Number of Occurrences of a Substring
// Medium.
// Two pointers. A valid substring of length k will always contain one of
// length k-1, so we only need to consider length minSize.
// TC: O(minSize*N)
// SC: O(minSize*N)
class Solution {
 public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    std::vector<int> letters(26);
    int n = s.size(), nums = 0, start = 0, res = 0;
    std::unordered_map<std::string, int> occurances;
    for (int end = 0; end < n; ++end) {
      if (letters[s[end] - 'a']++ == 0) {
        nums++;
      }
      if (end + 1 >= minSize) {
        if (end + 1 > minSize) {
          if (--letters[s[start] - 'a'] == 0) {
            nums--;
          }
          start++;
        }
        if (nums <= maxLetters) {
          std::string sub = s.substr(start, minSize);
          occurances[sub]++;
          if (occurances[sub] > res) res = occurances[sub];
        }
      }
    }
    return res;
  }
};
