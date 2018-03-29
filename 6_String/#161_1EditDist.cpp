//#161. One Edit Distance
//Medium
//Method: 
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (max(s.size(), t.size()) - min(s.size(), t.size()) > 1 || (s == t)) return false;
        if (s.empty() || t.empty()) return true;
        if (s.size() < t.size()) {
            swap(s, t)
        }
        int nsame = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (s[i] == t[i])
                nsame++;
            else
                break;
        }
        if (nsame == t.size()) return true;
        for (int i = 0; i < t.size(); ++i) {
            if (s[s.size() - 1 - i] == t[t.size() - 1 - i])
                nsame++;
            else
                break;
        }
        return nsame == s.size() - 1;
    }
};