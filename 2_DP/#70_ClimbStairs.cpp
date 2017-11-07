//#70
//Easy
//https://leetcode.com/problems/climbing-stairs/?tab=Description
//Arthor: lhy-loveworld
//Method: y(n) = y(n-1) + y(n-2), build an array to store the result for looking up
//        caution that if we call itself more than once in a recursive function, the result will not be cached, the time cost will be exponential
//Complexity: Time: best case O(1), worst case O(n) Space O(n)

class Solution {
    vector<int> result = vector<int> (2,1);
public:
    int climbStairs(int n) {
        if (n > result.size()-1)
            for (int i = result.size() - 1; i < n + 1; i++)
            {
                result.push_back(result[i]+result[i-1]);
            }
        return result[n];
    }
};