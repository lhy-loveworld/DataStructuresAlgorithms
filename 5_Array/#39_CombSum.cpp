//#39. Combination Sum
//Medium
//Method: backtracking
//Complexity: Time O(N!); Space O(N)

class Solution {
    vector<vector<int>> res;
    vector<int> cur_s;
    void helper(vector<int>& c, int t, int cur, int n) {
        for (int i = n; i < c.size(); ++i) {
            if (cur + c[i] > t) {
                return;
            }
            cur_s.push_back(c[i]);
            if (cur + c[i] == t) {
                res.push_back(cur_s);
                cur_s.pop_back();
                return;
            }
            helper(c, t, cur + c[i], i);
            cur_s.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, 0);
        return res;
    }
};