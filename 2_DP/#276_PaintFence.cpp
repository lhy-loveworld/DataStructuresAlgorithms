//#276
//Easy
//Arthor: lhy-loveworld
//Method: No need to store the interim value
//Complexity: time O(N) space O(1)

class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) return 0;
        if (n == 1) return k;
        int same = k, diff = k * (k - 1);
        for (int i = 3; i < n + 1; ++i) {
            int tmp = same;
            same = diff;
            diff = (tmp + diff) * (k - 1);
        }
        return same + diff;
    }
};