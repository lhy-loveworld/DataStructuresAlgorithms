//#215. Kth Largest Element in an Array
//Medium
//Method: two methods
//Complexity: Time O(Nlogk); Space O(1) or O(k)

class Solution {
public:
	//Method 1:
	//Using partition in quicksort, everytime find a pivot
    int Part(vector<int>& nums, int l, int r, int p) {
        int t = nums[p];
        swap(nums[l], nums[p]);
        while (l < r) {
            while (l < r && nums[r] <= t) r--;
            nums[l] = nums[r];
            while (l < r && nums[l] >= t) l++;
            nums[r] = nums[l];
        }
        nums[l] = t;
        return l;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (1) {
            int pivot = rand() % (r - l + 1) + l;// random choosing a pivot to improve performance under sorted scenario
            pivot = Part(nums, l, r, pivot);
            if (pivot == k - 1) return nums[pivot];
            if (pivot < k - 1) l = pivot + 1;
            else r = pivot - 1;
        }
    }

    //Method 2:
    //Using a max heap of size k
    bool operator() (int a, int b) {
        return a > b;
    }
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, deque<int>, Solution> pq;
        for (int i: nums) {
            if (pq.size() < k || pq.top() < i) {
                if (pq.size() >= k) {
                    pq.pop();
                }
                pq.push(i);
            }
        }
        return pq.top();
    }
};