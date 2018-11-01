//#312. Burst Balloons
//Hard
//Method: DP. When finding the formula, need to always consider the edge of the subarray (always consider it in the original vector, never seperate it out of it)
//Complexity: Time O(N^3); Space O(N^2)

class Solution {
public:
    //Method 1: complete the input vector, consume more space but save if clause
    int maxCoins(vector<int>& nums) {
        int n = nums.size()
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int> > helper(n + 2, vector<int> (n + 2, 0));

        for (int len = 1; len <= n; ++len) {
            for (int start = 0; start + len < n + 1; ++start) {
                for (int last = start + 1; last < start + len + 1; ++last) {
                    helper[start][start + len + 1] = max(helper[start][start + len + 1], helper[start][last] + helper[last][start + len + 1] + nums[start] * nums[last] * nums[start + len + 1]);
                }
            }
        }

        return helper[0].back();
    }

    //Method 2: use if clause
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<vector<int> > helper(n, vector<int> (n, 0));
        for (int i = 0; i < n; ++i) {
            helper[i][i] = nums[i] * (i == 0 ? 1 : nums[i - 1]) * (i == n - 1 ? 1 : nums[i + 1]);
        }
        for (int len = 2; len <= n; ++len) {
            for (int start = 0; start <= n - len; ++start) {
                for (int last = start; last < start + len; ++last) {
                    int cur = nums[last] * (start == 0 ? 1 : nums[start - 1]) * (start + len == n ? 1 : nums[start + len]);
                    if (last != start) cur += helper[start][last - 1];
                    if (last != start + len - 1) cur += helper[last + 1][start + len - 1];
                    helper[start][start + len - 1] = max(helper[start][start + len - 1], cur);
                }
            }
        }
        return helper[0].back();
    }
};