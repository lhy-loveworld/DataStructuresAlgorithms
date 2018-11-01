//#315. Count of Smaller Numbers After Self
//Hard
//Method: use a tree, to record the size of left tree of each number, and the number of duolications
//Complexity: time O(nlogn) space O(n)

class Solution {
public:
    struct treeNode {
        int val;
        int leftSize;
        int dup;
        treeNode* left, *right;
        treeNode(int i): val(i), leftSize(0), dup(1), left(nullptr), right(nullptr) {}
    };
    int insert(treeNode* root, int cur) {
        int res = 0;
        treeNode* curNode = root;
        while (1) {
            if (cur == curNode->val) {
                curNode->dup++;
                return res + curNode->leftSize;
            }
            if (cur < curNode->val) {
                curNode->leftSize++;
                if (!curNode->left) {
                    curNode->left = new treeNode(cur);
                    return res;
                }
                curNode = curNode->left;
            } else {
                res += (curNode->leftSize + curNode->dup);
                if (!curNode->right) {
                    curNode->right = new treeNode(cur);
                    return res;
                }
                curNode = curNode->right;
            }
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return nums;
        treeNode* root = nullptr;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (!root) {
                root = new treeNode(nums[i]);
                nums[i] = 0;
            } else
                nums[i] = insert(root, nums[i]);
        }
        return nums;
    }
};