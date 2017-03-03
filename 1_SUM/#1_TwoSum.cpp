//#1
//Easy
//https://leetcode.com/problems/two-sum/?tab=Description
//Arthor: lhy-loveworld
//Method: Two ways to solve this problem: Brute force & HashUse of unordered_map as hash table
//        Hash
//Complexity: Space: O(N); Time: O(N);


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ind;
        unordered_map <int,int> lookupT;
        unordered_map <int,int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            it = lookupT.find(target - nums[i]);
            if (it != lookupT.end()) {
                ind.push_back(it->second);
                ind.push_back(i);
                return ind;
            }
            lookupT[nums[i]] = i;
        }
    }
};
