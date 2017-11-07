//#49. Group Anagrams
//Medium
//Method: Two methods
//Complexity: Time O(MN); Space O(N)

class Solution {
public:
    //Method 1: use product of prime numbers as a hush function to represent each string
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        vector<int> v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        unordered_map<long long, vector<string> > m;
        for (int i = 0; i < strs.size(); ++i) {
            long long tmp = 1;
            for (int j = 0; j < strs[i].size(); ++j) {
                tmp *= v[strs[i][j] - 'a'];
            }
            m[tmp].push_back(strs[i]);
        }
        for (auto it = m.begin(); it != m.end(); ++it)
            res.push_back(it->second);
        return res;
    }

    //Method 2: Sort the string and use the sorted string as the key for the map
    string Sort(string s) {
        vector<int> m(26, 0);
        for (int j = 0; j < s.size(); ++j)
            m[s[j] - 'a']++;
        string t(s.size(), 'a');
        int start = 0;
        for (int j = 0; j < 26; ++j) {
            for (int i = start; i < start + m[j]; ++i)
                t[i] += j;
            start += m[j];
        }
        return t;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > m;
        for (int i = 0; i < strs.size(); ++i) {
            string t = Sort(strs[i]);
            m[t].push_back(strs[i]);
        }
        for (auto it = m.begin(); it != m.end(); ++it)
            res.push_back(it->second);
        return res;
    }
};