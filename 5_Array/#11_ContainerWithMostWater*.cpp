//#11. Container With Most Water
//Medium
//Method: two pointers
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, left = 0, right = height.size() - 1;
        while (left != right) {
            if (height[left] < height[right]) {
                res = max((right - left) * height[left], res);
                left++;
            } else {
                res = max((right - left) * height[right], res);
                right--;
            }
        }
        return res;
    }
};

//Use two pointers from both end
//The one keeps must be the largest among all the visited numbers
//And we are finding the farthest one that is larger than the current one (the one will be discarded)