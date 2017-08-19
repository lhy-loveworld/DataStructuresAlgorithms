//#320
//Medium
//Arthor: lhy-loveworld
//Method: Bitmap or backtrack
//Complexity: Time O(2^n); Space O(1)

class Solution {
public:
    //bitmap
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

    //backtrack
    void GenSub(vector<string>& res, string word, string tmp, int cur, int count) {
        for (int i = cur; i < word.size(); ++i) {
            if (count)
                tmp += (to_string(count));
            tmp.push_back(word[i]);
            GenSub(res, word, tmp, i + 1, 0);
            do
                tmp.pop_back();
            while (tmp.back() >= '0' && tmp.back() <= '9');
            ++count;
        }
        if (count)
            tmp += (to_string(count));
        res.push_back(tmp);
    }
    
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        string tmp;
        GenSub(res, word, tmp, 0, 0);
        return res;
    }
};