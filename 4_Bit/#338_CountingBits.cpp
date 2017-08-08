//#338
//Medium
//Arthor: lhy-loveworld
//Method: Two methods
//Complexity: Time O(N); Space O(N)

class Solution {
public:
	//First method, first get the bit count of the number dropping the last bit
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }

    vector<int> countBits(int num) {
        vector<int> res({0});
        for (int i = 1; i < num + 1; ++i) {
            if (i % 2)
                res.push_back(res[i / 2] + 1);
            else
                res.push_back(res[i / 2]);
        }
        return res;
    }
};
