//#100
//Easy
//https://leetcode.com/problems/same-tree/description/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL)
            return (p == q);
        else
            return (p->val == q->val) && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
    }

    //BFS
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st_p, st_q;
        st_p.push(p);
        st_q.push(q);
        while (!st_p.empty() && !st_p.empty()) {
            TreeNode* tmp1 = st_p.top(), *tmp2 = st_q.top();
            if (tmp1 == tmp2) {
                st_p.pop();
                st_q.pop();
            }
            else
                if (tmp1 == NULL || tmp2 == NULL)
                    return false;
                else {
                    if (tmp1->val != tmp2->val)
                        return false;
                    else {
                        st_p.pop();
                        st_q.pop();
                        st_p.push(tmp1->left);
                        st_q.push(tmp2->left);
                        st_p.push(tmp1->right);
                        st_q.push(tmp2->right);
                    }
                }
        }
        return true;
    }
};