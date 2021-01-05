// 179.Largest Number
// Medium
// Implement the sorting function.
// TC: O(mnlogn)
// SC: O(mn)
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    std::vector<std::string> nums_str;
    nums_str.reserve(nums.size());
    for (int i : nums) {
      nums_str.push_back(to_string(i));
    }
    auto f = [](const std::string& s1, const std::string& s2) {
      if (s1 == "0") return false;
      if (s2 == "0") return true;
      return s1 + s2 > s2 + s1;
    };
    std::sort(nums_str.begin(), nums_str.end(), f);
    if (nums_str[0] == "0") return "0";
    std::string res;
    for (const std::string& s : nums_str) {
      res += s;
    }
    return res;
  }
};
