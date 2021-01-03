// 813. Largest Sum of Averages.
// Medium.
// DP. When dividing range [a,b] into k parts, first divide it into [a,c] and
// [c+1,b]. And then divide [a,c] to k-1 parts. Recursively.
// TC: O(K*N*N)
// SC: O(N*N)
class Solution {
 public:
  // Method 1: DP
  double largestSumOfAverages(vector<int>& A, int K) {
    int n = A.size();
    std::vector<std::vector<double>> avgs(n, std::vector<double>(n));
    avgs[0][0] = A[0];
    for (int i = 1; i < n; ++i) {
      avgs[i][i] = A[i];
      A[i] += A[i - 1];
    }
    std::vector<double> avgs_k(n);
    std::vector<double> avgs_k_last(n);
    for (int i = 0; i < n; ++i) {
      avgs[0][i] = avgs_k_last[i] = double(A[i]) / (i + 1);
    }
    if (K == 1) return avgs[0][n - 1];
    for (int k = 2; k < K; ++k) {
      for (int end = k; n - end >= K - k; ++end) {
	for (int i = k - 2; i < end - 1; ++i) {
          if (avgs[i + 1][end - 1] == 0) {
            avgs[i + 1][end - 1] = double(A[end - 1] - A[i]) / (end - 1 - i);
          }
          avgs_k[end - 1] = max(avgs_k[end - 1],
				avgs[i + 1][end - 1] + avgs_k_last[i]);
	}
      }
      avgs_k.swap(avgs_k_last);
    }
    double res = 0;
    for (int i = K - 2; i < n - 1; ++i) {
      if (avgs[i + 1][n - 1] == 0) {
        avgs[i + 1][n - 1] = double(A[n - 1] - A[i]) / (n - 1 - i);
      }
      res = max(res, avgs[i + 1][n - 1] + avgs_k_last[i]);
    }
    return res;
  }

  // Method 2: Recursion with memoisation.
  int n_;
  std::vector<std::vector<std::vector<double>>> helper_;
  int K_;
  std::vector<int> A_;
  
  double RecFind(int div, int start, int end) {
    if (div < K_ && helper_[div - 1][start][end] > 0) return helper_[div - 1][start][end];
    if (div == 1) {
      double sum = start > 0 ? A_[end] - A_[start - 1] : A_[end];
      helper_[0][start][end] = sum / (end - start + 1);
      return helper_[0][start][end];
    }
    double res = 0;
    for (int l = 1; end - start + 1 - l >= div - 1; ++l) {
      res = max(res, RecFind(1, start, start + l - 1) + RecFind(div - 1, start + l, end));
    }
    if (div < K_) helper_[div - 1][start][end] = res;
    return res;
  }

  double largestSumOfAverages(vector<int>& A, int K) {
    n_ = A.size();
    for (int i = 1; i < n_; ++i) {
      A[i] += A[i - 1];
    }
    if (K == 1) return A[n_ - 1] / double(n_);
    K_ = K;
    A_ = std::move(A);
    helper_ = std::vector<std::vector<std::vector<double>>>(K - 1, std::vector<std::vector<double>>(n_, std::vector<double>(n_)));
    return RecFind(K, 0, n_ - 1);
  }
};
