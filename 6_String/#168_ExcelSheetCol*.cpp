//#168. Excel Sheet Column Title
//Easy
//Method: Relationship between n and res, char + string
//Complexity: Time O(1); Space O(1)

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            int rem = n % 26 ? n % 26 : 26;
            char c = 'A' + rem - 1;
            res = c + res;
            n = (n - rem) / 26;
        }
        return res;
    }
};