//#235 Lowest Common Ancestor of a Binary Search Tree
//Easy
//Method: Iteration / Recursion
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
public:
    //Method 1: iteration
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if (!p || !q) return (p ? p : q);
        while ((root->val - p->val) * (root->val - q->val) > 0) {
            root = (root->val > p->val) ? root->left : root->right;
        }
        return root;
    }

    //Method 2: recursion
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        if (!p || !q) return (p ? p : q);
        if ((root->val - p->val) * (root->val - q->val) <= 0) return root;
        if (root->val > p->val) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
    }
};