//#314. Binary Tree Vertical Order Traversal
//Medium
//Method: Level order trasversal to ensure their vertical order, use a number to record horizontal order
//Complexity: Time O(N); Space O(N)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return vector<vector<int> > ();
        queue<pair<TreeNode*, int> > Q;
        deque<vector<int> > res(1);
        int base = 0;
        Q.push(make_pair(root, 0));
        while (!Q.empty()) {
            int n = Q.size();
            for (int i = 0; i < n; ++i) {
                int d = Q.front().second;
                TreeNode* cur = Q.front().first;
                Q.pop();
                if (d < base) {
                    res.push_front(vector<int> ());
                    base--;
                } else if (d > base + int(res.size()) - 1) {
                    res.push_back(vector<int> ());
                }
                res[d - base].push_back(cur->val);
                if (cur->left) Q.push(make_pair(cur->left, d - 1));
                if (cur->right) Q.push(make_pair(cur->right, d + 1));
            }
        }
        return vector<vector<int> > (res.begin(), res.end());
    }
};