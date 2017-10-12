//#42. Trapping Rain Water
//Hard
//Method: two methods
//Complexity: Time O(N) O(N) O; Space O(1) O(N)

//Method 1: Find from both end, until they meet at the peak, add water in each bin
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int max_l = 0, max_r = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= max_l) 
                    max_l = height[left];
                else
                    res += max_l - height[left];
                left++;
            } else {
                if (height[right] >= max_r)
                    max_r = height[right];
                else
                    res += max_r - height[right];
                right--;
            }
        }
        return res;
    }
    //Method 2: Using a stack to calculate the area of the rectangular
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty() || height[st.top()] > height[i])
                st.push(i);
            else {
                while (!st.empty() && height[st.top()] < height[i]) {
                    int tmp = st.top();
                    st.pop();
                    if (!st.empty())
                        res += (min(height[st.top()], height[i]) - height[tmp]) * (i - st.top() - 1);
                }
                st.push(i);
            }
        }
        return res;
    }
};
