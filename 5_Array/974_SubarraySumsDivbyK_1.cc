// 974. Subarray Sums Divisible by K
// Medium
// Track the number of subarrays with the same remainder divided by K.
// TC: O(N)
// SC: O(K)
class Solution {
 public:
  int subarraysDivByK(vector<int>& A, int K) {
    long long sum = 0;
    std::vector<long long> helper(K);
    helper[0] = 1;
    long long res = 0;
    for (int a : A) {
      sum += a;
      int d = sum % K;
      if (d < 0) d += K;
      res += helper[d];
      helper[d]++;
    }
    return res;
  }
};
