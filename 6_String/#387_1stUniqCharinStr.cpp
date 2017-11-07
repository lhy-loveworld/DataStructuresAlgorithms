//#387. First Unique Character in a String
//Easy
//Method: Only contains lower case letter, store the times each character shows, two loops
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> pos(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (pos[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};