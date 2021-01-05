// 1261. Find Elements in a Contaminated Binary Tree
// Medium
// TC: O(N), O(1)
// SC: O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
 public:
  std::vector<bool> tracker_;

  FindElements(TreeNode* root) {
    std::stack<TreeNode*> st;
    tracker_ = std::vector<bool>(1000001);
    root->val = 0;
    st.push(root);
    while (!st.empty()) {
      TreeNode* top = st.top();
      st.pop();
      if (top->left != nullptr) {
        top->left->val = 2 * top->val + 1;
        if (top->left->val < 1000001) tracker_[top->left->val] = true;
        st.push(top->left);
      }
      if (top->right != nullptr) {
        top->right->val = 2 * top->val + 2;
        if (top->right->val < 1000001) tracker_[top->right->val] = true;
	st.push(top->right);
      }
    }
  }
    
  bool find(int target) {
    return target == 0 || tracker_[target];
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
