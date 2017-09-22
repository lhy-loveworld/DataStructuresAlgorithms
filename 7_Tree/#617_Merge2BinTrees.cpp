//#617 Merge Two Binary Trees
//Easy
//Method: Subtree and recursion / stack
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
    //Method 1: recursion
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 || !t2) return ((t1) ? t1 : t2);
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }

    //Method 2: stack
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 || !t2) return ((t1) ? t1 : t2);
        stack<pair<TreeNode*, TreeNode*> > helper;
        helper.push(pair<TreeNode*, TreeNode*> (t1, t2));
        while (!helper.empty()) {
            TreeNode* tmp1 = helper.top().first;
            TreeNode* tmp2 = helper.top().second;
            helper.pop();
            tmp1->val += tmp2->val;
            if (tmp1->left && tmp2->left)
                helper.push(pair<TreeNode*, TreeNode*> (tmp1->left, tmp2->left));
            else
                tmp1->left = ((tmp1->left) ? tmp1->left : tmp2->left);
            if (tmp1->right && tmp2->right)
                helper.push(pair<TreeNode*, TreeNode*> (tmp1->right, tmp2->right));
            else
                tmp1->right = ((tmp1->right) ? tmp1->right : tmp2->right);
        }
        return t1;
    }
};