//#543. Diameter of Binary Tree
//Easy
//Method: caution for the return value of the recursion
//Complexity: time O(N)

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
    int res;
    int rec(TreeNode* root) {
        int curLeft = 0, curRight = 0;
        if (root->left) curLeft = (rec(root->left) + 1);
        if (root->right) curRight = (rec(root->right) + 1);
        res = max(curLeft + curRight, res);
        return max(curLeft, curRight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        if (!root) return res;
        rec(root);
        return res;
    }
};