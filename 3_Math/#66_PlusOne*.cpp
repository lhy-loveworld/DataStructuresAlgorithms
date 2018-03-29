//#66. Plus One
//Easy
//Method: caution for overflow
//Complexity: time O(n); space O(n)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c_o = 0;
        list<int> res;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int t = digits[i] + c_o;
            if (i == digits.size() - 1) t++;
            if (t >= 10) {
                c_o = 1;
                t = t % 10;
            }
            else c_o = 0;
            res.push_front(t);
        }
        if (c_o) res.push_front(1);
        return vector<int> (res.begin(), res.end());
    }
};