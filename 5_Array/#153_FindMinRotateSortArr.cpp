//#153. Find Minimum in Rotated Sorted Array
//Medium
//Method: recursion and iteration
//Complexity: Time O(logN) O(log(M+N)); Space O(1)

class Solution {
public:
	//Method 1: iteration
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (nums[l] > nums[r]) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[l]) r = mid;
            else l =  mid + 1;
        }
        return nums[l];
    }

    //Method 2: recursion
    int subfind(vector<int>& nums, int l, int r) {
        if (nums[l] <= nums[r]) return nums[l];
        int mid = (l + r) / 2;
        if (nums[mid] < nums[l]) return subfind(nums, l, mid);
        else return subfind(nums, mid + 1, r);
    }
    int findMin(vector<int>& nums) {
        return subfind(nums, 0, nums.size() - 1);
    }
};