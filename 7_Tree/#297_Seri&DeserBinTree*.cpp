//#297. Serialize and Deserialize Binary Tree
//Hard
//Method: Use of recursion and stack, another way is to store each int into four characters (serialization)
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
class Codec {
    TreeNode* subdeserialize(string& data) {
        if (data.empty() || data[0] == 'R') {
            if (data[0] == 'R')
                data = data.substr(1);
            return NULL;
        }
        size_t pos;
        TreeNode* root = new TreeNode (stoi(data, &pos));
        data = data.substr(pos + 1);
        root->left = subdeserialize(data);
        root->right = subdeserialize(data);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        return to_string(root->val) + 'L' + serialize(root->left) + 'R' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    //Method 1: recursively
    TreeNode* deserialize(string data) {
        return subdeserialize(data);
    }

    //Method 2: using stack
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        size_t pos;
        TreeNode* root = new TreeNode (stoi(data, &pos));
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* cur = st.top();
        data = data.substr(pos);
        while (!data.empty()) {
            if (data[0] == 'L') {
                data = data.substr(1);
                if (data[0] != 'R') {
                    cur->left = new TreeNode (stoi(data, &pos));
                    data = data.substr(pos);
                    st.push(cur->left);
                }
            } else {
                st.pop();
                data = data.substr(1);
                if (data.empty()) return root;
                if (data[0] != 'R') {
                    cur->right = new TreeNode (stoi(data, &pos));
                    data = data.substr(pos);
                    st.push(cur->right);
                }
            }
            cur = st.top();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));