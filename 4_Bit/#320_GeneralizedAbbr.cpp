//#320
//Medium
//Arthor: lhy-loveworld
//Method: Bitmap or backtrack
//Complexity: Time O(2^n); Space O(1)

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int len = word.size();
        vector<string> res;
        for (int i = 0; i < (1 << len); ++i) {
            int mask = 1;
            int n = 0;
            string tmp;
            for (int j = 0; j < len; ++j) {
                if (i & mask) {
                    if (n) {
                        tmp += to_string(n);
                        n = 0;
                    }
                    tmp.push_back(word[j]);
                } else {
                    ++n;
                }
                mask <<= 1;
            }
            if (n)
                tmp += to_string(n);
                
            res.push_back(tmp);
        }
        return res;
    }
};