//#188 Best Time to Buy and Sell Stock IV
//Hard
//Method: DP and priority queue
//Time complexity: O(N to kN) O(N + klog(N))
//Space complexity: O(N)

class Solution {
public:
    //Method 1: DP
    //When k >= n / 2; it is converted to Best Time to But and Sell Stock II, time complexity is only O(N)
    //refer to Best time buy and sell stock iii for more explaination
    //Faster
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
        vector<int> buys(n + 1, 0);
        vector<int> sells(n + 1, 0);
        buys[0] = INT_MIN;
        for (int i = 1; i <= k; ++i) {
            int prev_s = sells[2 * i - 2];
            for (int j = 2 * i - 1; j <= n; ++j) {
                buys[j] = max(buys[j - 1], prev_s - prices[j - 1]);
                prev_s = sells[j];
                sells[j] = max(sells[j - 1], buys[j - 1] + prices[j - 1]);
            }
        }
        return sells.back();
    }

    //Method 2: use a priority queue to store all the profits, use a a stack to store all the peak-valley pair
    //When dealing with 2 adjacent pairs, if the valley of the former one is lower than the latter one's, 
    //we need to transform the presentation of the profits of these two(or more, that's why we use stack)
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