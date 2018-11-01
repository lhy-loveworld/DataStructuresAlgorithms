//#272. Closest Binary Search Tree Value II
//Hard
//Method: first find the closest positionof target, track the path in two stacks (one is larger than target, one is smaller).
//        then trace back the path
//Complexity: time O(klogN < N). space O(logN)

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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> smaller, larger;
        vector<int> res;
        TreeNode* cur = root;
        while (cur) {
            if (cur->val < target) {
                smaller.push(cur);
                cur = cur->right;
            } else {
                larger.push(cur);
                cur = cur->left;
            }
        }
        while (1) {
            if (smaller.empty() || (!larger.empty() && target - smaller.top()->val > larger.top()->val - target)) {
                cur = larger.top();
                larger.pop();
                res.push_back(cur->val);
                if (--k == 0) return res;
                cur = cur->right;
                while (cur) {
                    larger.push(cur);
                    cur = cur->left;
                }
            } else {
                cur = smaller.top();
                smaller.pop();
                res.push_back(cur->val);
                if (--k == 0) return res;
                cur = cur->left;
                while (cur) {
                    smaller.push(cur);
                    cur = cur->right;
                }
            }
        }
    }
};