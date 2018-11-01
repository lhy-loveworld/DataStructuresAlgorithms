//#739. Daily Temperatures
//Medium
//Method: skyscraper problems
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> waitStack;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!waitStack.empty() && temperatures[waitStack.top()] < temperatures[i]) {
                temperatures[waitStack.top()] = i - waitStack.top();
                waitStack.pop();
            }
            waitStack.push(i);
        }
        while (!waitStack.empty()) {
            temperatures[waitStack.top()] = 0;
            waitStack.pop();
        }
        return temperatures;
    }
};