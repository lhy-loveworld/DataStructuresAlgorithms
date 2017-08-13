//#78
//Medium
//Arthor: lhy-loveworld
//Method: Three methods.
//Complexity: Time O(N*2^N); Space O(1)

class Solution {
public:
    //Bit map
    vector<vector<int>> subsets(vector<int>& nums) {
    	unsigned long long S = 1 << nums.size();
    	vector<vector<int>> res(S, vector<int>());
    	for (unsigned long long mask = 0; mask < S; ++mask) {
    		for (int i = 0; i < nums.size(); ++i) {
    			if (mask & (1 << i))
    				res[i].push_back(nums[i]);
    		}
    	}
    	return res;
    }

    //iteration
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> res(1, vector<int>());
    	for (int i = 0; i < nums.size(); ++i) {
    		int S = res.size();
    		for (int j = 0; j < S; ++j) {
    			res.push_back(res[j]);
    			res.back().push_back(nums[i]);
    		}
    	}
    	return res;
    }

    //recursion, backtrack
    void subgen(vector<vector<int>>& res, vector<int>& tmp, int next, vector<int>& nums) {
    	res.push_back(tmp);
    	for (int i = next; i < nums.size(); ++i) {
    		tmp.push_back(nums[i]);
    		subgen(res, tmp, i + 1, nums);
    		tmp.pop_back();
    	}
    }

    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> res;
    	vector<int> tmp;
    	subgen(res, tmp, 0, nums);
    	return res;
    }
};
