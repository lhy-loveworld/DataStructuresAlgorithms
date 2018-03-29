//#224. Basic Calculator
//Hard
//Method: Recursion and stack
//Complexity: time O(n); space O(1)

class Solution {
    //Method 1: stack, one for operands, one for operators
    //everytime calculate when the next operator shows up.
    int helper(string &s) {
        stack<int> oprd;
        stack<int> oprt;
        oprd.push(0);
        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && s[i] == ' ') ++i;
            while (i < s.size() && s[i] <= '9' && s[i] >= '0') {
                oprd.top() = oprd.top() * 10 + s[i] - '0';
                i++;
            }
            if (i < s.size() && s[i] == '(') {
                oprt.push(0);
                i++;
            }
            if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
                if (!oprt.empty() && oprt.top() != 0) {
                    int t = oprd.top();
                    oprd.pop();
                    oprd.top() += t * oprt.top();
                    oprt.pop();
                }
                
                oprt.push(s[i] == '+' ? 1 : -1);
                oprd.push(0);
                i++;
            }
            if (i < s.size() && s[i] == ')') {
                while (oprt.top() != 0) {
                    int t = oprd.top();
                    oprd.pop();
                    oprd.top() += t * oprt.top();
                    oprt.pop();
                }
                oprt.pop();
                i++;
            }
        }
        while (!oprt.empty()) {
            int t = oprd.top();
            oprd.pop();
            oprd.top() += t * oprt.top();
            oprt.pop();
        }
        return oprd.top();
    }

    //Method 2: recursion, everytime encounter a ( recursion, everytime encounter a ), return
    int pos;
    int helper(string &s) {
        int i = pos;
        int op1 = 0, op2 = 0, op = 1;
        while (i < s.size()) {
            while (i < s.size() && s[i] == ' ') ++i;
            while (i < s.size() && s[i] <= '9' && s[i] >= '0') {
                op2 = op2 * 10 + s[i] - '0';
                i++;
            }
            if (i < s.size() && s[i] == '(') {
                pos = i + 1;
                op2 = helper(s);
                i = pos;
            }
            if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
                op1 += op2 * op;
                op2 = 0;
                op = (s[i] == '+') ? 1 : -1;
                i++;
            }
            if (i == s.size() || s[i] == ')') {
                pos = i + 1;
                break;
            }
        }
        return op1 + op2 * op;
    }
public:
    int calculate(string s) {
        if (s.empty()) return 0;
        return helper(s);
    }
};