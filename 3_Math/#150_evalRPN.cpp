//#150
//Medium
//Method: stack str.back()
//Complexity: time O(n); space O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i].back() <= '9' && tokens[i].back() >= '0') 
                st.push(stoi(tokens[i]));
            else
                switch (tokens[i][0]) {
                    case '+': {
                        int tmp = st.top();
                        st.pop();
                        st.top() += tmp;
                        break;
                    }
                    case '-': {
                        int tmp = st.top();
                        st.pop();
                        st.top() -= tmp;
                        break;
                    }
                    case '*': {
                        int tmp = st.top();
                        st.pop();
                        st.top() *= tmp;
                        break;
                    }
                    case '/': {
                        int tmp = st.top();
                        st.pop();
                        st.top() /= tmp;
                        break;
                    }
                }
        }
        return st.top();
    }
};