//#89. Gray Code
//Medium
//Method: 
//Complexity: Time O(2^N); Space O(1)

class Solution {
public:
    //Method 1: directly insert one by one
    vector<int> grayCode(int n) {
        int s = pow(2, n);
        vector<int> res(s);
        for (int i = 0; i < s; ++i) {
            res[i] = i ^ i >> 1;
        }
        return res;
    }

    //Time complexity: O(2^N) Space complexity: O(2^N)
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int> (1,0);
        vector<int> an = {0,1};
        for (int i = 1; i < n; i++) {
            int msb = 1 << i;
            vector<int> ran(an.rbegin(), an.rend());
            for (auto& a: ran) {
                a = a | msb;
            }
            an.insert(an.end(), ran.begin(), ran.end());
        }
        return an;
    }
};