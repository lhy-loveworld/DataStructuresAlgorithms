//#110. Balanced Binary Tree
//Easy
//Method: recursion
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
    bool res;
public:
    int findDepth(TreeNode* root) {
        if (!root) return 0;
        int dl = findDepth(root->left), dr;
        if (!res) return 0;
        dr = findDepth(root->right);
        if (abs(dl - dr) > 1) res = false;
        return max(dl, dr) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        res = true;
        int dl = findDepth(root->left), dr;
        if (res) {
            dr = findDepth(root->right);
            if (abs(dl - dr) > 1) res = false;
        }
        return res;
    }
};