//#476
//Easy
//Arthor: lhy-loveworld
//Method: Remember how to construct of a number of all 1s, and how to find the length of a number's binary form.
//Complexity: Time O(1); Space O(1)

class Solution {
public:
	//Fastest way
    int findComplement(int num) {
        int mask = num | (num >> 1);
        mask |= (mask >> 2);
        mask |= (mask >> 4);
        mask |= (mask >> 8);
        mask |= (mask >> 16);
        return mask ^ num;
    }

    //Another way
    int findComplement(int num) {
        unsigned mask = ~0; //note that INT_MAX = ~0
        while (num & mask) mask <<= 1; //note how to build a mask with all 1s
        return ~mask & ~num;
    }
};