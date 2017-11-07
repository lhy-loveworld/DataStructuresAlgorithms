//#38. Count and Say
//Easy
//Method: static vector
//Complexity: Time O(N); Space O(N)

class Solution {
public:
    string countAndSay(int n) {
        static vector<string> v(1, "1");
        if (n <= v.size())
            return v[n - 1];
        for (int i = v.size(); i < n; ++i) {
            string next;
            int j = 1;
            int num = 1;
            char ch = v.back()[0];
            while (j < v.back().size()) {
                if (ch == v.back()[j]) {
                    num++;
                } else {
                    next += (to_string(num) + ch);
                    num = 1;
                    ch = v.back()[j];
                }
                j++;
            }
            next += (to_string(num) + ch);
            v.push_back(next);
        }
        return v.back();
    }
};