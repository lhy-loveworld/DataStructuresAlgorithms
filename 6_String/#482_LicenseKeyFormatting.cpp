//#482. License Key Formatting
//Easy
//Method:
//Complexity: time O(N)

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int curLen = 0;
        for (auto it = S.rbegin(); it != S.rend(); ++it) {
            if (*it == '-') continue;
            res = islower(*it) ? (char(toupper(*it)) + res) : (*it + res);
            curLen++;
            if (curLen == K) {
                curLen = 0;
                res = '-' + res;
            }
        }
        if (res[0] == '-') res = res.substr(1);
        return res;
    }
};