// #753. Cracking the Safe
// Hard
// Method: three methods
// Complexity: 
class Solution {
 public:
  // Method 1: start from the last vertice, and visit all the vertice in forward order. (or you can start from the first one and traverse in reverse order)
  string crackSafe(int n, int k) {
    int total = pow(k, n);
    unordered_set<string> isVisited;
    string res(n, '0' + k - 1);
    for (int i = 1; i < total; ++i) {
      res += '0';
      for (int j = 0; j < k; ++j, ++res.back()) {
	if (!isVisited.count(res.substr(res.size() - n))) {
          isVisited.insert(res.substr(res.size() - n));
          break;
        }
      }
    }
    return res;
  }

  // Method 2: each password is a vertice, finding Hanmiltonian cycle using backtrack
  unordered_set<int> is_visited_;
  string res_;
  int target_;
  bool HasNextPass(int prefix, int n, int k) {
    if (res_.size() == target_) return true;
    for (int i = 0; i < k; ++i) {
      int tmp = prefix + i;
      if (!is_visited_.count(tmp)) {
        is_visited_.insert(tmp);
        res_.push_back('0' + i);
        if (HasNextPass(tmp % int(pow(10, n - 1)) * 10, n, k)) return true;
        res_.pop_back();
        is_visited_.erase(tmp);
      }
    }
    return false;
  }
  string crackSafe(int n, int k) {
    target_ = n - 1 + pow(k, n);
    res_.assign(n - 1, '0');
    HasNextPass(0, n, k);
    return res_;
  }

  // Method 3: each password is an edge, finding Eulerian circle using post-order dfs
  unordered_set<int> is_visited_;
  string res_;
  void HasNextPass(int prefix, int n, int k) {
    for (int i = 0; i < k; ++i) {
      int tmp = prefix + i;
      if (!is_visited_.count(tmp)) {
        is_visited_.insert(tmp);
        HasNextPass(tmp % int(pow(10, n - 1)) * 10, n, k);
        res_.push_back('0' + i); // post order. visit this vertice after dfs.
      }
    }
  }
  string crackSafe(int n, int k) {
    HasNextPass(0, n, k);
    res_.append(n - 1, '0');
    return res_;
  }
};
