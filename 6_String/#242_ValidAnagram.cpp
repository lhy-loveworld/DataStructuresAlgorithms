//#242 Valid Anagram
//Easy
//Method: Hash table
//Complexity: Time O(N); Space O(N)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<wchar_t, int> dic;
        for (int i = 0; i < s.size(); ++i) {
            if (dic.count(s[i])) ++dic[s[i]];
            else dic[s[i]] = 1;
            if (dic.count(t[i])) --dic[t[i]];
            else dic[t[i]] = -1;
        }
        for (auto it: dic) {
            if (it.second)
                return false;
        }
        return true;
    }
};