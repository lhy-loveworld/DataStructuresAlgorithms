// 451. Sort Characters By Frequency
// Medium
// TC: O(N)
// SC: O(N)
class Solution {
 public:
  string frequencySort(string s) {
    std::vector<std::string> char_str(UCHAR_MAX);
    for (char c : s) {
      char_str[c] += c;
    }
    auto f = [](const std::string& a, const std::string& b) {return a.size() > b.size();};
    std::sort(char_str.begin(), char_str.end(), f);
    std::string res;
    res.reserve(s.size());
    for (const std::string& str : char_str) {
      res += str;
    }
    return res;
  }
};
