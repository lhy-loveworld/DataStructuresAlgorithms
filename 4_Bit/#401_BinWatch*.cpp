//#401
//Easy
//Arthor: lhy-loveworld
//Method: Try to think in the opposite way. Instead of trying to form the number with specified amount of 1s, you can test each number to see if it has that amount of 1s.
//Complexity: Time O(1); Space O(1)

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                int tm = (h << 6) | m;
                if (bitset<10>(tm).count() == num)
                    res.push_back(to_string(h) + (m < 10? ":0":":") + to_string(m));
            }
        }
        return res;
    }
};