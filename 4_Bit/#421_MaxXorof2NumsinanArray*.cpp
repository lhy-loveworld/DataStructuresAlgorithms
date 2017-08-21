//#421
//Medium
//Arthor: lhy-loveworld
//Method: Use tree structure to store the array
//        Need to compare from the MSB, thus only need to search once for each number
//        Also need to be cautious about that the maximum number of int type is 1 << 30 rather than 1 << 31
//        And the times of iteration
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    class TreeNode {
        public:
            TreeNode* next[2];
            TreeNode() {next[0] = NULL; next[1] = NULL;}
            void buildTree(vector<int>& nums) {
                for (int i = 0; i < nums.size(); ++i) {
                    int mask = 1 << 30;
                    TreeNode *cur = this;
                    for (int j = 0; j < 31; j++) {
                        int index = (mask & nums[i]) > 0;
                        if (cur->next[index] == NULL)
                            cur->next[index] = new TreeNode;
                        mask >>= 1;
                        cur = cur->next[index];
                    }
                }
            }
    };
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int max = 0;
        TreeNode TN;
        TN.buildTree(nums);
        for (int i = 0; i < nums.size(); ++i) {
            int mask = 1 << 30;
            TreeNode* cur = &TN;
            for (int j = 0; j < 31; j++) {
                int index = (mask & nums[i]) == 0;
                if (cur->next[index]) {
                    res |= mask;
                    cur = cur->next[index];
                } else {
                    cur = cur->next[1 - index];
                }
                mask >>= 1;
            }
            if (res > max)
                max = res;
            res = 0;
        }
        return max;
    }
};