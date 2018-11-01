//#394. Decode String
//Medium
//Method: recursively, cautious for different kinds of referrence
//Complexity: time O(N). space O(1)

class Solution {
public:
    string decodeHelper(const string& s, size_t& i) {
        string res;
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                size_t t;
                int rep = stoi(s.substr(i), &t);
                i += t + 1;
                string sub = decodeHelper(s, i);
                for (int j = 0; j < rep; ++j) res += sub;
            } else res += s[i];
            ++i;
        }
        return res;
    }
    string decodeString(string s) {
        size_t i = 0;
        return decodeHelper(s, i);
    }
};