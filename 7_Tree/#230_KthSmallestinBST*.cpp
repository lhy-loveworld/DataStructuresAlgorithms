//#230. Kth Smallest Element in a BST
//Medium
//Method: in-order traverse, when an element is pushed into stack, push its left child as well,
//        when a element is poped out of stack, process its right child in the next iteration

//        Morris inorder traverse
//        If the BST is frequently inserted or deleted, we can modify the TreeNode struct to add a new field to store the size of its left subtree
//        or we can use a seperate map to store the TreeNode->val to size of left subtree
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
    //Method 1: inorder traverse using stack
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            if (--k == 0) return st.top()->val;
            cur = st.top()->right;
            st.pop();
        }
    }

    //Method 2: Morris inorder traversal without using stack but need to modify the tree structure
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        while (cur) {
            if (!cur->left) {
                if (--k == 0)
                    return cur->val;
                cur = cur->right;
            } else {
                TreeNode* cur_l = cur->left;
                while (cur_l->right && cur_l->right != cur)
                    cur_l = cur_l->right;
                if (!cur_l->right) {
                    cur_l->right = cur;
                    cur = cur->left;
                } else {
                    cur_l->right = NULL;
                    if (--k == 0)
                        return cur->val;
                    cur = cur->right;
                }
            }
        }
    }
};