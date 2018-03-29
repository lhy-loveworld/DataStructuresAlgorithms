//#217. Contains Duplicate
//Easy
//Method: 
//Complexity: time O(nlogn) O(n); space O(1) O(n)

class Solution {
public:
    //Method 1: first sort
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i]) return true;
        }
        return false;
    }

    //Method 2: hash set
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i: nums) {
            if (s.count(i)) return true;
            s.insert(i);
        }
        return false;
    }
};