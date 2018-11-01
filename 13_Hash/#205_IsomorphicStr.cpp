//#205. Isomorphic Strings
//Easy
//Method: unordered_map
//Complexity: time O(N). space O(N)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_set<char> tOccur;
        for (auto i = 0; i < s.size(); ++i) {
            auto it = s2t.find(s[i]);
            if (it == s2t.end()) {
                if (tOccur.count(t[i])) return false;
                s2t[s[i]] = t[i];
                tOccur.insert(t[i]);
            } else {
                if (it->second != t[i]) return false;
            }
        }
        return true;
    }
};