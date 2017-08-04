//#155 Min Stack
//Easy
//https://leetcode.com/problems/min-stack/description
//Arthor: lhy-loveworld
//Method: Need to store the min of the stack at anytime, use another stack.
//Complexity: Time O(N); Space O(N)

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};