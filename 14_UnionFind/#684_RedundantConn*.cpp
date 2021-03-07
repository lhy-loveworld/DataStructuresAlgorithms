//#684. Redundant Connection
//Medium
//Method: union set to test connection
//Complexity: O(NlogN)

class Solution {
public:
  int ds_find(const vector<int> &DisjointSet, int t) {
    while (DisjointSet[t] >= 0) t = DisjointSet[t];
    return t;
  }
  void ds_union(vector<int> &DisjointSet, int r1, int r2) {
    if (DisjointSet[r1] > DisjointSet[r2]) swap(r1, r2);
    DisjointSet[r1] += DisjointSet[r2];
    DisjointSet[r2] = r1;
  }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      vector<int> DisjointSet(edges.size(), -1);
      for (const auto &tmp: edges) {
        int r1 = ds_find(DisjointSet, tmp[0] - 1);
        int r2 = ds_find(DisjointSet, tmp[1] - 1);
        if (r1 == r2) return tmp;
        ds_union(DisjointSet, r1, r2);
      }
    }
};