//#236. Lowest Common Ancestor of a Binary Tree
//Medium
//Method: Using stack to track path or recursively
//Complexity: Time O(N); Space O(h)


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
    //Method 1: using a stack to track the path of finding a node
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;
        TreeNode* to_find = NULL, *cur = root, *prev = root;
        int Min;
        TreeNode* res;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
                if (!to_find && (st.top() == p || st.top() == q)) {
                    to_find = (st.top() == p) ? q : p;
                    Min = st.size();
                    res = st.top();
                }
                if (to_find && st.top() == to_find)
                    return res;
            }
            if (!st.top()->right || prev == st.top()->right) {
                prev = st.top();
                st.pop();
                if (to_find && st.size() < Min) {
                    Min = st.size();
                    res = st.top();
                }
            } else
                cur = st.top()->right;
        }
    }

    //Method 2: recursively
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* res1 = lowestCommonAncestor(root->left, p, q), *res2 = lowestCommonAncestor(root->right, p, q);
        if (res1 && res2) return root;
        return (res1) ? res1 : res2;
    }
};