//#102. Binary Tree Level Order Traversal
//Medium
//Method: two methods
//Complexity: Time O(N); Space O(1)

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
    vector<vector<int> > res;
public:
    //Method 1: recursive
    void Helper(TreeNode* t, int d) {
        if (!t) return;
        if (res.size() == d)
            res.push_back(vector<int> ());
        res[d].push_back(t->val);
        Helper(t->left, d + 1);
        Helper(t->right, d + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        Helper(root, 0);
        return res;
    }

    //Method 2: using a queue
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return res;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int n = Q.size();
            vector<int> V;
            for (int i = 0; i < n; ++i) {
                TreeNode* tmp = Q.front();
                Q.pop();
                V.push_back(tmp->val);
                if (tmp->left) Q.push(tmp->left);
                if (tmp->right) Q.push(tmp->right);
            }
            res.push_back(V);
        }
        return res;
    }
};