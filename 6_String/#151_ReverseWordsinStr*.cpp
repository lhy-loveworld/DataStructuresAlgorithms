//#151. Reverse Words in a String
//Medium
//Method: First reverse each word and adjust their position, and then reverse the whole string and adjust size.
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    void RW(string &s, int l, int r) {
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
    void reverseWords(string &s) {
        if (s.empty()) return;
        int p = 0, b = 0, e = -1;
        while (p < s.size()) {
            while (p < s.size() && s[p] == ' ') p++;
            if (p == s.size()) break;
            int cur_beg = p;
            int cur_end = p + 1;
            while (cur_end < s.size() && s[cur_end] != ' ') cur_end++;
            RW(s, cur_beg, cur_end - 1);
            while (cur_beg < cur_end) {
                s[b++] = s[cur_beg++];
            }
            e = b - 1;
            if (b == s.size()) break;
            s[b++] = ' ';
            p = cur_end;
        }
        RW(s, 0, e);
        s.resize(e + 1);
    }
};