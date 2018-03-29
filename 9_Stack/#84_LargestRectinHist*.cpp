//#84. Largest Rectangle in Histogram
//Hard
//Method: keep a rising stack, if new element is higher than top, push, otherwise pop and calculate the area of the top.
//          finding the left most and right most element higher than the current one
//Complexity: Time O(N) Space O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        stack<int> st;
        heights.push_back(0);
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int idx = st.top();
                st.pop();
                int start = st.empty() ? 0 : st.top() + 1; //start point is the one prior than the top
                int sqr = (i - start) * heights[idx];       //end point is the one waiting to be pushed
                res = max(res, sqr);
            }
            st.push(i);
        }
        return res;
    }
};
