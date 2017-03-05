//#15 3Sum
//Medium
//https://leetcode.com/problems/3sum/?tab=Description
//Arthor: lhy-loveworld
//Method: Convert it into a loop of 2 Sum. First sort it and then use two-pointer method
//Complexity: Time O(NlogN+N^2) = O(N^2); Space O(N)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > r;
        if (nums.size()<3) return r;
        sort(nums.begin(),nums.end());
        
        for (int i = 0; (nums[i] <= 0)&&(i < nums.size() - 2); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j!=k) {
                if (nums[i] + nums[j] + nums[k] < 0) j++;
                else if (nums[i] + nums[j] + nums[k] > 0) k--;
                    else {
                        vector<int> r1(3,0);
                        r1[0]=nums[i];
                        r1[1]=nums[j];
                        r1[2]=nums[k];
                        r.push_back(r1);
                        j++;
                        while ((nums[j]==nums[j-1])&&(j!=k)) j++;
                        if (j!=k) k--;
                        while ((nums[k]==nums[k+1])&&(j!=k)) k--;
                    }
            }
            while ((nums[i]==nums[1+i])&&(i < nums.size() - 2)) i++;
        }
        return r;
    }
};
