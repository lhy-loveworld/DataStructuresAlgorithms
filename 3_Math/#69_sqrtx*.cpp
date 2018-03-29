//#69 Sqrt(x)
//Easy
//Method: binary search
//Complexity: time O(logn); space O(1)

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int h = x, l = 0;
        long m;

        while (h - l > -1) {
            m = (h + l) / 2;
            if (m * m == x)
                return m;
            if (m * m < x)
                l = m + 1;
            else
                h = m - 1;
        }
        return h;

        /*Or we can do
        while (h - l > 1) {
            m = (h + l) / 2;
            if (m * m == x)
                return m;
            if (m * m < x)
                l = m;
            else
                h = m;
        }
        return l;
        */
    }
};