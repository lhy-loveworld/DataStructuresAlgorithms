//#28. Implement strStr()
//Easy
//Method: two pointers
//Complexity: Time O(MN); Space O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int h = haystack.size(), n = needle.size();
        for (int i = 0; i < h - n + 1; ++i) {
            if (haystack[i] == needle[0]) {
                int j = 1;
                for (; j < n; ++j) {
                    if (needle[j] != haystack[i + j])
                        break;
                }
                if (j == n)
                    return i;
            }
        }
        return -1;
    }
};