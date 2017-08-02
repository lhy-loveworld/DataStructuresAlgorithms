//#101
//Easy
//Arthor: lhy-loveworld
//Method: Use of DFS and BFS
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
    //DFS
    bool isSymmetric(TreeNode* root) {
        return (!root) || isSym(root->left, root->right);
    }
    
    bool isSym(TreeNode* node1, TreeNode* node2) {
        if (node1 == node2)
            return true;
        else if (node1 == NULL || node2 == NULL) {
            return false;
        } else {
            return (node1->val == node2->val) && isSym(node1->left, node2->right) && isSym(node2->left, node1->right);
        }
    }

    //BFS
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        stack<TreeNode*> st1, st2;
        st1.push(root->left);
        st2.push(root->right);
        while (!st1.empty() && !st2.empty()) {
            TreeNode *tmp1 = st1.top(), *tmp2 = st2.top();
            st1.pop();
            st2.pop();
            if (tmp1 != tmp2) {
                if (tmp1 == NULL || tmp2 == NULL)
                    return false;
                else {
                    if (tmp1->val != tmp2->val)
                        return false;
                    else {
                        st1.push(tmp1->left);
                        st1.push(tmp1->right);
                        st2.push(tmp2->right);
                        st2.push(tmp2->left);
                    }
                }
            }
        }
        return (st1.empty() && st2.empty());
    }
};