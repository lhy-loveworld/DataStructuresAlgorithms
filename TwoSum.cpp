//#1
//Two ways to solve this problem: Brute force & Hash
//Hash
//Space: O(N)
//Time: O(N)
//Use of unordered_map as hash table

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
