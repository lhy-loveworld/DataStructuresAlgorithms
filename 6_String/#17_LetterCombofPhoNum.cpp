//#17. Letter Combinations of a Phone Number
//Medium
//Method: Backtrack, DFS
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    vector<string> helper = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; //Caution for the position of this initialization and the way to do it.
    void build_vct(vector<string> &res, int cur_pos, int max_pos, string str, string d) {
        if (cur_pos == max_pos) {
            res.push_back(str);
            return;
        }
        for (int i = 0; i < helper[d[cur_pos] - '0' - 2].size(); ++i) {
            build_vct(res, cur_pos + 1, max_pos, str + helper[d[cur_pos] - '0' - 2][i], d);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        build_vct(res, 0, digits.size(), "", digits);
        return res;
    }
};
