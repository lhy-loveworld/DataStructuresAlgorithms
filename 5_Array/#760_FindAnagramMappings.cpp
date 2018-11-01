//#760. Find Anagram Mappings
//Easy
//Method: 
//Complexity: Time O(N); Space O(N)

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;
        for (int i = 0; i < B.size(); ++i) {
            mp[B[i]] = i;
        }
        vector<int> res;
        for(auto j: A) res.push_back(mp[j]);
        return res;
    }
};