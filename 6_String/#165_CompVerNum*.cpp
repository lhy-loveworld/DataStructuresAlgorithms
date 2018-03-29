//#165. Compare Version Numbers
//Medium
//Method: cautious for the case 1 and 1.0
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t p1 = 0, p2 = 0;
        int v1, v2;
        while (p1 < version1.size() || p2 < version2.size()) {
            size_t l1, l2;
            v1 = p1 < version1.size() ? stoi(version1.substr(p1), &l1) : 0;
            v2 = p2 < version2.size() ? stoi(version2.substr(p2), &l2) : 0;
            if (v1 > v2) return 1;
            if (v1 < v2) return -1;
            p1 += l1 + 1;
            p2 += l2 + 1;
        }
        return 0;
    }
};