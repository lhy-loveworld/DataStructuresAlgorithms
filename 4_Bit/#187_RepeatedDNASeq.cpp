//#187
//Medium
//Arthor: lhy-loveworld
//Method: Two methods
//Complexity: Time O(N); Space O(N)

class Solution {
public:
    //First method, build a string map
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> dict;
        if (s.size() < 11) return res;
        for (int i = 0; i < s.size() - 9; ++i) {
            string tmp = s.substr(i, 10);
            if (dict[tmp]++ == 1)
                res.push_back(tmp);
        }
        return res;
    }

    //Second method, use a number to represent each string sequence
    //Because there's only 4 possible letters in total, and the difference between their binay form is only 3 bits, we can use 30 bits to represent each sequence.
    vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> r;
    int t = 0, i = 0, ss = s.size();
    while (i < 9)
        t = t << 3 | s[i++] & 7;
    while (i < ss)
        if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
            r.push_back(s.substr(i - 10, 10));
    return r;
    }
};