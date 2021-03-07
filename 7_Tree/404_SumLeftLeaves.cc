// 404. Sum of Left Leaves
// Easy.
// TC: O(N)
// SC: O(1)
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
class Solution {
 public:
  int res;
  void helper(TreeNode* cur, bool left_child) {
    if (cur == nullptr) {
      return;
    }
    if (cur->left == nullptr && cur->right == nullptr) {
      if (left_child) res += cur->val;
    } else  {
      helper(cur->left, true);
      helper(cur->right, false);
    }
  }
  int sumOfLeftLeaves(TreeNode* root) {
    res = 0;
    helper(root, false);
    return res;
  }
};
