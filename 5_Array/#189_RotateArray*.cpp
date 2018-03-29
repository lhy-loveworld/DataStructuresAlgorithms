//#189. Rotate Array
//Easy
//Method: multiple methods
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    //Method 1: track the most front modified element, one run
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) return;
        int changed = nums.size();
        for (int i = 0; i < changed; ++i) {
            int next = i + k;
            while (next != i) {
                swap(nums[next], nums[i]);
                if (next < changed)
                    changed = next;
                next = (next + k) % nums.size();
            }
        }
    }

    //Method 2: calculate the largest common factor, this is the iteration
    int FindLCF(int a, int b) {
        while (a != 0) {
            b = b - a;
            if (b < a)
                swap(a, b);
        }
        return b;
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) return;
        int iters = FindLCF(k, nums.size());
        for (int i = 0; i < iters; ++i) {
            int next = i + k;
            while (next != i) {
                swap(nums[next], nums[i]);
                next = (next + k) % nums.size();
            }
        }
    }

    //Method 3: two runs
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n | k == 0) return;
        k %= n;
        reverse(nums.begin(), nums.begin() + n - k) ;
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};