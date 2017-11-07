//#173. Binary Search Tree Iterator
//Medium
//Method: Average O(1)
//Complexity: Time O(1); Space O(h)


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        TreeNode *tmp = root;
        while (tmp) {
            st.push(tmp);
            tmp = tmp->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *res = st.top(), *tmp = res->right;
        st.pop();
        while (tmp) {
            st.push(tmp);
            tmp = tmp->left;
        }
        return res->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */