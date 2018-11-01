//#753. Cracking the Safe
//Hard
//Method: three methods
//Complexity: 

class Solution {
public:
  //Method 1: start from the last vertice, and visit all the vertice in forward order. (or you can start from the first one and traverse in reverse order)
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

    //Method 2: each password is a vertice, finding hanmiltonion circle using backtrack
      unordered_set<int> isVisited;
  string res;
  int target;
  bool has_next_pass(int prefix, int n, int k) {
    if (res.size() == target) return true;
    for (int i = 0; i < k; ++i) {
      int tmp = prefix + i;
      if (!isVisited.count(tmp)) {
        isVisited.insert(tmp);
        res.push_back('0' + i);
        if (has_next_pass(tmp % int(pow(10, n - 1)) * 10, n, k)) return true;
        res.pop_back();
        isVisited.erase(tmp);
      }
    }
    return false;
  }
    string crackSafe(int n, int k) {
        target = n - 1 + pow(k, n);
        res.assign(n - 1, '0');
      has_next_pass(0, n, k);
      return res;
    }

  //Method 3: each password is an edge, finding euler circle using post-order dfs
    unordered_set<int> isVisited;
  string res;
  void has_next_pass(int prefix, int n, int k) {
    for (int i = 0; i < k; ++i) {
      int tmp = prefix + i;
      if (!isVisited.count(tmp)) {
        isVisited.insert(tmp);
        has_next_pass(tmp % int(pow(10, n - 1)) * 10, n, k);
        res.push_back('0' + i); //post order. visit this vertice after dfs.
      }
    }
  }
    string crackSafe(int n, int k) {
      has_next_pass(0, n, k);
      res.append(n - 1, '0');
      return res;
    }
};