//#336. Palindrome Pairs
//Hard
//Method: two methods
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    //Method 1: store each string in dictionary, and for each string, find all its possible matches
    bool isPalindrome(const string& str) {
        if (str.empty()) return true;
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > res;
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); ++i) mp[words[i]] = i;
        for (int i = 0; i < words.size(); ++i) {
            string target;
            for (int j = words[i].size(); j > 0; --j) {
                if (target != words[i] && isPalindrome(words[i].substr(0, j))) {
                    auto it = mp.find(target);
                    if (it != mp.end())
                        res.push_back(vector<int> {it->second, i});
                }
                target.push_back(words[i][j - 1]);
            }
            for (int j = words[i].size(); j >= 0; --j) {
                if (target != words[i] && isPalindrome(words[i].substr(j))) {
                    auto it = mp.find(target);
                    if (it != mp.end())
                        res.push_back(vector<int> {i, it->second});
                }
                if (j > 0) target = target.substr(1);
            }
        }
        return res;
    }

    //Method 2: brutal force optimized with bit masks
    bool checkPal(string word) {
        //cout << word << endl;
        int i = 0, j = word.size() - 1;
        while (i <= j) {
            if (word[i] != word[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<int> masks(words.size());
        vector<vector<int> > res;
        for (int i = 0; i < words.size(); ++i) {
            for (char& c: words[i]) {
                masks[i] ^= (1 << (c - 'a'));
            }
            //cout << masks[i] << endl;
        }
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (i == j) continue;
                if ((words[i].size() + words[j].size()) % 2) {
                    if (((masks[i] ^ masks[j]) & ((masks[i] ^ masks[j]) - 1)) == 0) {
                        if (checkPal(words[i] + words[j])) res.push_back(vector<int> {i, j});
                    }
                } else {
                    if ((masks[i] ^ masks[j]) == 0) {
                        //cout << (masks[i] ^ masks[j]) << endl;
                        if (checkPal(words[i] + words[j])) res.push_back(vector<int> {i, j});
                    }
                }
            }
        }
        return res;
    }
};