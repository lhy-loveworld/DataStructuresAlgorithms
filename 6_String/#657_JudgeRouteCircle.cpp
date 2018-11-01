//#657. Judge Route Circle
//Medium
//Method:
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    bool judgeCircle(string moves) {
        int hor = 0, ver = 0;
        for (char c: moves) {
            switch (c) {
                case 'R':
                    hor++;
                    break;
                case 'L':
                    hor--;
                    break;
                case 'U':
                    ver++;
                    break;
                case 'D':
                    ver--;
                    break;
            }
        }
        return hor == 0 && ver == 0;
    }
};