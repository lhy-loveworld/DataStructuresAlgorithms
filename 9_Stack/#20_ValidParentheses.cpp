//#20
//Easy
//https://leetcode.com/problems/valid-parentheses/description/
//Arthor: lhy-loveworld
//Method: Use of stack
//Complexity: Time O(N); Space O(N)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                switch (s[i]) {
                    case ')':
                        if (st.empty() || st.top() != '(')
                            return false;
                        break;
                    case '}':
                        if (st.empty() || st.top() != '{')
                            return false;
                        break;
                    case ']':
                        if (st.empty() || st.top() != '[')
                            return false;
                }
                st.pop();
            }
        }
        return (st.empty());
    }
};