//#188 Best Time to Buy and Sell Stock IV
//Hard
//Method: DP and priority queue
//Time complexity: O(N to kN) O(N + klog(N))
//Space complexity: O(N)

class Solution {
 public:
  // Method 1: DP
  // When k >= n / 2; it is converted to Best Time to But and Sell Stock II (with unlimited trade times), time complexity is only O(N)
  // Since there is at most one trade at a time, there are only two status: after_buy and after_sell.
  // buys[k][n] = max(buys[k][n - 1], sells[k - 1][n] - price[n])
  // sells[k][n] = max(sells[k][n - 1], buys[k][n] + price[n])
  // You cannot buy/sell more than once in a single day. So status[k][n] can only compare with status[k][n-1].
  int maxProfit(int k, vector<int>& prices) {
    if (prices.empty() || k == 0) return 0;
    int n = prices.size();
    int res = 0;
    if (k >= n / 2) {
      int res = 0;
        for (int i = 1; i < n; ++i) {
            res += max(0, prices[i] - prices[i - 1]);
        }
	return res;
    }
    vector<int> buys(n + 1, INT_MIN);
    vector<int> sells(n + 1, 0);
    // Outer k, inner n.
    for (int i = 1; i <= k; ++i) {
      buys[2 * i - 1] = max(buys[2 * i - 2], sells[2 * i - 1] - prices[2 * i - 2]); // k buys require at least 2k-1 days.
      for (int j = 2 * i; j <= n; ++j) { // k sells require at least 2k days.
	buys[j] = max(buys[j - 1], sells[j] - prices[j - 1]);
        sells[j] = max(sells[j - 1], buys[j] + prices[j - 1]);
      }
    }
    return sells.back();
  }

  // Method 2: Outer n, inner k.
  int maxProfit(int k, vector<int>& prices) {
    if (prices.size() < 2 || k == 0) return 0;
    int res = 0;
    if (prices.size() / 2 < k) {
      for (int i = 1; i < prices.size(); ++i) {
	if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
      }
      return res;
    }
    std::vector<int> buys(k + 1, INT_MIN), sells(k + 1);
    for (int i = 0; i < prices.size(); ++i) {
      for (int j = 1; j <= k; ++j) {
        buys[j] = max(sells[j - 1] - prices[i], buys[j]);
	sells[j] = max(buys[j] + prices[i], sells[j]);
      }
    }
    return sells[k];
  }
  
  // Method 3: https://docs.google.com/document/d/1avhSSnPpXN_dEJr09MGfR01-LzaSqMsJqd3Jj56onFE/edit?usp=sharing
  int maxProfit(int k, vector<int>& prices) {
    if (k == 0 || prices.empty()) return 0;
    stack<pair<int, int> > vp_s;
    priority_queue<int> pro;
    int v = 0, p = 0;
    while (p != prices.size()) {
      for (v = p; v < prices.size() - 1 && prices[v + 1] <= prices[v]; ++v);
      if (v == prices.size() - 1) break;
      for (p = v + 1; p < prices.size() && prices[p] >= prices[p - 1]; ++p);
      while (!vp_s.empty() && prices[vp_s.top().first] >= prices[v]) {
	pro.push(prices[vp_s.top().second - 1] - prices[vp_s.top().first]);
        vp_s.pop();
      }
      while (!vp_s.empty() && prices[p - 1] > prices[vp_s.top().second - 1]) {
	pro.push(prices[vp_s.top().second - 1] - prices[v]);
        v = vp_s.top().first;
	vp_s.pop();
      }
      vp_s.push(pair<int, int>(v, p));
    }
    while (!vp_s.empty()) {
      pro.push(prices[vp_s.top().second - 1] - prices[vp_s.top().first]);
      vp_s.pop();
    }
    int res = 0;
    for (int i = 0; i < k && !pro.empty(); ++i) {
      res += pro.top();
      pro.pop();
    }
    return res;
  }
};
