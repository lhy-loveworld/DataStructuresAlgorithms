// 1073. Adding Two Negabinary Numbers
// Medium
// Figure out all the possibilities for the result and carryover.
// TC: O(N)
// SC: O(1)
class Solution {
 public:
  vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    int carry_over = 0;
    if (arr1.size() < arr2.size()) {
      arr1.swap(arr2);
    }
    std::vector<int> res(arr1.size());
    for (int i = 0; i < arr1.size(); ++i) {
      int t = arr1[arr1.size() - 1 - i] + carry_over;
      if (i < arr2.size()) {
        t += arr2[arr2.size() - 1 - i];
      }
      switch (t) {
        case -1:
          res[i] = 1;
          carry_over = 1;
          break;
        case 0:
        case 1:
	  res[i] = t;
          carry_over = 0;
          break;
        case 2:
          res[i] = 0;
          carry_over = -1;
	  break;
        case 3:
          res[i] = 1;
          carry_over = -1;
      }
    }
    if (carry_over == -1) {
      res.push_back(1);
      res.push_back(1);
    } else if (carry_over == 1) {
      res.push_back(1);
    } else {
      while (res.back() == 0 && res.size() > 1) {
        res.pop_back();
      }
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
