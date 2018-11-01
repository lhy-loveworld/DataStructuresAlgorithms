//#843. Guess the Word
//Hard
//Method: every time search from the string have the most matches with others, which can eliminate most alternatives
//Complexity: time O(N^2). space O(N)

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int num_match(const string& s1, const string& s2) {
        int match = 0;
        for (int j = 0; j < 6; ++j) match += (s1[j] == s2[j]);
        return match;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        unordered_map<string, int> M;
        string maxstr = wordlist[0];
        int maxnum = 0;
        for (int i = 0; i + 1 < wordlist.size(); ++i) {
            for (int j = i + 1; j < wordlist.size(); ++j) {
                if (num_match(wordlist[i], wordlist[j]) > 0) {
                    M[wordlist[i]]++;
                    M[wordlist[j]]++;
                    if (M[wordlist[i]] > maxnum) {
                        maxstr = wordlist[i];
                        maxnum = M[wordlist[i]];
                    }
                    if (M[wordlist[j]] > maxnum) {
                        maxstr = wordlist[j];
                        maxnum = M[wordlist[j]];
                    }
                }
            }
        }
        
        int t = master.guess(maxstr);
        if (t == 6) return;
        vector<string> newlist;
        for (int i = 0; i < wordlist.size(); ++i) {
            if (num_match(maxstr, wordlist[i]) == t) newlist.push_back(wordlist[i]);
        }
        wordlist = newlist;
        return findSecretWord(wordlist, master);
    }
};