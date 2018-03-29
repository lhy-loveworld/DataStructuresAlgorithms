//#278. First Bad Version
//Easy
//Method: binary search
//Complexity: Time O(logN); Space O(1)

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long l = 1, r = n;//caution for the overflow case
        while (l != r) {
            if (isBadVersion((l + r) / 2))
                r = (l + r) / 2;
            else
                l = (l + r) / 2 + 1;
        }
        return l;
    }
};