//#303_RangeSumQuery
//Easy
//Method: Many calls to sumRange function, can trade in space for time.
//        Simplest way is to brute force, time complexity O(N) for each query; space comlexity is O(1) for each query
//        Or we can use hash map to store the sum for each pair, overhead constructor complexity for both time and space are O(N^2), O(1) for each query
//        Best way is to store sum from 0 to i, overhead complexity for both time and space are O(N), every query is O(1)
//Time complexity: O(N+#query)
//Space complexity: O(N)

class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int> nums) {
        if (nums.empty()) return;
        sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            sum.push_back(sum[i-1] + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return sum[j];
        else return sum[j]-sum[i-1];
    }
};
