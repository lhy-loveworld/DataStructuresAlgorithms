//#496. Next Greater Element I
//Easy
//Method: use a stack to store the elements in descending order
//Complexity: time O(N) for both. space O(N)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> descStack;
      unordered_map<int, int> nxtGreater;
      for (const int& i: nums) {
        while (!descStack.empty() && descStack.top() < i) {
          nxtGreater[descStack.top()] = i;
          descStack.pop();
        }
        descStack.push(i);
        nxtGreater[i] = -1;
      }
      vector<int> res;
      for (const int& i: findNums) res.push_back(nxtGreater[i]);
      return res;
    }
};