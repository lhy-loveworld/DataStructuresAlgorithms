//#338
//Medium
//Arthor: lhy-loveworld
//Method: Two methods, dp
//Complexity: Time O(N); Space O(N)

class Solution {
public:
	//Method 1: dp
    //first get the bit count of the number dropping the last bit
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }

    //Method 2: also dp
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
