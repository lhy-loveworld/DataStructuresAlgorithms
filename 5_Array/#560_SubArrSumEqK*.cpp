//#560. Subarray Sum Equals K
//Medium
//Method: Any subarray can be the difference between two subarray whose start is nums[0], use a hash map to track the previous head subarrays.
//          cautious for the current sum is k
//Complexity: time O(N). space O(N)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> Map;
        int Sum = 0;
        Map[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            Sum += nums[i];
            auto it = Map.find(Sum - k);
            if (it != Map.end()) res += it->second;
            Map[Sum]++;
        }
        return res;
    }
};