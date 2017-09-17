//#72 Edit Distance
//Hard
//Method: DP.
//Time complexity: O(M*N)
//Space complexity: O(N)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> helper(n + 1, 0);
        int prev;
        for (int i = 1; i <= n; ++i)
            helper[i] = i;
        for (int i = 1; i <= m; ++i) {
            prev = helper[0];
            helper[0] = i;
            for (int j = 1; j <= n; ++j) {
                swap(helper[j], prev);
                if (word1[i - 1] != word2[j - 1])
                    helper[j] = min(helper[j - 1] + 1, min(prev + 1, helper[j] + 1));
            }
        }
        return helper.back();
    }
};