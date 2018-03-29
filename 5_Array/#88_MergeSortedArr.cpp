//#88. Merge Sorted Array
//Easy
//Method: two pointers, form the array backwards
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (n > 0) {
            nums1[m + n - 1] = (m > 0 && nums1[m - 1] > nums2[n - 1]) ? nums1[--m] : nums2[--n];
        }
    }
};