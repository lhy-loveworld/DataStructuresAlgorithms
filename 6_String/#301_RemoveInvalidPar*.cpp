//#301. Remove Invalid Parentheses
//Hard
//Method: DFS and BFS
//Complexity: Time O(N^M) ; Space O(N^M); (M = number of parentheses needed to be removed + 1)

class Solution {
    vector<string> res;

    //Method 1: DFS
    //Everytime find out the the parenthese that must be deleted, and then find out the next, using recursion
    //When you need to delete a parenthese, you need to look back to find out the exact one.
    //Track the start point of searching to reduce unnecessary search
    //Track the start point of deleting to eliminate duplicate
    //Everytime only delete the first parenthese if there are consecutive ones
    void CheckPair(string s, int beg, int del, char a, char b) {
        int cnt = 0;
        int idx = beg;
        for (; idx < s.size(); ++idx) {
            if (s[idx] == a) cnt++;
            else if (s[idx] == b)
                if (--cnt < 0) break;
        }
        if (!cnt) {
            if (a == ')') reverse(s.begin(), s.end());
            res.push_back(s);
        } else {
            if (cnt > 0) {
                reverse(s.begin(), s.end());
                CheckPair(s, 0, 0, ')', '(');
            } else {
                for (int i = del; i <= idx; ++i)
                    if (s[i] == b && (i == del || s[i - 1] != b))
                        CheckPair(s.substr(0, i) + s.substr(i + 1), idx, i, a, b);
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        CheckPair(s, 0, 0, '(', ')');
        return res;
    }

    //Method 2: BFS
    //Try to remove every possible possible parenthese, and check if they are valid
    //Use a queue to store each level
    //Use the following rules to reduce duplicated computing:
    //1. Everytime only remove the first one among consecutive parentheses.
    //2. Record the position of last removement.
    //3. Never remove ) after removing (
    //      The removement can be ))) or ((( or )))(((
    bool isValid(const string &s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') cnt++;
            else if (s[i] == ')') {
                cnt--;
                if (cnt < 0)
                    return false;
            }
        }
        return (cnt == 0);
    }
    vector<string> removeInvalidParentheses(string s) {
        if (isValid(s)) 
            return vector<string> {s};
        queue<tuple<string, int, char>> Q;
        Q.push(make_tuple(s, 0, ')'));
        while (!Q.empty() && res.empty()) {
            int n = Q.size();
            for (int j = 0; j < n; ++j) {
                string str = get<0>(Q.front());
                int beg = get<1>(Q.front());
                char last = get<2>(Q.front());
                Q.pop();
                for (int i = beg; i < str.size(); ++i) {
                    if (i != beg && str[i] == str[i - 1]) continue;
                    if (str[i] == '(' || str[i] == ')' && last != '(') {
                        string n_str = str.substr(0, i) + str.substr(i + 1);
                        if (isValid(n_str)) res.push_back(n_str);
                        else Q.push(make_tuple(n_str, i, str[i]));
                    }
                }
            }
        }
        return res;
    }
};