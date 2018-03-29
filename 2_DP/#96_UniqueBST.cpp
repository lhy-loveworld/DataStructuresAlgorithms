//#96_Unique Binary Search Trees
//Medium
//Method: DP, when solving tree related problems should consider the structure of the tree
//        find the relationship between one and its subtree
//Time complexity: O(N), Space complexity: O(N)

class Solution {
public:
    int numTrees(int n) {
        vector<int> helper(n + 1, 0);
        helper[0] = 1;
        helper[1] = 1;
        for (int i = 2; i < n + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                helper[i] += (helper[j] * helper[i - 1 -j]);
            }
        }
        return helper[n];
    }
};