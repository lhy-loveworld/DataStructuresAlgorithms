//#318
//Medium
//Arthor: lhy-loveworld
//Method: Bitmask for each string.
//Complexity: Time O(N^2); Space O(N)

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        unordered_map<int, int> mask_len;
        for (string str: words) {
            int mask = 0;
            for (char ch: str) {
                mask |= (1 << ch - 'a');
            }
            mask_len[mask] = max(mask_len[mask], (int) str.size())
            for (auto tuple: mask_len) {
                if ((mask & tuple.first) == 0) {
                    res = max(res, mask_len[mask] * tuple.second);
                }
            }
        }
        return res;
    }
};