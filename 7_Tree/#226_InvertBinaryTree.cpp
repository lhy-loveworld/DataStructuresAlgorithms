//#226
//Easy
//https://leetcode.com/problems/invert-binary-tree/description/
//Arthor: lhy-loveworld
//Method: Use of DFS and BFS
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
	//DFS
    TreeNode* invertTree(TreeNode* root) {
        if (root != NULL) {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
    
    //BFS
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* tmp = st.top();
            st.pop();
            if (tmp != NULL) {
                st.push(tmp->left);
                st.push(tmp->right);
                swap(tmp->left, tmp->right);
            }
        }
        return root;
    }
};