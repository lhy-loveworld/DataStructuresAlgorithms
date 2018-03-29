//#716. Max Stack
//Hard
//Method: two methods
//Complexity: Space O(N)

//Method 1: using 3 stacks, 1 is the ordinary one, 2 is used to store all the current max in sequence, 3 is used to temporarily store the elements in 1 when popping the max
class MaxStack {
    stack<int> st1, st2, st3;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {   //O(1)
        st1.push(x);
        if (st2.empty() || st2.top() <= x) st2.push(x);
    }
    
    int pop() {      //O(1)
        int t = st1.top();
        if (st2.top() == t) st2.pop();
        st1.pop();
        return t;
    }
    
    int top() {             //O(1)
        return st1.top();
    }
    
    int peekMax() {         //O(1)
        return st2.top();
    }
    
    int popMax() {          //O(N)
        int t = st2.top();
        while (st1.top() != t) {// temorarily store them in stack 3
            st3.push(st1.top());
            st1.pop();
        }
        st1.pop();
        st2.pop();
        while (!st3.empty()) { //repush to st1 and st2, cautious to push to both st1 and st2
            push(st3.top());
            st3.pop();
        }
        return t;
    }
};

//Method 2: using a map with a linked list, map maps the integer to a forward_list of its appearence in the current list.
class MaxStack {
    list<int> ls;
    map<int, forward_list<list<int>::iterator> > mp;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {          //O(logN)
        ls.push_front(x);
        auto it = mp.find(x);
        if (it != mp.end()) {
            it->second.push_front(ls.begin());
        } else mp[x] = forward_list<list<int>::iterator> (1, ls.begin());
    }
    
    int pop() {             //O(logN)
        int t = ls.front();
        ls.pop_front();
        auto it = mp.find(t);
        (it->second).pop_front();
        if ((it->second).empty()) mp.erase(it);
        return t;
    }
    
    int top() {                 //O(1)
        return ls.front();
    }
    
    int peekMax() {             //O(1)
        return mp.rbegin()->first;
    }
    
    int popMax() {              //O(logN)
        int t = mp.rbegin()->first;
        ls.erase(mp.rbegin()->second.front());
        mp.rbegin()->second.pop_front();
        if (mp.rbegin()->second.empty()) mp.erase(--mp.end());
        return t;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
