//#316. Remove Duplicate Letters
//Hard
//Method: as long as we still have remaining letters, we can substitute it with a lower one
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> numLeft(26);
        vector<bool> isChosen(26);
        string res;
        for (char& c: s) numLeft[c - 'a']++;
        for (char& c: s) {
            if (!isChosen[c - 'a']) {
                while (!res.empty() && res.back() > c && numLeft[res.back() - 'a']) {
                    isChosen[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(c);
                isChosen[c - 'a'] = true;
            }
            numLeft[c - 'a']--;
        }
        return res;
    }
};