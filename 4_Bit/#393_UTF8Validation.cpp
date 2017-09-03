//#393
//Medium
//Arthor: lhy-loveworld
//Method: Use bit mask to scan through the vector.
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int len = 0;
        for (int i = 0; i < data.size(); ++i) {
            if (len == 0) {
                if ((data[i] & 0x80) == 0)
                    len = 0;
                else if ((data[i] & 0xE0) == 0xC0)
                    len = 1;
                else if ((data[i] & 0xF0) == 0xE0)
                    len = 2;
                else if ((data[i] & 0xF8) == 0xF0)
                    len = 3;
                else
                    return false;
            } else {
                if ((data[i] & 0xC0) == 0x80)
                    --len;
                else
                    return false;
            }
        }
        return (len == 0);
    }
};