//#518. Coin Change 2
//Medium
//Method: dp
//Time complexity: O(MN)
//Space complexity: O(M)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> helper(amount + 1, 0);
        helper[0] = 1;
        for (auto i: coins) {
            for (int j = 0; j < amount; ++j) {
                if (helper[j] == 0) continue;
                if (j + i <= amount) helper[j + i] += helper[j];
            }
        }
        return helper.back();
    }
};